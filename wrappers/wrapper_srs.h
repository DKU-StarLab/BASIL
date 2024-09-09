#pragma once

#include "indexes/srs/include/srs/sRS.h"
#include "indexes/srs/include/srs/sRS_builder.h"
#include "util.h"
#include "wrappers/base.h"

template <class KeyType, int radix_bit, int delta, int sampling_interval>
class sRS : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    if (!parameters_set_) util::fail("RS parameters not set.");
    size_t data_size = data.size();

    return util::timing([&] {
      auto min = std::numeric_limits<KeyType>::min();
      auto max = std::numeric_limits<KeyType>::max();

      if (data_size > 0) {
        min = data.front().key;
        max = data.back().key;
      }

      srs::sRSBuilder<KeyType, KeyValue<KeyType>> rsb(
          min, max, data_size, num_radix_bits_, delta_, sampling_interval_);

      srs_ = rsb.BulkLoad(data);
    });
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    const srs::SearchBound sb = srs_.GetSearchBound(lookup_key);
    return {sb.begin, sb.end};
  }

  std::string name() const { return "sRS"; }

  std::size_t size() const { return srs_.GetSize(); }

  bool applicable(bool _unique, const std::string& data_filename) {
    // Remove prefix from filename.
    static constexpr const char* prefix = "data/";
    std::string dataset = data_filename.data();
    dataset.erase(dataset.begin(),
                  dataset.begin() + dataset.find(prefix) + strlen(prefix));

    // Set parameters based on the dataset.
    return SetParameters(dataset);
  }

  std::string variant() const {
    return std::to_string(num_radix_bits_) + "/" + std::to_string(delta_) +
           "/" + std::to_string(sampling_interval_);
  }

 private:
  bool SetParameters(const std::string& dataset) {
    num_radix_bits_ = radix_bit;
    delta_ = delta;
    sampling_interval_ = sampling_interval;
    parameters_set_ = true;
    return true;
  }

  srs::sRS<KeyType, KeyValue<KeyType>> srs_;
  size_t num_radix_bits_;
  size_t delta_;
  size_t sampling_interval_;
  bool parameters_set_ = false;
};
