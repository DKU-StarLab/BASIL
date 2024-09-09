#pragma once

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <queue>
#include <vector>

#include "common.h"
#include "scht.h"
namespace scht {

template <class KeyType, class KeyValType>
class msCompactHistTree : public sCompactHistTree<KeyType, KeyValType> {
 public:
  msCompactHistTree() = default;

  msCompactHistTree(KeyType min_key, KeyType max_key, size_t num_keys,
                    size_t num_bins, size_t log_num_bins, size_t max_error,
                    size_t interval, size_t shift, std::vector<unsigned> table)
      : sCompactHistTree<KeyType, KeyValType>(min_key, max_key, num_keys,
                                              num_bins, log_num_bins, max_error,
                                              interval, shift, table),
        height_cnt_(0),
        sum_sqr_error_(0),
        pos_branch_cnt(0),
        neg_branch_cnt(0),
        empty_bin_cnt_(0) {}

  std::string GetMeta(std::vector<KeyValType>& data,
                      std::vector<EqualLookup<KeyType>>& lookups) {
    MetaLookupTrace(data, lookups);

    auto avg_sqr_error_ = sum_sqr_error_ / lookups.size();
    auto avg_height_ = (height_cnt_ / lookups.size()) + 1;
    auto empty_bin_ratio = empty_bin_cnt_ / lookups.size();
    auto pos_branch_ratio = pos_branch_cnt / (pos_branch_cnt + neg_branch_cnt);

    std::string meta = std::to_string(avg_sqr_error_) + "/" +
                       std::to_string(avg_height_) + "/" +
                       std::to_string(empty_bin_ratio) + "/" +
                       std::to_string(pos_branch_ratio);
    return meta;
  }

 private:
  void MetaLookupTrace(std::vector<KeyValType>& data,
                       std::vector<EqualLookup<KeyType>>& lookups) {                  
    for (auto iter = lookups.begin(); iter != lookups.end(); iter++) {
      SearchBound sb = MetaGetSearchBound((*iter).key);

      auto result = std::lower_bound(
          data.begin() + sb.begin, data.begin() + sb.end, (*iter).key,
          [](const KeyValType& lhs, const KeyType lookup_key) {
            return lhs.key < lookup_key;
          });

      auto count =
          std::distance(data.begin() + sb.begin, data.begin() + sb.end);
      auto first = data.begin() + sb.begin;
      int loop_cnt = 0;

      while (count > 0) {
        auto it = first;
        auto step = count / 2;
        std::advance(it, step);

        if (loop_cnt == 0) {
          auto error = std::distance(result, it);
          sum_sqr_error_ += std::abs(error) * std::abs(error);
        }

        if ((*it).key < (*iter).key) {
          first = ++it;
          count -= step + 1;
          neg_branch_cnt++;
        } else {
          count = step;
          pos_branch_cnt++;
        }
        loop_cnt++;
      }
    }
  }

  SearchBound MetaGetSearchBound(const KeyType key) {
    size_t pred = MetaLookup(key);
    const size_t begin =
        (pred < this->interval_ - 1) ? 0 : (pred - this->interval_ + 1);
    // `end` is exclusive.
    const size_t end = (pred + this->max_error_ + 1 > this->num_keys_)
                           ? this->num_keys_
                           : (pred + this->max_error_ + 1);

    return SearchBound{begin, end};
  }

  // Count height and empty bins used for lookup
  size_t MetaLookup(KeyType key) {
    // Edge cases
    if (key <= this->min_key_) return 0;
    if (key >= this->max_key_) return this->num_keys_ - 1;
    key -= this->min_key_;

    auto width = this->shift_;
    size_t next = 0;
    do {
      // Get the bin
      KeyType bin = key >> width;
      auto idx = (next << this->log_num_bins_) + bin;
      next = this->table_[idx];

      // Is it a leaf?
      if (next & this->Leaf) {
        // Count empty bin used for lookup
        if (this->table_[idx] == this->table_[idx + 1]) {
          empty_bin_cnt_++;
        }
        return next & this->Mask;
      }

      // Increment height
      height_cnt_++;

      // Prepare for the next level
      key -= bin << width;
      width -= this->log_num_bins_;
    } while (true);
  }

  double height_cnt_;
  double sum_sqr_error_;
  double pos_branch_cnt;
  double neg_branch_cnt;
  double empty_bin_cnt_;
};

}  // namespace scht
