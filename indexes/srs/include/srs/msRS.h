#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "common.h"
#include "sRS.h"

namespace srs {

// Approximates a cumulative distribution function (CDF) using spline
// interpolation.
template <class KeyType, class KeyValueType>
class msRS : public sRS<KeyType, KeyValueType> {
 public:
  msRS() = default;

  msRS(KeyType min_key, KeyType max_key, size_t original_num_keys,
       size_t num_radix_bits, size_t num_shift_bits, size_t sampling_interval,
       size_t train_max_error, std::vector<uint32_t> radix_table,
       std::vector<srs::Coord<KeyType>> spline_points)
      : sRS<KeyType, KeyValueType>(
            min_key, max_key, original_num_keys, num_radix_bits, num_shift_bits,
            sampling_interval, train_max_error, radix_table, spline_points),
        sum_sqr_error_(0) {}

  size_t GetSplineSize() const {
    return this->spline_points_.size() * sizeof(Coord<KeyType>);
  }

  size_t GetRadixTableSize() const {
    return this->radix_table_.size() * sizeof(uint32_t);
  }

  std::string GetMeta(std::vector<KeyValueType>& data,
                      std::vector<EqualLookup<KeyType>>& lookups) {
    CalculateError(data, lookups);
    double avg_sqr_error = sum_sqr_error_ / double(lookups.size());
    std::string meta = std::to_string(GetRadixTableSize()) + "/" +
                       std::to_string(GetSplineSize()) + "/" +
                       std::to_string(avg_sqr_error);
    return meta;
  }

 private:
  void CalculateError(std::vector<KeyValueType>& data,
                      std::vector<EqualLookup<KeyType>>& lookups) {
    for (auto iter = lookups.begin(); iter != lookups.end(); iter++) {
      SearchBound sb = this->GetSearchBound((*iter).key);

      auto result = std::lower_bound(
          data.begin() + sb.begin, data.begin() + sb.end, (*iter).key,
          [](const KeyValueType& lhs, const KeyType lookup_key) {
            return lhs.key < lookup_key;
          });

      auto first = data.begin() + sb.begin;
      auto count =
          std::distance(data.begin() + sb.begin, data.begin() + sb.end);
      std::advance(first, count / 2);

      auto error = std::distance(result, first);
      sum_sqr_error_ += std::abs(error) * std::abs(error);
    }
  }
  double sum_sqr_error_;
};

}  // namespace srs