#pragma once

#include "benchmark.h"
#include "benchmarks/common.h"
#include "indexes/analysis-srmi/include/srmi/models.hpp"
#include "indexes/analysis-srmi/include/srmi/srmi_robust_meta.hpp"
#include "wrappers/meta/wrapper_meta_srmi_cpp_robust.h"

template <template <typename> typename Searcher>
void benchmark_32_srmi_cpp_meta(
    sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_srmi_cpp_meta(
    sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 1>>();
#endif
#ifdef META // Section 5.1
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 1>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 4>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 16>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 64>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 256>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 1024>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 4096>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 16384>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 1024, 0, 1, 65536>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 1>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 4>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 16>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 64>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 256>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 1024>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 4096>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 16384>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 16384, 0, 1, 65536>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 1>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 4>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 16>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 64>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 256>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 1024>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 4096>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 16384>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 262144, 0, 1, 65536>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 1>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 4>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 16>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 64>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 256>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 1024>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 4096>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 16384>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 4194304, 0, 1, 65536>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 1>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 4>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 16>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 64>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 256>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 1024>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 4096>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 16384>>();
  benchmark.template Run<
      msRMIRobust<uint64_t, srmi::LinearSpline, srmi::LinearRegression,
                  srmi::msRmiRobust, 67108864, 0, 1, 65536>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_srmi_cpp_meta, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_srmi_cpp_meta, uint64_t);
