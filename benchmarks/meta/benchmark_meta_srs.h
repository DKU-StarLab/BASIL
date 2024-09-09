#pragma once

#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/meta/wrapper_meta_srs.h"

template <template <typename> typename Searcher>
void benchmark_32_srs_meta(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_srs_meta(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<sRS<uint64_t, 18, 16, 1>>();
#endif
#ifdef META // Section 5.1
  benchmark.template Run<msRS<uint64_t, 18, 4, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 16, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 13, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 64, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 61, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 49, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 64>>();
  benchmark.template Run<msRS<uint64_t, 18, 256, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 253, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 241, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 193, 64>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 256>>();
  benchmark.template Run<msRS<uint64_t, 18, 1024, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 1021, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 1009, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 961, 64>>();
  benchmark.template Run<msRS<uint64_t, 18, 769, 256>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 1024>>();
  benchmark.template Run<msRS<uint64_t, 18, 4096, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 4093, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 4081, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 4033, 64>>();
  benchmark.template Run<msRS<uint64_t, 18, 3841, 256>>();
  benchmark.template Run<msRS<uint64_t, 18, 3073, 1024>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 4096>>();
  benchmark.template Run<msRS<uint64_t, 18, 16384, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 16381, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 16369, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 16321, 64>>();
  benchmark.template Run<msRS<uint64_t, 18, 16129, 256>>();
  benchmark.template Run<msRS<uint64_t, 18, 15361, 1024>>();
  benchmark.template Run<msRS<uint64_t, 18, 12289, 4096>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 16384>>();
  benchmark.template Run<msRS<uint64_t, 18, 65536, 1>>();
  benchmark.template Run<msRS<uint64_t, 18, 65533, 4>>();
  benchmark.template Run<msRS<uint64_t, 18, 65521, 16>>();
  benchmark.template Run<msRS<uint64_t, 18, 65473, 64>>();
  benchmark.template Run<msRS<uint64_t, 18, 65281, 256>>();
  benchmark.template Run<msRS<uint64_t, 18, 64513, 1024>>();
  benchmark.template Run<msRS<uint64_t, 18, 61441, 4096>>();
  benchmark.template Run<msRS<uint64_t, 18, 49153, 16384>>();
  benchmark.template Run<msRS<uint64_t, 18, 1, 65536>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_srs_meta, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_srs_meta, uint64_t);
