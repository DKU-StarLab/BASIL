#pragma once

#include <algorithm>
#include <vector>
#include <numeric>


namespace srmi {

/**
 * Struct to hold the approximated position and error bounds returned by the index.
 */
struct Approx {
  std::size_t pos; ///< The estimated position of the key.
  std::size_t lo;  ///< The lower bound of the search range.
  std::size_t hi;  ///< The upper bound of the search range.
};

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
class sRmiRobust
{
  using key_type = Key;
  using kv_type = KeyValue;
  using layer1_type = Layer1;
  using layer2_type = Layer2;

 protected:
  std::size_t n_keys_;      ///< The number of keys the index was built on.
  std::size_t layer2_size_; ///< The number of models in layer2.
  std::size_t interval_;    ///< Sampling Interval
  layer1_type l1_;          ///< The layer1 model.
  layer2_type *l2_;         ///< The array of layer2 models.
  float outliers_;          ///< The proportion of elements to disregard as outliers

 public:
  /**
   * Default constructor.
   */
  sRmiRobust() = default;

  /**
   * Builds the index with @p layer2_size models in layer2 on the sorted @p keys.
   * @param keys vector of sorted keys to be indexed
   * @param layer2_size the number of models in layer2
   */
  sRmiRobust(const std::vector<kv_type> &keys, const std::size_t interval, const std::size_t layer2_size, const float outliers)
      : sRmiRobust(keys.begin(), keys.end(), interval, layer2_size, outliers) { }

  /**
   * Builds the index with @p layer2_size models in layer2 on the sorted keys in the range [first, last).
   * @param first, last iterators that define the range of sorted keys to be indexed
   * @param layer2_size the number of models in layer2
   */
  template<typename RandomIt>
  sRmiRobust(RandomIt first, RandomIt last, const std::size_t interval, const std::size_t layer2_size, const float outliers)
      : n_keys_(std::distance(first, last))
      , layer2_size_(layer2_size)
      , interval_(interval)
      , outliers_(outliers)
  {
    std::size_t outlier_size = (std::size_t) (outliers_ * n_keys_);
    // Train layer1.
    l1_ = layer1_type(first + outlier_size, last - outlier_size, outlier_size, static_cast<double>(layer2_size) / n_keys_); // train with compression

    // Train layer2.
    l2_ = new layer2_type[layer2_size];
    std::size_t segment_start = 0;
    std::size_t segment_id = 0;

    auto pos = first;
    std::size_t pred_segment_id = 0;
    std::size_t i = 0;

    // Assign each key to its segment.
    for (i = 0; i < n_keys_ - 1; i += interval_) {
      pos = first + i;
      pred_segment_id = get_segment_id((*pos).key);
      // If a key is assigned to a new segment, all models must be trained up to the new segment.
      if (pred_segment_id > segment_id) {
        new (&l2_[segment_id]) layer2_type(first + segment_start, pos, interval_, segment_start);
        for (std::size_t j = segment_id + 1; j < pred_segment_id; ++j) {
          new (&l2_[j]) layer2_type(pos - interval, pos, interval_, i - interval); // train other models on last key in previous segment
        }
        segment_id = pred_segment_id;
        segment_start = i;
      }
    }

    // Train last key.
    auto last_pos = pos;
    i = n_keys_ - 1;

    pos = first + i;
    pred_segment_id = get_segment_id((*pos).key);
    // If a key is assigned to a new segment, all models must be trained up to the new segment.
    if (pred_segment_id > segment_id) {
      new (&l2_[segment_id]) layer2_type(first + segment_start, pos, interval_, segment_start);
      for (std::size_t j = segment_id + 1; j < pred_segment_id; ++j) {
        new (&l2_[j]) layer2_type(last_pos, pos, interval_, std::distance(first, last_pos)); // train other models on last key in previous segment
      }
      segment_id = pred_segment_id;
      segment_start = i;
    }
    
    // Train remaining models.
    new (&l2_[segment_id]) layer2_type(first + segment_start, last, interval_, segment_start);
    for (std::size_t j = segment_id + 1; j < layer2_size; ++j) {
      new (&l2_[j]) layer2_type(last - 1, last, interval_, n_keys_ - 1); // train remaining models on last key
    }
  }

  /**
   * Destructor.
   */
  ~sRmiRobust() { delete[] l2_; }

  /**
   * Returns the id of the segment @p key belongs to.
   * @param key to get segment id for
   * @return segment id of the given key
   */
  std::size_t get_segment_id(const key_type key) const {
    return std::clamp<double>(l1_.predict(key), 0, layer2_size_ - 1);
  }

  /**
   * Returns a position estimate and search bounds for a given key.
   * @param key to search for
   * @return position estimate and search bounds
   */
  Approx search(const key_type key) const {
    auto segment_id = get_segment_id(key);
    std::size_t pred = std::clamp<double>(l2_[segment_id].predict(key), 0, n_keys_ - 1);
    return {pred, 0, n_keys_};
  }

  /**
   * Returns the number of keys the index was built on.
   * @return the number of keys the index was built on
   */
  std::size_t n_keys() const { return n_keys_; }

  /**
   * Returns the number of models in layer2.
   * @return the number of models in layer2
   */
  std::size_t layer2_size() const { return layer2_size_; }

  /**
   * Returns the size of the index in bytes.
   * @return index size in bytes
   */
  std::size_t size_in_bytes() {
    return l1_.size_in_bytes() + layer2_size_ * l2_[0].size_in_bytes() + sizeof(n_keys_) + sizeof(layer2_size_);
  }

  /**
   * Returns a representation of the number of segments within each "bin" of the data
   * @return vector with number of segments in each bin
   */
   std::vector<std::size_t> segments_per_bin(const std::vector<key_type> &keys, std::size_t num_bins) {
     std::vector<std::size_t> bin_segments;
     auto bin_size = keys.size() / num_bins;
     bin_segments.push_back(get_segment_id(keys[bin_size] - 1));
     for (std::size_t i = 2; i <= num_bins; i++) {
        bin_segments.push_back(get_segment_id(keys[bin_size * i] - 1) - bin_segments[bin_segments.size() - 1]);
     }
     return bin_segments;
   }
};
} // namespace rmi
