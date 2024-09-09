#pragma once
#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/meta/wrapper_meta_scht.h"

template <template <typename> typename Searcher>
void benchmark_32_scht_meta(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_scht_meta(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<msCHT<uint64_t, 1024, 127, 1>>();
#endif
#ifdef META // Section 5.1
  benchmark.template Run<msCHT<uint64_t, 1024, 131071, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 131068, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 131056, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 131008, 64>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 130816, 256>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 130048, 1024>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 126976, 4096>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 114688, 16384>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 65536, 65536>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 32767, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 32764, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 32752, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 32704, 64>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 32512, 256>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 31744, 1024>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 28672, 4096>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 16384, 16384>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 8191, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 8188, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 8176, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 8128, 64>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 7936, 256>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 7168, 1024>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 4096, 4096>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 2047, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 2044, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 2032, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 1984, 64>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 1792, 256>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 1024, 1024>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 511, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 508, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 496, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 448, 64>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 256, 256>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 127, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 124, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 112, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 64, 64>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 31, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 28, 4>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 16, 16>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 7, 1>>();
  benchmark.template Run<msCHT<uint64_t, 1024, 4, 4>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_scht_meta, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_scht_meta, uint64_t);
