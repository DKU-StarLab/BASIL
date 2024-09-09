#pragma once

#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/meta/wrapper_meta_spgm_index.h"

template <template <typename> typename Searcher>
void benchmark_32_spgm_meta(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_spgm_meta(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<msPGM<uint64_t, 16, 1, 4, 1>>();
#endif
#ifdef META // Section 5.1
  benchmark.template Run<msPGM<uint64_t, 4, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 16, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 13, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 64, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 61, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 49, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 256, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 253, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 241, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 193, 64, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1024, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1021, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1009, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 961, 64, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 769, 256, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 4096, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 4093, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 4081, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 4033, 64, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 3841, 256, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 3073, 1024, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 16384, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 16381, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 16369, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 16321, 64, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 16129, 256, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 15361, 1024, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 12289, 4096, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 65536, 1, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 65533, 4, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 65521, 16, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 65473, 64, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 65281, 256, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 64513, 1024, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 61441, 4096, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 49153, 16384, 4, 1>>();
  benchmark.template Run<msPGM<uint64_t, 1, 65536, 4, 1>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_spgm_meta, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_spgm_meta, uint64_t);
