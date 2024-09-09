#include "benchmark.h"
#include <cstdlib>
#include "wrappers/wrapper_binary_search.h"
#include "benchmarks/benchmark_art.h"
#include "benchmarks/benchmark_bs.h"
#include "benchmarks/benchmark_btree.h"
#include "benchmarks/benchmark_ibtree.h"
#include "benchmarks/benchmark_srmi_alt.h"
#include "benchmarks/benchmark_spgm.h"
#include "benchmarks/benchmark_srs.h"
#include "benchmarks/benchmark_scht.h"
#include "benchmarks/benchmark_srt.h"
#include "benchmarks/meta/benchmark_meta_srmi_alt.h"
#include "benchmarks/meta/benchmark_meta_spgm.h"
#include "benchmarks/meta/benchmark_meta_srs.h"
#include "benchmarks/meta/benchmark_meta_scht.h"

#include "config.h"
#include "searches/branching_binary_search.h"
#include "searches/branchless_binary_search.h"
#include "searches/interpolation_search.h"
#include "searches/linear_search.h"
#include "utils/cxxopts.hpp"
using namespace std;

#define check_only(tag, code)        \
  if ((!only_mode) || only == tag) { \
    code;                            \
  }
#define add_search_type(name, func, type, search_class)                   \
  {                                                                       \
    if (search_type == (name)) {                                          \
      auto search = search_class<type>();                                 \
      sosd::Benchmark<type, search_class> benchmark(                      \
          filename, lookups, num_repeats, perf, build,                    \
          csv, sep, tail, sampling_ratio, perf_no,                        \
          num_threads, search, csv_suffix);                               \
      func(benchmark, only_mode, only, filename);                         \
      found_search_type = true;                                           \
      break;                                                              \
    }                                                                     \
  }

template <class Benchmark>
void execute_32_bit(Benchmark benchmark, bool only_mode,
                    std::string only, std::string filename) {
}

template <class Benchmark>
void execute_64_bit(Benchmark benchmark, bool only_mode,
                    std::string only, std::string filename) {
  check_only("BS", benchmark_64_bs(benchmark));
  check_only("ART", benchmark_64_art(benchmark));
  check_only("BTree", benchmark_64_btree(benchmark));
  check_only("IBTree", benchmark_64_ibtree(benchmark));
  check_only("sRT", benchmark_64_srt(benchmark));
  check_only("sRMI_CPP", benchmark_64_srmi_cpp(benchmark));
  check_only("sPGM", benchmark_64_spgm(benchmark));
  check_only("sRS", benchmark_64_srs(benchmark));
  check_only("sCHT", benchmark_64_scht(benchmark));
  check_only("msRMI_CPP", benchmark_64_srmi_cpp_meta(benchmark));
  check_only("msPGM", benchmark_64_spgm_meta(benchmark));
  check_only("msRS", benchmark_64_srs_meta(benchmark));
  check_only("msCHT", benchmark_64_scht_meta(benchmark));
}


