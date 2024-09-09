#pragma once

#include <cassert>
#include <cmath>
#include <limits>
#include <stack>

#include "common.h"
#include "scht.h"

namespace scht {

// Allows building a `CompactHistTree` in a single pass over sorted data.
template <class KeyType, class KeyValType>
class sCHTBuilder {
 public:
  // The cache-oblivious structure makes sense when the tree becomes deep
  // (`numBins` or `maxError` become small)
  sCHTBuilder(KeyType min_key, KeyType max_key, size_t num_bins,
              size_t max_error, size_t interval,
              std::vector<KeyValType>& kv_vec, bool use_cache = false)
      : min_key_(min_key),
        max_key_(max_key),
        num_bins_(num_bins),
        log_num_bins_(computeLog(static_cast<uint64_t>(num_bins_))),
        max_error_(max_error),
        interval_(interval),
        use_cache_(use_cache),
        curr_num_keys_(kv_vec.size()),
        kv_vec_(kv_vec) {
    assert((num_bins_ & (num_bins_ - 1)) == 0);
    // Compute the logarithm in base 2 of the range.
    auto lg = computeLog(max_key_ - min_key_, true);

    // And also the initial shift for the first node of the tree.
    assert(lg >= log_num_bins_);
    shift_ = lg - log_num_bins_;
  }

  sCompactHistTree<KeyType, KeyValType> BulkLoad() {
    // Last key needs to be equal to `max_key_`.
    BuildOfflineNotCopy();

    return Finalize();
  }

  // Finalizes the construction and returns a read-only `RadixSpline`.
  sCompactHistTree<KeyType, KeyValType> Finalize() {
    if (!use_cache_) {
      Flatten();
    } else {
      CacheObliviousFlatten();
    }

    return sCompactHistTree<KeyType, KeyValType>(
        min_key_, max_key_, curr_num_keys_, num_bins_, log_num_bins_,
        max_error_, interval_, shift_, std::move(table_));
  }

 protected:
  static constexpr unsigned Infinity = std::numeric_limits<unsigned>::max();
  static constexpr unsigned Leaf = (1u << 31);
  static constexpr unsigned Mask = Leaf - 1;

  // Range covered by a node, i.e. [l, r[
  struct Range {
    unsigned start;
    unsigned end;
  };

  struct Node {
    unsigned level;
    KeyType key_lo;
    std::vector<Range> bins;
  };

  static unsigned computeLog(uint32_t n, bool round = false) {
    assert(n);
    return 31 - __builtin_clz(n) + (round ? ((n & (n - 1)) != 0) : 0);
  }

  static unsigned computeLog(uint64_t n, bool round = false) {
    assert(n);
    return 63 - __builtin_clzl(n) + (round ? ((n & (n - 1)) != 0) : 0);
  }

