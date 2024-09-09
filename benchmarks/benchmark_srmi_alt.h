#pragma once

#include "benchmark.h"
#include "benchmarks/common.h"
#include "indexes/analysis-srmi/include/srmi/models.hpp"
#include "indexes/analysis-srmi/include/srmi/srmi_robust.hpp"
#include "wrappers/wrapper_srmi_cpp_robust.h"

template <template <typename> typename Searcher>
void benchmark_32_srmi_cpp(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_srmi_cpp(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 1>>();
#endif
#ifdef PERF // Section 5.1
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 1024, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 16384, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 262144, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 4194304, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::sRmiRobust, 67108864, 0, 1, 65536>>();
#endif
#ifdef SPEEDUP // Section 5.2
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 1048576>>();
#endif
#ifdef DESIGNSPACE // Section 5.3
benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1024, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4096, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16384, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 65536, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 262144, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 1048576, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 4194304, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 16777216, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 67108864, 0, 1, 1048576>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 1>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 2>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 4>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 8>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 16>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 32>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 64>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 128>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 256>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 512>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 1024>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 2048>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 4096>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 8192>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 16384>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 32768>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 65536>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 131072>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 262144>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 524288>>();
  benchmark.template Run<
      sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                    srmi::sRmiRobust, 268435456, 0, 1, 1048576>>();
#endif
#ifdef PARETO_AVG_STACK // Section 5.4.1
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 16>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 1>>();
#endif
#ifdef PARETO_AVG_COVID // Section 5.4.1
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 16>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 1>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
#endif
#ifdef PARETO_AVG_HISTORY // Section 5.4.1
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 16>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 1>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
#endif
#ifdef PARETO_AVG_BOOKS // Section 5.4.1
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 16>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 1>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
#endif
#ifdef PARETO_AVG_OSM // Section 5.4.1
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16384, 0, 1, 65536>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 65536, 0, 1, 16384>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 262144, 0, 1, 4096>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4194304, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16777216, 0, 1, 256>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 67108864, 0, 1, 64>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 67108864, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 268435456, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4294967296, 0, 1, 1>>();
#endif
#ifdef PARETO_AVG_GENOME // Section 5.4.1
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 256, 0, 1, 262144>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 67108864, 0, 1, 4>>();
    benchmark.template Run<
                        sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                    srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
#endif
#ifdef PARETO_TAIL_STACK // Section 5.4.2
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 16>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 1>>();
#endif
#ifdef PARETO_TAIL_COVID // Section 5.4.2
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 1>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 67108864, 0, 1, 1>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4294967296, 0, 1, 1>>();
#endif
#ifdef PARETO_TAIL_HISTORY // Section 5.4.2
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1024, 0, 1, 65536>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 16>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4194304, 0, 1, 1>>();
#endif
#ifdef PARETO_TAIL_BOOKS // Section 5.4.2
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 256, 0, 1, 65536>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1024, 0, 1, 16384>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4096, 0, 1, 4096>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 65536, 0, 1, 256>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 64>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16777216, 0, 1, 4>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 67108864, 0, 1, 1>>();
#endif
#ifdef PARETO_TAIL_OSM // Section 5.4.2
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 262144>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 65536, 0, 1, 65536>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 262144, 0, 1, 16384>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1048576, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4194304, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16777216, 0, 1, 256>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 67108864, 0, 1, 64>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 268435456, 0, 1, 1>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4294967296, 0, 1, 1>>();
#endif
#ifdef PARETO_TAIL_GENOME // Section 5.4.2
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 256, 0, 1, 262144>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 65536>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 4096, 0, 1, 16384>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16384, 0, 1, 4096>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 65536, 0, 1, 1024>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 262144, 0, 1, 256>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 16777216, 0, 1, 64>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 67108864, 0, 1, 16>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 268435456, 0, 1, 1>>();
    benchmark.template Run<
                            sRMICppRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                                        srmi::sRmiRobust, 1073741824, 0, 1, 1>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_srmi_cpp, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_srmi_cpp, uint64_t);
