// This file is part of PGM-index <https://github.com/gvinciguerra/PGM-index>.
// Copyright (c) 2018 Giorgio Vinciguerra.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "pgm_index_sampling.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <utility>
#include <vector>

namespace spgm {
template<typename K, typename KV, size_t Epsilon = 48, size_t Interval = 16, size_t EpsilonRecursive = 4, 
         size_t IntervalRecursive = 1, typename Floating = float>
class msPGMIndex : public sPGMIndex<K, KV, Epsilon, Interval, EpsilonRecursive, IntervalRecursive, Floating>{
protected:
    double sum_sqr_error = 0;
    std::string seg_cnt = "";
    std::string seg_size = "";

    template <typename K2, typename KV2, size_t Epsilon2, size_t Interval2, size_t EpsilonRecursive2, size_t IntervalRecursive2, typename Floating2>
    using Segment = typename sPGMIndex<K2, KV2, Epsilon2, Interval2, EpsilonRecursive2, IntervalRecursive2, Floating2>::Segment;

public:
    /**
     * Constructs an empty index.
     */
    msPGMIndex() = default;

    /**
     * Constructs the index on the given sorted vector.
     * @param data the vector of keys to be indexed, must be sorted
     */
    explicit msPGMIndex(const std::vector<K> &data) : msPGMIndex(data.begin(), data.end()) {}

    /**
     * Constructs the index on the sorted keys in the range [first, last).
     * @param first, last the range containing the sorted keys to be indexed
     */
    template<typename RandomIt>
    msPGMIndex(RandomIt first, RandomIt last)
        : sPGMIndex<K, KV, Epsilon, Interval, EpsilonRecursive, IntervalRecursive, Floating>(first, last) {}

    std::string GetMeta(std::vector<KV>& data, std::vector<EqualLookup<K>>& lookups) {
        CalculateError(data, lookups);
        CalculateSegmentCount();
        
        double avg_sqr_error_ = sum_sqr_error / lookups.size();   
        std::string meta = seg_cnt + "/" + seg_size + "/" + std::to_string(avg_sqr_error_);
        return meta;
    }

    void CalculateError(std::vector<KV>& data, std::vector<EqualLookup<K>>& lookups) {
        for(auto iter = lookups.begin(); iter != lookups.end(); iter++){
            ApproxPos sb = this->search((*iter).key);

            auto result = std::lower_bound(
                data.begin() + sb.lo, data.begin() + sb.hi, (*iter).key,
                [](const KV& lhs, const K lookup_key) {
                    return lhs.key < lookup_key;
                });

            auto first = data.begin() + sb.lo;
            auto count = std::distance(data.begin() + sb.lo, data.begin() + sb.hi);
            std::advance(first, count/2);

            auto error = std::distance(result, first);
            sum_sqr_error += std::abs(error) * std::abs(error);
        }
    }

    void CalculateSegmentCount() {
        for (size_t i = 1; i < this->height() + 1; i++){
            size_t level_cnt = 0;
            if (i == 1){
                level_cnt = this->levels_offsets[i] - 1;
            } else {
                level_cnt = this->levels_offsets[i] - this->levels_offsets[i-1] - 1;
            }

            if (i != 1){
                seg_cnt += "-";
                seg_size += "-"; 
            }
            
            seg_cnt += std::to_string(level_cnt);
            seg_size += std::to_string(level_cnt * sizeof(Segment<K, KV, Epsilon, Interval, EpsilonRecursive, IntervalRecursive, Floating>));
        }
    }
};
}