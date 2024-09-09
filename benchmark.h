#pragma once

#include <immintrin.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <cfenv>
#include <dtl/thread.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "config.h"
#include "searches/branching_binary_search.h"
#include "util.h"
#include "utils/perf_event.h"

#ifdef __linux__
#define checkLinux(x) (x)
#else
#define checkLinux(x) \
  { util::fail("Only supported on Linux."); }
#endif

// Get the CPU affinity for the process.
static const auto cpu_mask = dtl::this_thread::get_cpu_affinity();

// Batch size in number of lookups.
static constexpr std::size_t batch_size = 1u << 16;

namespace sosd {

// KeyType: Controls the type of the key (the value will always be uint64_t)
//          Use uint64_t for 64 bit types and uint32_t for 32 bit types
//          KeyType must implement operator<
template <typename KeyType = uint64_t,
          template <typename> typename SearchClass = BranchingBinarySearch>
class Benchmark {
 public:
  Benchmark(const std::string& data_filename,
            const std::string& lookups_filename, const size_t num_repeats,
            const bool perf, const bool build, const bool csv, const bool sep,
            const bool tail, const double sampling_ratio, const int perf_no, 
            const size_t num_threads, const SearchClass<KeyType> searcher,
            const std::string& csv_suffix)
      : data_filename_(data_filename),
        lookups_filename_(lookups_filename),
        num_repeats_(num_repeats),
        first_run_(true),
        perf_(perf),
        build_(build),
        csv_(csv),
        sep_(sep),
        tail_(tail),
        sampling_ratio_(sampling_ratio),
        perf_no_(perf_no),
        num_threads_(num_threads),
        searcher_(searcher),
        csv_suffix_(csv_suffix) {
    static constexpr const char* prefix = "data/";
    dataset_name_ = data_filename.data();
    dataset_name_.erase(
    dataset_name_.begin(),
    dataset_name_.begin() + dataset_name_.find(prefix) + strlen(prefix));

    // Load data.
    std::vector<KeyType> keys = util::load_data<KeyType>(data_filename_);

    log_sum_search_bound_ = 0.0;
    l1_sum_search_bound_ = 0.0;
    l2_sum_search_bound_ = 0.0;
    if (!is_sorted(keys.begin(), keys.end()))
      util::fail("keys have to be sorted");
    // Check whether keys are unique.
    unique_keys_ = util::is_unique(keys);
    if (unique_keys_)
      std::cout << "data is unique" << std::endl;
    else
      std::cout << "data contains duplicates" << std::endl;
    // Add artificial values to keys.
    data_ = util::add_values(keys);
    // Load lookups.
    lookups_ = util::load_data<EqualLookup<KeyType>>(lookups_filename_);

    // Create the data for the index (key -> position).
    for (uint64_t pos = 0; pos < data_.size(); pos++) {
      index_data_.push_back((KeyValue<KeyType>){data_[pos].key, pos});
    }
  }

  template <class Index>
  void Run() {
    // Build index.
    Index index;

    if (!index.applicable(unique_keys_, data_filename_)) {
      std::cout << "index " << index.name() << " is not applicable"
                << std::endl;
      return;
    }

    build_ns_ = index.Build(index_data_, lookups_);

    if (index.name().find("Expo") == std::string::npos) {
      DoLookups<Index>(index);
    } else {
      DoLookupsExpo<Index>(index);
    }

    PrintResult(index);
    first_run_ = false;
  }

  bool uses_binary_search() const {
    return (searcher_.name() == "BinarySearch") ||
           (searcher_.name() == "BranchlessBinarySearch");
  }

  bool uses_lienar_search() const { return searcher_.name() == "LinearSearch"; }

