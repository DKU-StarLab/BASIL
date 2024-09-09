#ifndef LIST_SPGM_H
#define LIST_SPGM_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "indexes/sPGM-index/include/pgm/pgm_index_sampling.hpp"
#include "util.h"
#include "wrappers/base.h"

//#include <functional>
//#include <boost/iterator/transform_iterator.hpp>
//#include <boost/range/adaptors.hpp>

template <class KeyType, size_t delta, size_t interval, size_t recursive_delta,
          size_t recursive_interval>
class sPGM : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
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

  std::string name() const { return "sPGM"; }

  std::size_t size() const { return spgm_.size_in_bytes(); }

  bool applicable(bool unique, const std::string& data_filename) const {
    return true;
  }

  std::string variant() const {
    return std::to_string(delta) + "/" + std::to_string(interval) + "/" +
           std::to_string(recursive_delta) + "/" +
           std::to_string(recursive_interval);
  }

 private:
  spgm::sPGMIndex<KeyType, KeyValue<KeyType>, delta, interval, recursive_delta,
                  recursive_interval>
      spgm_;
};

#endif  // LIST_SPGM_H
