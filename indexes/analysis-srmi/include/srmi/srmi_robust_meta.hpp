#pragma once

#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <string>
#include "srmi_robust.hpp"
namespace srmi {

/**
 * This is a reimplementation of a two-layer recursive model index (RMI) supporting a variety of (monotonic) models.
 * RMIs were invented by Kraska et al. (https://dl.acm.org/doi/epdf/10.1145/3183713.3196909).
 *
 * Note that this is the base class which does not provide error bounds.
 *
 * @tparam Key the type of the keys to be indexed
 * @tparam Layer1 the type of the model used in layer1
 * @tparam Layer2 the type of the models used in layer2
 */
template<typename Key,  typename KeyValue, typename Layer1, typename Layer2>
class msRmiRobust : public sRmiRobust<Key, KeyValue, Layer1, Layer2>
{
  using key_type = Key;
  using kv_type = KeyValue;
  using layer1_type = Layer1;
  using layer2_type = Layer2;

 protected:
  double sum_sqr_error_;
  uint64_t const_seg_cnt_;
 
 public:
  /**
   * Default constructor.
   */
  msRmiRobust() = default;

  /**
   * Builds the index with @p layer2_size models in layer2 on the sorted @p keys.
   * @param keys vector of sorted keys to be indexed
   * @param layer2_size the number of models in layer2
   */
  msRmiRobust(const std::vector<kv_type> &keys, const std::size_t interval, const std::size_t layer2_size, const float outliers)
      : msRmiRobust(keys.begin(), keys.end(), interval, layer2_size, outliers) { }

  /**
   * Builds the index with @p layer2_size models in layer2 on the sorted keys in the range [first, last).
   * @param first, last iterators that define the range of sorted keys to be indexed
   * @param layer2_size the number of models in layer2
   */
  template<typename RandomIt>
  msRmiRobust(RandomIt first, RandomIt last, const std::size_t interval, const std::size_t layer2_size, const float outliers)
      : sRmiRobust<Key, KeyValue, Layer1, Layer2>(first, last, interval, layer2_size, outliers),
      sum_sqr_error_(0),
      const_seg_cnt_(0) {}

  /**
   * Destructor.
   */
  ~msRmiRobust() {}

  std::string get_meta(std::vector<KeyValue>& data, std::vector<EqualLookup<Key>>& lookups) {
    count_const_segments();
    calculate_error(data, lookups);
    double avg_sqr_error = sum_sqr_error_ / lookups.size();

    std::string meta = std::to_string(avg_sqr_error)
                     + "/"  + std::to_string(const_seg_cnt_);
    return meta;
  }
  
  void calculate_error(std::vector<KeyValue>& data, std::vector<EqualLookup<Key>>& lookups) {
    for(auto iter = lookups.begin(); iter != lookups.end(); iter++){
      Approx sb = this->search((*iter).key);
      
      auto result = std::lower_bound(
        data.begin(), data.end(), (*iter).key,
        [](const KeyValue& lhs, const Key lookup_key) {
          return lhs.key < lookup_key;
        });

      auto pred = data.begin() + sb.pos;
      auto error = std::distance(result, pred);
      sum_sqr_error_ += std::abs(error) * std::abs(error);
    }
  }

  void count_const_segments(){
    for (size_t i = 0; i < this->layer2_size_; i++){
      if (this->l2_[i].slope() == 0.f)
        const_seg_cnt_++;
    }
  }
};
} // namespace srmi