  void BuildOfflineNotCopy() {
    // Init the node, which covers the range `curr` := [a, b[.
    auto initNode = [&](unsigned nodeIndex, Range curr) -> void {
      // Compute `width` of the current node (2^`width` represents the range
      // covered by a single bin).
      std::optional<unsigned> currBin = std::nullopt;
      unsigned width = shift_ - tree_[nodeIndex].level * log_num_bins_;

      // (sampling) Train sample keys that are not last.
      auto index = curr.start;
      for (; index < curr.end - interval_; index += interval_) {
        // Extract the bin of the current key.
        auto bin =
            (kv_vec_[index].key - min_key_ - tree_[nodeIndex].key_lo) >> width;

        // Is the first bin or a new one?
        if ((!currBin.has_value()) || (bin != currBin.value())) {
          // Iterate the bins which have not been touched and set for them an
          // empty range.
          for (unsigned iter = currBin.has_value() ? (currBin.value() + 1) : 0;
               iter != bin; ++iter) {
            tree_[nodeIndex].bins[iter] = {index, index};
          }

          // Init the current bin.
          tree_[nodeIndex].bins[bin] = {index, index};
          currBin = bin;
        }
        tree_[nodeIndex].bins[bin].end += interval_;
      }

      // (sampling) Train last key
      auto bin =
          (kv_vec_[index].key - min_key_ - tree_[nodeIndex].key_lo) >> width;

      // Is the first bin or a new one?
      if ((!currBin.has_value()) || (bin != currBin.value())) {
        // Iterate the bins which have not been touched and set for them an
        // empty range.
        for (unsigned iter = currBin.has_value() ? (currBin.value() + 1) : 0;
             iter != bin; ++iter) {
          tree_[nodeIndex].bins[iter] = {index, index};
        }

        // Init the current bin.
        tree_[nodeIndex].bins[bin] = {index, curr.end};
        currBin = bin;
      } else {
        tree_[nodeIndex].bins[bin].end = curr.end;
      }
    };

    // Init the first node.
    tree_.push_back(
        {0, 0,
         std::vector<Range>({num_bins_, {curr_num_keys_, curr_num_keys_}})});
    initNode(0, {0, curr_num_keys_});

    // Run the BFS
    std::queue<unsigned> nodes;
    nodes.push(0);
    while (!nodes.empty()) {
      // Extract from the queue.
      auto node = nodes.front();
      nodes.pop();

      // Consider each bin and decide whether we should split it.
      unsigned level = tree_[node].level;
      KeyType lower = tree_[node].key_lo;
      for (unsigned bin = 0; bin != num_bins_; ++bin) {
        // Should we split further?
        if (tree_[node].bins[bin].end - tree_[node].bins[bin].start >
            max_error_) {
          // Corner-case: is #keys > range? Then create a leaf (this can only
          // happen for datasets with duplicates).
          auto size = tree_[node].bins[bin].end - tree_[node].bins[bin].start;

          if (size > (1ull << (shift_ - level * log_num_bins_))) {
            tree_[node].bins[bin].start |= Leaf;
            continue;
          }

          // Alloc the next node.
          std::vector<Range> newNode;
          newNode.assign(num_bins_, {tree_[node].bins[bin].end,
                                     tree_[node].bins[bin].end});

          // And add it to the tree.
          KeyType newLower =
              lower + bin * (1ull << (shift_ - level * log_num_bins_));
          tree_.push_back({level + 1, newLower, newNode});

          // Init it
          initNode(tree_.size() - 1, tree_[node].bins[bin]);

          // Reset this node (no leaf, pointer to child).
          // narrow conversion
          tree_[node].bins[bin] = {0,
                                   static_cast<unsigned int>(tree_.size() - 1)};

          // And push it into the queue.
          nodes.push(tree_.size() - 1);
        } else {
          // Leaf
          tree_[node].bins[bin].start |= Leaf;
        }
      }
    }
  }

  // Flatten the layout of the tree.
  void Flatten() {
    table_.resize(static_cast<size_t>(tree_.size()) * num_bins_);
    for (size_t index = 0, limit = tree_.size(); index != limit; ++index) {
      for (unsigned bin = 0; bin != num_bins_; ++bin) {
        // Leaf node?
        if (tree_[index].bins[bin].start & Leaf) {
          // Set the partial sum.
          table_[(index << log_num_bins_) + bin] = tree_[index].bins[bin].start;
        } else {
          // Set the pointer.
          table_[(index << log_num_bins_) + bin] = tree_[index].bins[bin].end;
        }
      }
    }
  }

