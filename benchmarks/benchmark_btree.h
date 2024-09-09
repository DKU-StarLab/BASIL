#pragma once
#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/wrapper_stx_btree.h"

template <template <typename> typename Searcher>
void benchmark_32_btree(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_btree(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<STXBTree<uint64_t, 1>>();
#endif
#ifdef PARETO_AVG // Section 5.4.1
  benchmark.template Run<STXBTree<uint64_t,1>>();
  benchmark.template Run<STXBTree<uint64_t,4>>();
  benchmark.template Run<STXBTree<uint64_t,16>>();
  benchmark.template Run<STXBTree<uint64_t,64>>();
  benchmark.template Run<STXBTree<uint64_t,256>>();
  benchmark.template Run<STXBTree<uint64_t,1024>>();
  benchmark.template Run<STXBTree<uint64_t,4096>>();
  benchmark.template Run<STXBTree<uint64_t,16384>>();
  benchmark.template Run<STXBTree<uint64_t,65536>>();
  benchmark.template Run<STXBTree<uint64_t,262144>>();
  benchmark.template Run<STXBTree<uint64_t,1048576>>();
#endif
#ifdef PARETO_TAIL // Section 5.4.2
  benchmark.template Run<STXBTree<uint64_t,1>>();
  benchmark.template Run<STXBTree<uint64_t,4>>();
  benchmark.template Run<STXBTree<uint64_t,16>>();
  benchmark.template Run<STXBTree<uint64_t,64>>();
  benchmark.template Run<STXBTree<uint64_t,256>>();
  benchmark.template Run<STXBTree<uint64_t,1024>>();
  benchmark.template Run<STXBTree<uint64_t,4096>>();
  benchmark.template Run<STXBTree<uint64_t,16384>>();
  benchmark.template Run<STXBTree<uint64_t,65536>>();
  benchmark.template Run<STXBTree<uint64_t,262144>>();
  benchmark.template Run<STXBTree<uint64_t,1048576>>();
#endif  
}
INSTANTIATE_TEMPLATES(benchmark_32_btree, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_btree, uint64_t);
