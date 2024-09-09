#ifndef LIST_MSPGM_H
#define LIST_MSPGM_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "indexes/sPGM-index/include/pgm/pgm_index_sampling_meta.hpp"
#include "util.h"
#include "wrappers/base.h"

template <class KeyType, int delta, int interval, int recursive_delta,
          int recursive_interval>
class msPGM : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    data_ = &data;
    lookups_ = &lookups;

    uint64_t build_time = util::timing(
        [&] { spgm_ = decltype(spgm_)(data.begin(), data.end()); });

    return build_time;
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    auto approx_range = spgm_.search(lookup_key);
    auto lo = approx_range.lo;
    auto hi = approx_range.hi;

    return (SearchBound){lo, hi};
  }

  std::string name() const { return "msPGM"; }

  std::size_t size() const { return spgm_.size_in_bytes(); }

  bool applicable(bool unique, const std::string& data_filename) const {
    return true;
  }

  std::string variant() {
    return std::to_string(delta) + "/" + std::to_string(interval) + "/" +
           std::to_string(recursive_delta) + "/" +
           std::to_string(recursive_interval) + "/" +
           std::to_string(spgm_.height()) + "/" +
           spgm_.GetMeta(*data_, *lookups_);
  }

 private:
  spgm::msPGMIndex<KeyType, KeyValue<KeyType>, delta, interval, recursive_delta,
                   recursive_interval>
      spgm_;
  std::vector<KeyValue<KeyType>>* data_;
  std::vector<EqualLookup<KeyType>>* lookups_;
};

#endif  // LIST_MSPGM_H