int main(int argc, char* argv[]) {
  cxxopts::Options options("benchmark", "Searching on sorted data benchmark");
  options.positional_help("<data> <lookups>");
  options.add_options()(
    "data", "Data file with keys",cxxopts::value<std::string>())(
    "lookups", "Lookup key (query) file", cxxopts::value<std::string>())(
    "help", "Displays help")(
    "r,repeats", "Number of repeats", cxxopts::value<int>()->default_value("1"))(
    "t,threads", "Number of lookup threads",
    cxxopts::value<int>()->default_value("1"))(
    "s,sampling_ratio", "Sampling ratio of tail latency",
      cxxopts::value<double>()->default_value("0.01"))(
    "p,perf","Track performance counters")(
    "o,perf_option","Perf option 0) LLC, 1) TLB, 2) Branch, 3) Instruction",
        cxxopts::value<int>()->default_value("0"))(
    "sep","Time prediction and correction separately")(
    "l,tail", "long tail latency(0/0.5/0.9/0.99/0.999/0.9999)")(  
    "b,build", "Only measure and report build times")(
    "only", "Only run the specified index",
        cxxopts::value<std::string>()->default_value(""))(
    "search", "Specify a search type, one of: binary, branchless_binary, linear, "
        "interpolation", cxxopts::value<std::string>()->default_value("binary"))(
    "csv", "Output a CSV of results in addition to a text file")(
    "suffix", "Suffix of the output CSV file", cxxopts::value<std::string>()->default_value(""));
  
  options.parse_positional({"data", "lookups", "positional"});
  const auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help({}) << "\n";
    exit(0);
  }

  const size_t num_repeats = result["repeats"].as<int>();
  cout << "Repeating lookup code " << num_repeats << " time(s)." << endl;

  const size_t num_threads = result["threads"].as<int>();
  cout << "Using " << num_threads << " thread(s)." << endl;
  
  const bool perf = result.count("perf");
  const bool build = result.count("build");
  const bool sep = result.count("sep");
  const bool tail = result.count("tail");
  const bool csv = result.count("csv");
  const std::string filename = result["data"].as<std::string>();
  const std::string csv_suffix = result["suffix"].as<std::string>();
  const std::string lookups = result["lookups"].as<std::string>();
  const std::string search_type = result["search"].as<std::string>();
  const bool only_mode = result.count("only") || std::getenv("SOSD_ONLY");
  const double sampling_ratio = result["sampling_ratio"].as<double>();
  const int perf_no = result["perf_option"].as<int>();
  std::string only;

  if (tail){
    cout << "Using " << sampling_ratio << " sampling ratio" << endl;
  }
  
  if (perf){
    std::string perf_name = "";

    if (perf_no == 0){
      perf_name = "LLC miss";
    } else if (perf_no == 1){
      perf_name = "TLB miss";
    } else if (perf_no == 2){    
      perf_name = "Branch miss";
    } else if (perf_no == 3){
      perf_name = "Instructions";
    }

    cout << "Using " << perf_name << " performance counter" << endl;
  }

  if (result.count("only")) {
    only = result["only"].as<std::string>();
  } else if (std::getenv("SOSD_ONLY")) {
    only = std::string(std::getenv("SOSD_ONLY"));
  } else {
    only = "";
  }

  const DataType type = util::resolve_type(filename);

  if (lookups.find("lookups") == std::string::npos) {
    cerr << "Warning: lookups file seems misnamed. Did you specify the right "
            "one?\n";
  }

  if (only_mode)
    cout << "Only executing indexes matching " << only << std::endl;

  // Pin main thread to core 0.
  util::set_cpu_affinity(0);
  bool found_search_type = false;

  switch (type) {
    case DataType::UINT32: {
      // Create benchmark.
      if constexpr (sosd_config::fast_mode) {
        util::fail("32-bit is not supported when SOSD is built with fast mode");
      } else {
        add_search_type("binary", execute_32_bit, uint32_t,
                        BranchingBinarySearch);
        add_search_type("branchless_binary", execute_32_bit, uint32_t,
                        BranchlessBinarySearch);
        add_search_type("linear", execute_32_bit, uint32_t, LinearSearch);
        add_search_type("interpolation", execute_32_bit, uint32_t,
                        InterpolationSearch);
      }
      break;
    }
    case DataType::UINT64: {
      // Create benchmark.
      if constexpr (sosd_config::fast_mode) {
        add_search_type("binary", execute_64_bit, uint64_t,
                        BranchingBinarySearch);
      } else {
        add_search_type("binary", execute_64_bit, uint64_t,
                        BranchingBinarySearch);
        add_search_type("branchless_binary", execute_64_bit, uint64_t,
                        BranchlessBinarySearch);
        add_search_type("linear", execute_64_bit, uint64_t, LinearSearch);
        add_search_type("interpolation", execute_64_bit, uint64_t,
                        InterpolationSearch);
      }
      break;
    }
  }

  if (!found_search_type) {
    std::cerr << "Specified search type is not implemented in this build. "
                 "Disable fast mode for other search types."
              << std::endl;
  }

  return 0;
}
