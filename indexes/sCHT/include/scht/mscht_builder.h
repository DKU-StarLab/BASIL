#pragma once

#include <cassert>
#include <cmath>
#include <limits>

#include "common.h"
#include "mscht.h"

namespace scht {

// Allows building a `CompactHistTree` in a single pass over sorted data.
template <class KeyType, class KeyValType>
class msCHTBuilder : public sCHTBuilder<KeyType, KeyValType> {
 public:
  // The cache-oblivious structure makes sense when the tree becomes deep
  // (`numBins` or `maxError` become small)
  msCHTBuilder(KeyType min_key, KeyType max_key, size_t num_bins,
               size_t max_error, size_t interval,
               std::vector<KeyValType>& kv_vec, bool use_cache = false)
      : sCHTBuilder<KeyType, KeyValType>(min_key, max_key, num_bins, max_error,
                                         interval, kv_vec, use_cache) {}

  msCompactHistTree<KeyType, KeyValType> BulkLoad() {
    this->BuildOfflineNotCopy();
    return Finalize();
  }

  msCompactHistTree<KeyType, KeyValType> Finalize() {
    if (!this->use_cache_) {
      this->Flatten();
    } else {
      this->CacheObliviousFlatten();
    }

    return msCompactHistTree<KeyType, KeyValType>(
        this->min_key_, this->max_key_, this->curr_num_keys_, this->num_bins_,
        this->log_num_bins_, this->max_error_, this->interval_, this->shift_,
        std::move(this->table_));
  }
};

}  // namespace scht