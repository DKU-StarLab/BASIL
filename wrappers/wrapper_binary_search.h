#pragma once

#include "base.h"

template <class KeyType>
class BinarySearch : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    // Nothing else to do here as input data is already sorted.
    data_size = data.size();
    return 0;
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    return (SearchBound){0, data_size};
  }

  std::string name() const { return "BinarySearch"; }

  std::size_t size() const { return 0; }

  std::string variant() const { return std::to_string(0); }

 private:
  size_t data_size;
};
