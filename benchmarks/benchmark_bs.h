#pragma once
#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/wrapper_binary_search.h"

template <template <typename> typename Searcher>
void benchmark_64_bs(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<BinarySearch<uint64_t>>();
#endif
#ifdef PARETO_AVG // Section 5.4.1
  benchmark.template Run<BinarySearch<uint64_t>>();
#endif
#ifdef PARETO_TAIL // Section 5.4.2
  benchmark.template Run<BinarySearch<uint64_t>>();
#endif  
}

INSTANTIATE_TEMPLATES(benchmark_64_bs, uint64_t);