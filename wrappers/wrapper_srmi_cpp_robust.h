#pragma once

#include <fstream>
#include <memory>
#include <utility>

#include "base.h"
#include "indexes/analysis-srmi/include/srmi/models.hpp"
#include "indexes/analysis-srmi/include/srmi/srmi_robust.hpp"

// Alternate implementation of RMI in C++ with robust outlier compensation
template <class KeyType, typename Layer1, typename Layer2,
          template <typename...> typename RMIType, size_t layer2_size,
          int numerator, int denominator, size_t interval>
class sRMICppRobust : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    return util::timing([&] {
      rmi_ =
          std::make_unique<RMIType<KeyType, KeyValue<KeyType>, Layer1, Layer2>>(
              data, interval, layer2_size,
              (double)numerator / (double)denominator);
    });
  }
  std::string name() const { return "sRMI(Expo)"; }

  std::size_t size() const { return rmi_->size_in_bytes(); }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    auto it = rmi_->search(lookup_key);
    return (SearchBound){it.pos, 0};
  }

  std::string variant() const {
    return std::to_string(layer2_size) + "/" +
           std::to_string((double)numerator / (double)denominator) + "/" +
           std::to_string(interval);
  }

 private:
  // std::vector<KeyValue<KeyType>> data_ = data;
  std::unique_ptr<RMIType<KeyType, KeyValue<KeyType>, Layer1, Layer2>> rmi_;
};