 private:
  bool CheckResults(uint64_t actual, uint64_t expected, KeyType lookup_key,
                    SearchBound bound) {
    if (actual != expected) {
      const auto pos = std::find_if(
          data_.begin(), data_.end(),
          [lookup_key](const auto& kv) { return kv.key == lookup_key; });

      const auto idx = std::distance(data_.begin(), pos);

      std::cout << "equality lookup returned wrong result:" << std::endl;
      std::cout << "lookup key: " << lookup_key << std::endl;
      std::cout << "actual: " << actual << ", expected: " << expected
                << std::endl
                << "correct index is: " << idx << std::endl
                << "index start: " << bound.start << " stop: " << bound.stop
                << std::endl;

      return false;
    }

    return true;
  }

  template <class Index>
  void DoLookups(Index& index) {
    if (build_) return;

    // Atomic counter used to assign work to threads.
    std::atomic<std::size_t> cntr(0);

    bool run_failed = false;

    runs_.resize(num_repeats_);
    for (unsigned int i = 0; i < num_repeats_; ++i) {
      random_sum_ = 0;
      individual_ns_sum_ = 0;

      uint64_t ms;
      if (num_threads_ == 1) {
        if (sep_) {
          ms = util::timing([&] {
            SepBinLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        } else if (tail_) {
          tail_latencys_.resize(lookups_.size() * sampling_ratio_);
          ms = util::timing([&] {
            TailBinLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        } else if (perf_) {
          ms = util::timing([&] {
            PerfBinLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        } else {
          ms = util::timing([&] {
            AvgBinLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        }
      } else {
        // Reset atomic counter.
        cntr.store(0);
        ms = util::timing([&] {
          while (true) {
            const size_t begin = cntr.fetch_add(batch_size);
            if (begin >= lookups_.size()) break;
            unsigned int limit = std::min(begin + batch_size, lookups_.size());
            AvgBinLookupsLoop<Index>(index, begin, limit, run_failed);
          }
        });
      }
      runs_[i] = ms;
      if (run_failed) {
        runs_ = std::vector<uint64_t>(num_repeats_, 0);
        return;
      }
    }
  }

  template <class Index>
  void DoLookupsExpo(Index& index) {
    if (build_) return;

    // Atomic counter used to assign work to threads.
    std::atomic<std::size_t> cntr(0);

    bool run_failed = false;

    runs_.resize(num_repeats_);
    for (unsigned int i = 0; i < num_repeats_; ++i) {
      random_sum_ = 0;
      individual_ns_sum_ = 0;

      uint64_t ms;
      if (num_threads_ == 1) {
        if (sep_) {
          ms = util::timing([&] {
            SepExpoLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        } else if (tail_) {
          tail_latencys_.resize(lookups_.size() * sampling_ratio_);
          ms = util::timing([&] {
            TailExpoLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        } else if (perf_) {
          ms = util::timing([&] {
            PerfExpoLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        } else {
          ms = util::timing([&] {
            AvgExpoLookupsLoop<Index>(index, 0, lookups_.size(), run_failed);
          });
        }
      } else {
        // Reset atomic counter.
        cntr.store(0);
        ms = util::timing([&] {
          while (true) {
            const size_t begin = cntr.fetch_add(batch_size);
            if (begin >= lookups_.size()) break;
            unsigned int limit = std::min(begin + batch_size, lookups_.size());
            AvgExpoLookupsLoop<Index>(index, begin, limit, run_failed);
          }
        });
      }
      runs_[i] = ms;
      if (run_failed) {
        runs_ = std::vector<uint64_t>(num_repeats_, 0);
        return;
      }
    }
  }

  template <class Index>
  void AvgBinLookupsLoop(Index& index, unsigned int start, unsigned int limit,
                         bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    for (unsigned int idx = start; idx < limit; ++idx) {
      // Compute the actual index for debugging.
      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;

      // not tracking errors, measure the lookup time.
      bound = index.EqualityLookup(lookup_key);

      iter = std::lower_bound(
          data_.begin() + bound.start, data_.begin() + bound.stop, lookup_key,
          [](const Row<KeyType>& lhs, const KeyType lookup_key) {
            return lhs.key < lookup_key;
          });

      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }

      if (result != expected) run_failed = true;
    }
  }
  template <class Index>
  void TailBinLookupsLoop(Index& index, unsigned int start_idx,
                          unsigned int limit, bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    size_t sampling_interval = limit / (limit * sampling_ratio_);

    for (unsigned int idx = start_idx; idx < limit; ++idx) {
      if (idx % sampling_interval == 0) {
        start = std::chrono::high_resolution_clock::now();
      }

      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;
      bound = index.EqualityLookup(lookup_key);

      iter = std::lower_bound(
          data_.begin() + bound.start, data_.begin() + bound.stop, lookup_key,
          [](const Row<KeyType>& lhs, const KeyType lookup_key) {
            return lhs.key < lookup_key;
          });

      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }

      if (result != expected) run_failed = true;

      if (idx % sampling_interval == 0) {
        end = std::chrono::high_resolution_clock::now();
        tail_latencys_.push_back(
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                .count());
      }
    }
  }
  template <class Index>
  void SepBinLookupsLoop(Index& index, unsigned int start_idx,
                          unsigned int limit, bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    auto start = std::chrono::high_resolution_clock::now();
    auto mid = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    auto sum_total =
        std::chrono::duration_cast<std::chrono::nanoseconds>(start - start);
    auto sum_pred =
        std::chrono::duration_cast<std::chrono::nanoseconds>(mid - mid);
    auto sum_corr =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - end);

    for (unsigned int idx = start_idx; idx < limit; ++idx) {
      start = std::chrono::high_resolution_clock::now();
      
      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;
      bound = index.EqualityLookup(lookup_key);
      
      mid = std::chrono::high_resolution_clock::now();

      iter = std::lower_bound(
          data_.begin() + bound.start, data_.begin() + bound.stop, lookup_key,
          [](const Row<KeyType>& lhs, const KeyType lookup_key) {
            return lhs.key < lookup_key;
          });

      result = 0;

      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }

      if (result != expected) {
        run_failed = true;
      }

      end = std::chrono::high_resolution_clock::now();

      sum_total +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      sum_pred +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(mid - start);
      sum_corr +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - mid);
    }
    avg_total_ = static_cast<double>(sum_total.count()) / lookups_.size();
    avg_pred_ = static_cast<double>(sum_pred.count()) / lookups_.size();
    avg_corr_ = static_cast<double>(sum_corr.count()) / lookups_.size();
  }

  template <class Index>
  void PerfBinLookupsLoop(Index& index, unsigned int start, unsigned int limit,
                          bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    int pred_fd = setup_perf_event(perf_no_);
    int corr_fd = setup_perf_event(perf_no_);

    for (unsigned int idx = start; idx < limit; ++idx) {
      enable_perf_event(pred_fd);
      
      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;
      bound = index.EqualityLookup(lookup_key);
      
      disable_perf_event(pred_fd);
      enable_perf_event(corr_fd);
        
      iter = std::lower_bound(
          data_.begin() + bound.start, data_.begin() + bound.stop, lookup_key,
          [](const Row<KeyType>& lhs, const KeyType lookup_key) {
            return lhs.key < lookup_key;
          });

      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }

      if (result != expected) run_failed = true;
      
      disable_perf_event(corr_fd);
    }
    pred_perf_ = close_perf_event(pred_fd);
    corr_perf_ = close_perf_event(corr_fd);
  }
  
  template <class Index>
  void AvgExpoLookupsLoop(Index& index, unsigned int start, unsigned int limit,
                          bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    for (unsigned int idx = start; idx < limit; ++idx) {
      // Compute the actual index for debugging.
      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;

      // not tracking errors, measure the lookup time.
      bound = index.EqualityLookup(lookup_key);
      auto pred = data_.begin() + bound.start;
      size_t b = 1;

      if ((*pred).key < lookup_key) {  // search right side
        auto curr = pred + b;
        while ((curr < data_.end()) && ((*curr).key < lookup_key)) {
          b *= 2;
          pred = curr;
          curr += b;
        }
        iter = std::lower_bound(
            pred, std::min(curr + 1, data_.end()), lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      } else {  // search left side
        auto curr = pred - b;
        while ((curr > data_.begin()) && ((*curr).key > lookup_key)) {
          b *= 2;
          pred = curr;
          curr -= b;
        }
        iter = std::lower_bound(
            std::max(data_.begin(), curr), pred, lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      }
      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }
      if (result != expected) run_failed = true;
    }
  }

  template <class Index>
  void TailExpoLookupsLoop(Index& index, unsigned int start_idx,
                           unsigned int limit, bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    size_t sampling_interval = limit / (limit * sampling_ratio_);

    for (unsigned int idx = start_idx; idx < limit; ++idx) {
      if (idx % sampling_interval == 0) {
        start = std::chrono::high_resolution_clock::now();
      }

      // Compute the actual index for debugging.
      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;

      // not tracking errors, measure the lookup time.
      bound = index.EqualityLookup(lookup_key);

      auto pred = data_.begin() + bound.start;
      size_t b = 1;

      if ((*pred).key < lookup_key) {  // search right side
        auto curr = pred + b;
        while ((curr < data_.end()) && ((*curr).key < lookup_key)) {
          b *= 2;
          pred = curr;
          curr += b;
        }
        iter = std::lower_bound(
            pred, std::min(curr + 1, data_.end()), lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      } else {  // search left side
        auto curr = pred - b;
        while ((curr > data_.begin()) && ((*curr).key > lookup_key)) {
          b *= 2;
          pred = curr;
          curr -= b;
        }
        iter = std::lower_bound(
            std::max(data_.begin(), curr), pred, lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      }

      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }

      if (result != expected) run_failed = true;

      if (idx % sampling_interval == 0) {
        end = std::chrono::high_resolution_clock::now();
        tail_latencys_.push_back(
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                .count());
      }
    }
  }

  template <class Index>
  void SepExpoLookupsLoop(Index& index, unsigned int start_idx,
                           unsigned int limit, bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    auto start = std::chrono::high_resolution_clock::now();
    auto mid = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    auto sum_total =
        std::chrono::duration_cast<std::chrono::nanoseconds>(start - start);
    auto sum_pred =
        std::chrono::duration_cast<std::chrono::nanoseconds>(mid - mid);
    auto sum_corr =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - end);

    for (unsigned int idx = start_idx; idx < limit; ++idx) {
      start = std::chrono::high_resolution_clock::now();

      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;
      bound = index.EqualityLookup(lookup_key);
      
      mid = std::chrono::high_resolution_clock::now();

      auto pred = data_.begin() + bound.start;
      size_t b = 1;
      if ((*pred).key < lookup_key) {  // search right side
        auto curr = pred + b;
        while ((curr < data_.end()) && ((*curr).key < lookup_key)) {
          b *= 2;
          pred = curr;
          curr += b;
        }
        iter = std::lower_bound(
            pred, std::min(curr + 1, data_.end()), lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      } else {  // search left side
        auto curr = pred - b;
        while ((curr > data_.begin()) && ((*curr).key > lookup_key)) {
          b *= 2;
          pred = curr;
          curr -= b;
        }
        iter = std::lower_bound(
            std::max(data_.begin(), curr), pred, lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      }
      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }
      if (result != expected) run_failed = true;

      end = std::chrono::high_resolution_clock::now();
      sum_total +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      sum_pred +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(mid - start);
      sum_corr +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - mid);
    }
    avg_total_ = static_cast<double>(sum_total.count()) / lookups_.size();
    avg_pred_ = static_cast<double>(sum_pred.count()) / lookups_.size();
    avg_corr_ = static_cast<double>(sum_corr.count()) / lookups_.size();
  }

  template <class Index>
  void PerfExpoLookupsLoop(Index& index, unsigned int start, unsigned int limit,
                           bool& run_failed) {
    SearchBound bound = {};
    uint64_t result;
    typename std::vector<Row<KeyType>>::iterator iter;

    int pred_fd = setup_perf_event(perf_no_);
    int corr_fd = setup_perf_event(perf_no_);

    for (unsigned int idx = start; idx < limit; ++idx) {
      enable_perf_event(pred_fd);
      
      const volatile uint64_t lookup_key = lookups_[idx].key;
      const volatile uint64_t expected = lookups_[idx].result;
      bound = index.EqualityLookup(lookup_key);
      
      disable_perf_event(pred_fd);
      enable_perf_event(corr_fd);
      
      auto pred = data_.begin() + bound.start;
      size_t b = 1;
      
      if ((*pred).key < lookup_key) {  // search right side
        auto curr = pred + b;
        while ((curr < data_.end()) && ((*curr).key < lookup_key)) {
          b *= 2;
          pred = curr;
          curr += b;
        }
        iter = std::lower_bound(
            pred, std::min(curr + 1, data_.end()), lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      } else {  // search left side
        auto curr = pred - b;
        while ((curr > data_.begin()) && ((*curr).key > lookup_key)) {
          b *= 2;
          pred = curr;
          curr -= b;
        }
        iter = std::lower_bound(
            std::max(data_.begin(), curr), pred, lookup_key,
            [](const Row<KeyType>& lhs, const KeyType lookup_key) {
              return lhs.key < lookup_key;
            });
      }

      result = 0;
      while (iter != data_.end() && iter->key == lookup_key) {
        result += iter->data[0];
        ++iter;
      }
      if (result != expected) run_failed = true;
      
      disable_perf_event(corr_fd);
    }
    pred_perf_ = close_perf_event(pred_fd);
    corr_perf_ = close_perf_event(corr_fd);
  }

  template <class Index>
  void PrintResult(Index& index) {
    std::string result_str = "";

    if (build_) {
      result_str = "build_only";
    } else if (tail_) {
      std::sort(tail_latencys_.begin(), tail_latencys_.end());

      result_str =
          std::to_string(tail_latencys_[0]) + "," +
          std::to_string(tail_latencys_[0.5 * tail_latencys_.size()]) + "," +
          std::to_string(tail_latencys_[0.9 * tail_latencys_.size()]) + "," +
          std::to_string(tail_latencys_[0.99 * tail_latencys_.size()]) + "," +
          std::to_string(tail_latencys_[0.999 * tail_latencys_.size()]) + "," +
          std::to_string(tail_latencys_[0.9999 * tail_latencys_.size()]) + "," +
          std::to_string(tail_latencys_[tail_latencys_.size() - 1]);
    } else if (sep_) {
      result_str = std::to_string(avg_total_) + "," +
                   std::to_string(avg_pred_) + "," + std::to_string(avg_corr_);
    } else if (perf_) {
      std::string perf_name = "";

      if (perf_no_ == 0){
        perf_name = ",LLC miss";
      } else if (perf_no_ == 1){
        perf_name = ",TLB miss";
      } else if (perf_no_ == 2){    
        perf_name = ",Branch miss";
      } else if (perf_no_ == 3){
        perf_name = ",Instructions";
      }
  
      result_str += std::to_string(pred_perf_) + "," 
                    + std::to_string(corr_perf_) + perf_name;
    } else {
      // compute median time
      std::vector<double> times;
      double median_time;
      for (unsigned int i = 0; i < runs_.size(); ++i) {
        const double ns_per_lookup =
            static_cast<double>(runs_[i]) / lookups_.size();
        times.push_back(ns_per_lookup);
      }
      std::sort(times.begin(), times.end());
      if (times.size() % 2 == 0) {
        median_time =
            0.5 * (times[times.size() / 2 - 1] + times[times.size() / 2]);
      } else {
        median_time = times[times.size() / 2];
      }

      result_str = std::to_string(median_time);
    }

    // don't print a line if (the first) run failed
    if (!build_ && runs_[0] == 0) result_str = "fail";

    std::string variant_str = index.variant();
    std::cout << "RESULT: " << index.name() << "," << variant_str << ","
              << index.size() << "," << build_ns_ << "," << result_str
              << std::endl;

    if (csv_) PrintResultCSV(index, result_str, variant_str);
  }

  template <class Index>
  void PrintResultCSV(Index& index, std::string result_str, std::string variant_str) {
    std::string filename = "";
    if (sep_) {
      filename = "./results/" + dataset_name_ + "_results_sep";
    } else if (build_) {
      filename = "./results/" + dataset_name_ + "_results_build";
    } else if (tail_) {
      filename = "./results/" + dataset_name_ + "_results_tail";
    } else if (perf_) {
      filename = "./results/" + dataset_name_ + "_results_perf";
    } else {
      filename = "./results/" + dataset_name_ + "_results_table";
    }

    if (csv_suffix_ != "") {
      filename = filename + "_" + csv_suffix_ + ".csv";
    } else {
      filename = filename + ".csv";
    }


    bool is_new = false;

    // 파일이 존재하는지 확인
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        is_new = true;
        fin.close();
    }

    std::ofstream fout(filename, std::ofstream::out | std::ofstream::app);
    if (!fout.is_open()) {
      std::cerr << "Failure to print CSV on " << filename << std::endl;
      return;
    }

    if (is_new){
      std::string header;
      if (sep_) {
        header = "index,options,space,build,total,predict,correct,dataset";
      } else if (build_) {
        header = "index,options,space,build,average,dataset";
      } else if (tail_) {
        header = "index,options,space,build,0.0,0.5,0.9,0.99,0.999,0.9999,1.0,dataset";
      } else if (perf_) {
        header = "index,options,space,build,perf_predict,perf_correct,perf type,dataset";
      } else {
        header = "index,options,space,build,average,dataset";
      }
      fout << header << std::endl;
    }

    if (!build_ && runs_[0] == 0)
      std::string index_name = index_name + "[FAIL]";

    fout << index.name() << "," << variant_str << "," << index.size() << ","
         << build_ns_ << "," << result_str << "," << dataset_name_ << std::endl;

    fout.close();
    return;
  }

  uint64_t random_sum_ = 0;
  uint64_t individual_ns_sum_ = 0;
  const std::string data_filename_;
  const std::string lookups_filename_;
  std::string dataset_name_;
  std::vector<Row<KeyType>> data_;
  std::vector<KeyValue<KeyType>> index_data_;
  bool unique_keys_;
  std::vector<EqualLookup<KeyType>> lookups_;
  uint64_t build_ns_;
  double log_sum_search_bound_;
  double l1_sum_search_bound_;
  double l2_sum_search_bound_;
  double avg_total_;
  double avg_pred_;
  double avg_corr_;
  // Run times.
  std::vector<uint64_t> runs_;
  // Number of times we repeat the lookup code.
  size_t num_repeats_;
  // Used to only print profiling header information for first run.
  bool first_run_;
  bool perf_;
  bool build_;
  bool measure_each_;
  bool csv_;
  bool sep_;
  bool tail_;
  double sampling_ratio_;
  int perf_no_;
  // Number of lookup threads.
  const size_t num_threads_;
  std::vector<double> tail_latencys_;
  long long pred_perf_ = 0;
  long long corr_perf_ = 0;
  std::vector<uint64_t> memory_;  // Some memory we can read to flush the cache
  SearchClass<KeyType> searcher_;
  std::string csv_suffix_;
};

}  // namespace sosd