  // Flatten the layout of the tree, such that the final layout is
  // cache-oblivious.
  void CacheObliviousFlatten() {
    // Build the precendence graph between nodes.
    assert(!tree_.empty());
    auto maxLevel = tree_.back().level;
    std::vector<std::vector<unsigned>> graph(tree_.size());
    for (unsigned index = 0, limit = tree_.size(); index != limit; ++index) {
      graph[index].reserve(num_bins_);
      for (unsigned bin = 0; bin != num_bins_; ++bin) {
        // No leaf?
        if ((tree_[index].bins[bin].start & Leaf) == 0) {
          graph[index].push_back(tree_[index].bins[bin].end);
        }
      }
    }

    // And now set the count of nodes in subtree and the first node in the
    // subtree (bottom-up).
    auto access = [&](unsigned vertex) -> size_t {
      return static_cast<size_t>(vertex) * (maxLevel + 1);
    };

    std::vector<std::pair<unsigned, unsigned>> helper(
        static_cast<size_t>(tree_.size()) * (maxLevel + 1), {Infinity, 0});
    for (unsigned index = 0, limit = tree_.size(); index != limit; ++index) {
      auto vertex = limit - index - 1;
      const auto currLvl = tree_[vertex].level;

      // Add the vertex itself.
      helper[access(vertex) + currLvl] = {vertex, 1};

      // And all subtrees, if any
      for (auto v : graph[vertex]) {
        for (unsigned lvl = currLvl; lvl <= maxLevel; ++lvl) {
          helper[access(vertex) + lvl].first =
              std::min(helper[access(vertex) + lvl].first,
                       helper[access(v) + lvl].first);
          helper[access(vertex) + lvl].second += helper[access(v) + lvl].second;
        }
      }
    }

    // Build the `order`, the cache-oblivious permutation.
    unsigned tempSize = 0;
    std::vector<unsigned> order(tree_.size());

    // Fill levels in [`lh`, `uh`[.
    std::function<void(unsigned, unsigned, unsigned)> fill =
        [&](unsigned rowIndex, unsigned lh, unsigned uh) {
          // Stop?
          if (uh - lh == 1) {
            order[rowIndex] = tempSize++;
            return;
          }

          // Leaf?
          if (graph[rowIndex].empty()) {
            order[rowIndex] = tempSize++;
            return;
          }

          // Find the split level.
          assert(helper[access(rowIndex) + lh].second);
          auto splitLevel = uh;
          while ((splitLevel >= lh + 1) &&
                 (!helper[access(rowIndex) + splitLevel - 1].second))
            --splitLevel;
          if (splitLevel == lh) {
            order[rowIndex] = tempSize++;
            return;
          }
          splitLevel = lh + (splitLevel - lh) / 2;

          // Recursion
          fill(rowIndex, lh, splitLevel);
          auto begin = helper[access(rowIndex) + splitLevel].first,
               end = begin + helper[access(rowIndex) + splitLevel].second;
          for (unsigned ptr = begin; ptr != end; ++ptr) {
            fill(ptr, splitLevel, uh);
          }
        };

    // Start filling `order`, which is a permutation of the nodes, s.t. the tree
    // becomes cache-oblivious.
    fill(0, 0, maxLevel + 1);

    // Flatten with `order`.
    table_.resize(static_cast<size_t>(tree_.size()) * num_bins_);
    for (unsigned index = 0, limit = tree_.size(); index != limit; ++index) {
      for (unsigned bin = 0; bin != num_bins_; ++bin) {
        // Leaf node?
        if (tree_[index].bins[bin].start & Leaf) {
          // Set the partial sum.
          table_[(static_cast<size_t>(order[index]) << log_num_bins_) + bin] =
              tree_[index].bins[bin].start;
        } else {
          // Set the pointer.
          table_[(static_cast<size_t>(order[index]) << log_num_bins_) + bin] =
              order[tree_[index].bins[bin].end];
        }
      }
    }

    // And clean.
    helper.clear();
    order.clear();
  }

  const KeyType min_key_;
  const KeyType max_key_;
  const size_t num_bins_;
  const size_t log_num_bins_;
  const size_t max_error_;
  const size_t interval_;
  const bool use_cache_;

  unsigned curr_num_keys_;
  size_t shift_;

  const std::vector<KeyValType>& kv_vec_;
  std::vector<unsigned> table_;
  std::vector<Node> tree_;
};

}  // namespace scht