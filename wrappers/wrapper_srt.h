#pragma once

#include "util.h"
#include "wrappers/base.h"

template <class KeyType, uint32_t num_radix_bits, int interval>
class sRadixTable : public Competitor {
 public:
  uint64_t Build(std::vector<KeyValue<KeyType>>& data,
                 std::vector<EqualLookup<KeyType>>& lookups) {
    return util::timing([&] {
      n_ = data.size();
      min_ = data.front().key;
      max_ = data.back().key;
      shift_bits_ = shift_bits(max_ - min_);

      uint64_t prev_prefix = 0;
      uint64_t max_prefix = (max_ - min_) >> shift_bits_;
      radix_hint_.resize(max_prefix + 2, 0);

      for (uint64_t i = 0; i < n_ - 1; i += interval) {
        uint64_t curr_prefix = (data[i].key - min_) >> shift_bits_;

        if (curr_prefix != prev_prefix) {
          for (uint64_t p = prev_prefix + 1; p <= curr_prefix; p++) {
            radix_hint_[p] = i;
          }
          prev_prefix = curr_prefix;
        }
      }

      // Last Key
      if (max_prefix != prev_prefix) {
        for (uint64_t p = prev_prefix + 1; p <= max_prefix; p++) {
          radix_hint_[p] = n_ - 1;
        }
      }

      radix_hint_[max_prefix + 1] = n_;
    });
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    // Compute index.
    if (lookup_key < min_)
      return (SearchBound){0, 1};
    else if (lookup_key > max_)
      return (SearchBound){n_ - 1, n_};

    uint64_t p = (lookup_key - min_) >> shift_bits_;
    if (p > radix_hint_.size() - 2) p = radix_hint_.size() - 2;
    uint64_t begin = radix_hint_[p];
    uint64_t end = radix_hint_[p + 1];

    begin = begin < interval - 1 ? 0 : (begin - interval + 1);
    if (end != n_) end++;

    return (SearchBound){begin, end};
  }

  std::string name() const { return std::string("sRT"); }

  std::size_t size() const { return sizeof(uint32_t) * radix_hint_.size(); }

  std::string variant() const {
    return std::to_string(num_radix_bits) + "/" + std::to_string(interval);
  }

  bool applicable(bool _unique, const std::string& filename) const {
    return true;
  }

 private:
  inline uint64_t shift_bits(const uint64_t val) {
    const uint32_t clz = __builtin_clzl(val);
    if ((64 - clz) < num_radix_bits)
      return 0;
    else
      return 64 - num_radix_bits - clz;
  }

  inline uint32_t shift_bits(const uint32_t val) {
    const uint32_t clz = __builtin_clz(val);
    if ((32 - clz) < num_radix_bits)
      return 0;
    else
      return 32 - num_radix_bits - clz;
  }

  uint64_t n_;
  KeyType min_;
  KeyType max_;
  KeyType shift_bits_;

  // this must be a vector and not an array so it can be larger than 1MB
  // without blowing out the stack.
  std::vector<uint32_t> radix_hint_;
};
