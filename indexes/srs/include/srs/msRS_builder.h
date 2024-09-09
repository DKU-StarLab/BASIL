#pragma once

#include <cassert>
#include <cmath>
#include <limits>

#include "common.h"
#include "msRS.h"
#include "sRS_builder.h"

namespace srs {
// Allows building a `RadixSpline` in a single pass over sorted data.
template <class KeyType, class KeyValueType>
class msRSBuilder : public sRSBuilder<KeyType, KeyValueType> {
 public:
  msRSBuilder(KeyType min_key, KeyType max_key, size_t original_num_keys,
              size_t num_radix_bits = 18, size_t train_max_error = 48,
              size_t sampling_interval = 16)
      : sRSBuilder<KeyType, KeyValueType>(min_key, max_key, original_num_keys,
                                          num_radix_bits, train_max_error,
                                          sampling_interval) {}

  msRS<KeyType, KeyValueType> BulkLoad(const std::vector<KeyValueType>& kvs) {
    assert(this->curr_num_keys_ == 0);

    size_t num = kvs.size();
    this->AddKey(kvs[0].key, 0);

    for (size_t i = this->interval_; i < num - 1; i += this->interval_) {
      this->AddKey(kvs[i].key, this->prev_position_ + this->interval_);
    }

    this->AddKey(kvs[num - 1].key, num - 1);

    return Finalize();
  }

 private:
  // Finalizes the construction and returns a read-only `RadixSpline`.
  msRS<KeyType, KeyValueType> Finalize() {
    // Last key needs to be equal to `max_key_`.
    assert(this->curr_num_keys_ == 0 || this->prev_key_ == this->max_key_);

    // Ensure that `prev_key_` (== `max_key_`) is last key on spline.
    if (this->curr_num_keys_ > 0 &&
        this->spline_points_.back().x != this->prev_key_)
      this->AddKeyToSpline(this->prev_key_, this->prev_position_);

    // Maybe even size the radix based on max key right from the start
    this->FinalizeRadixTable();

    return msRS<KeyType, KeyValueType>(
        this->min_key_, this->max_key_, this->original_num_keys_,
        this->num_radix_bits_, this->num_shift_bits_, this->interval_,
        this->max_error_, std::move(this->radix_table_),
        std::move(this->spline_points_));
  }
};
}  // namespace srs