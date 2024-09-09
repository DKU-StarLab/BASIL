#pragma once

#include "scht/mscht.h"
#include "scht/mscht_builder.h"
#include "util.h"
#include "wrappers/base.h"

template <class KeyType, int num_bins, int delta, int interval>
class msCHT : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    if (!parameters_set_) util::fail("CHT parameters not set.");
    data_ = &data;
    lookups_ = &lookups;

    return util::timing([&] {
      auto min = std::numeric_limits<KeyType>::min();
      auto max = std::numeric_limits<KeyType>::max();

      if (data.size() > 0) {
        min = data.front().key;
        max = data.back().key;
      }
      scht::msCHTBuilder<KeyType, KeyValue<KeyType>> chtb(
          min, max, num_bins_, delta_, interval_, data);
      cht_ = chtb.BulkLoad();
    });
  }

  SearchBound EqualityLookup(const KeyType lookup_key) {
    const scht::SearchBound sb = cht_.GetSearchBound(lookup_key);
    return {sb.begin, sb.end};
  }

  std::string name() const { return "msCHT"; }

  std::size_t size() const { return cht_.GetSize(); }

  bool applicable(bool _unique, const std::string& data_filename) {
    // Remove prefix from filename.
    static constexpr const char* prefix = "data/";
    std::string dataset = data_filename.data();
    dataset.erase(dataset.begin(),
                  dataset.begin() + dataset.find(prefix) + strlen(prefix));

    // Set parameters based on the dataset.
    return SetParameters(dataset);
  }

  std::string variant() {
    return std::to_string(num_bins_) + '/' + std::to_string(delta_) + '/' +
           std::to_string(interval_) + '/' + cht_.GetMeta(*data_, *lookups_);
  }

 private:
  bool SetParameters(const std::string& dataset) {
    num_bins_ = num_bins;
    delta_ = delta;
    interval_ = interval;

    parameters_set_ = true;
    return true;
  }

  scht::msCompactHistTree<KeyType, KeyValue<KeyType>> cht_;
  size_t num_bins_;
  size_t delta_;
  size_t interval_;
  bool parameters_set_ = false;
  std::vector<KeyValue<KeyType>>* data_;
  std::vector<EqualLookup<KeyType>>* lookups_;
};
