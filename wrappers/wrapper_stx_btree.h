#pragma once

#include <stx/btree_multimap.h>

#include "util.h"
#include "utils/tracking_allocator.h"
#include "wrappers/base.h"

template <class KeyType, int interval>
class STXBTree : public Competitor {
 public:
  STXBTree()
      : btree_(TrackingAllocator<std::pair<KeyType, uint64_t>>(
            total_allocation_size)) {}

  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    std::vector<std::pair<KeyType, uint64_t>> reformatted_data;
    reformatted_data.reserve(data.size());

    for (auto iter : data) {
      uint64_t idx = iter.value;
      reformatted_data.emplace_back(KeyType(iter.key), idx);
    }
    data_size_ = reformatted_data.size();

    return util::timing([&] {
      btree_.sampled_bulk_load(reformatted_data.begin(), reformatted_data.end(),
                               interval);
    });
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    // Search for first occurrence of key.
    auto it = btree_.lower_bound(lookup_key);

    uint64_t guess;
    if (it == btree_.end()) {
      guess = data_size_ - 1;
    } else {
      guess = it->second;
    }

    const uint64_t error = interval - 1;

    const uint64_t start = guess < error ? 0 : guess - error;
    const uint64_t stop = guess + 1 > data_size_
                              ? data_size_
                              : guess + 1;  // stop is exclusive (that's why +1)

    return (SearchBound){start, stop};
  }

  std::string name() const { return "BTree"; }

  std::size_t size() const {
    return btree_.get_allocator().total_allocation_size + sizeof(*this);
  }

  std::string variant() const { return std::to_string(interval); }

 private:
  // Using a multimap here since keys may contain duplicates.
  uint64_t total_allocation_size = 0;
  uint64_t data_size_ = 0;
  stx::btree_multimap<KeyType, uint64_t, std::less<KeyType>,
                      stx::btree_default_map_traits<KeyType, uint64_t>,
                      TrackingAllocator<std::pair<KeyType, uint64_t>>>
      btree_;
};
