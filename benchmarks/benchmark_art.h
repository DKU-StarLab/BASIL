#pragma once
#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/wrapper_art_primary_lb.h"

template <template <typename> typename Searcher>
void benchmark_64_art(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<ARTPrimaryLB<1>>();
#endif
#ifdef PARETO_AVG // Section 5.4.1
  benchmark.template Run<ARTPrimaryLB<1>>();
  benchmark.template Run<ARTPrimaryLB<4>>();
  benchmark.template Run<ARTPrimaryLB<16>>();
  benchmark.template Run<ARTPrimaryLB<64>>();
  benchmark.template Run<ARTPrimaryLB<256>>();
  benchmark.template Run<ARTPrimaryLB<1024>>();
  benchmark.template Run<ARTPrimaryLB<4096>>();
  benchmark.template Run<ARTPrimaryLB<16384>>();
  benchmark.template Run<ARTPrimaryLB<65536>>();
  benchmark.template Run<ARTPrimaryLB<262144>>();
  benchmark.template Run<ARTPrimaryLB<1048576>>();
#endif
#ifdef PARETO_TAIL // Section 5.4.2
  benchmark.template Run<ARTPrimaryLB<1>>();
  benchmark.template Run<ARTPrimaryLB<4>>();
  benchmark.template Run<ARTPrimaryLB<16>>();
  benchmark.template Run<ARTPrimaryLB<64>>();
  benchmark.template Run<ARTPrimaryLB<256>>();
  benchmark.template Run<ARTPrimaryLB<1024>>();
  benchmark.template Run<ARTPrimaryLB<4096>>();
  benchmark.template Run<ARTPrimaryLB<16384>>();
  benchmark.template Run<ARTPrimaryLB<65536>>();
  benchmark.template Run<ARTPrimaryLB<262144>>();
  benchmark.template Run<ARTPrimaryLB<1048576>>();
#endif  
}

INSTANTIATE_TEMPLATES(benchmark_64_art, uint64_t);