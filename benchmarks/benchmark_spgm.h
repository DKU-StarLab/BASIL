#pragma once

#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/wrapper_spgm_index.h"

template <template <typename> typename Searcher>
void benchmark_32_spgm(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_spgm(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<sPGM<uint64_t, 16, 1, 4, 1>>();
#endif
#ifdef PERF // Section 5.1
  benchmark.template Run<sPGM<uint64_t, 4, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 13, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 64, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 61, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 49, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 256, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 253, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 241, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 193, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1024, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1021, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1009, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 961, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 769, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4096, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4093, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4081, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4033, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3841, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3073, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16384, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16381, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16369, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16321, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16129, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15361, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 12289, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65536, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65533, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65521, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65473, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65281, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 64513, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 61441, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 49153, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
#endif
#ifdef SPEEDUP // Section 5.2
  benchmark.template Run<sPGM<uint64_t, 4, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 13, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 9, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 64, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 63, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 61, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 57, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 49, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 33, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 256, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 255, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 253, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 249, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 241, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 225, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 193, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 129, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1024, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1023, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1021, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1017, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1009, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 993, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 961, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 897, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 769, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 513, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4096, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4095, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4093, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4089, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4081, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4065, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4033, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3969, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3841, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3585, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3073, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 2049, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16384, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16383, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16381, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16377, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16369, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16353, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16321, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16257, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16129, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15873, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15361, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 14337, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 12289, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8193, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65536, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65535, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65533, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65529, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65521, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65505, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65473, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65409, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65281, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65025, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 64513, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 63489, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 61441, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 57345, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 49153, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 32769, 32768, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262144, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262143, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262141, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262137, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262129, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262113, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262081, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262017, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 261889, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 261633, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 261121, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 260097, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 258049, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 253953, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 245761, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 229377, 32768, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 196609, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 131073, 131072, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048576, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048575, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048573, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048569, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048561, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048545, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048513, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048449, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048321, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048065, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1047553, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1046529, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1044481, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1040385, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1032193, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1015809, 32768, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 983041, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 917505, 131072, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 786433, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 524289, 524288, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1048576, 4, 1>>();
#endif
#ifdef DESIGNSPACE // Section 5.3
  benchmark.template Run<sPGM<uint64_t, 4, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 13, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 9, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 64, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 63, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 61, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 57, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 49, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 33, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 256, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 255, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 253, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 249, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 241, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 225, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 193, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 129, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1024, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1023, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1021, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1017, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1009, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 993, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 961, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 897, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 769, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 513, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4096, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4095, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4093, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4089, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4081, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4065, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4033, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3969, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3841, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3585, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 3073, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 2049, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16384, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16383, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16381, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16377, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16369, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16353, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16321, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16257, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16129, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15873, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 15361, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 14337, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 12289, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8193, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65536, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65535, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65533, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65529, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65521, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65505, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65473, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65409, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65281, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 65025, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 64513, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 63489, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 61441, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 57345, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 49153, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 32769, 32768, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262144, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262143, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262141, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262137, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262129, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262113, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262081, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 262017, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 261889, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 261633, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 261121, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 260097, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 258049, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 253953, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 245761, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 229377, 32768, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 196609, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 131073, 131072, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048576, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048575, 2, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048573, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048569, 8, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048561, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048545, 32, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048513, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048449, 128, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048321, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1048065, 512, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1047553, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1046529, 2048, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1044481, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1040385, 8192, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1032193, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1015809, 32768, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 983041, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 917505, 131072, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 786433, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 524289, 524288, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1048576, 4, 1>>();
#endif
#ifdef PARETO_AVG_STACK // Section 5.4.1
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 2, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 2, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 1, 16, 1>>();
#endif
#ifdef PARETO_AVG_COVID // Section 5.4.1
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 1, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1, 16, 1>>();
#endif
#ifdef PARETO_AVG_HISTORY // Section 5.4.1
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 1, 4, 1>>();
#endif
#ifdef PARETO_AVG_BOOKS // Section 5.4.1
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 1, 4, 1>>();
#endif
#ifdef PARETO_AVG_OSM // Section 5.4.1
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 1, 16, 1>>();
#endif
#ifdef PARETO_AVG_GENOME // Section 5.4.1
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 2, 1, 16, 1>>();
#endif
#ifdef PARETO_TAIL_STACK // Section 5.4.2
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 2, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 1, 16, 1>>();
#endif
#ifdef PARETO_TAIL_COVID // Section 5.4.2
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 1, 4, 1>>();
#endif
#ifdef PARETO_TAIL_HISTORY // Section 5.4.2
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 1, 16, 1>>();
#endif
#ifdef PARETO_TAIL_BOOKS // Section 5.4.2
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16384, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 1, 4, 1>>();
#endif
#ifdef PARETO_TAIL_OSM // Section 5.4.2
  benchmark.template Run<sPGM<uint64_t, 1, 1048576, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 8, 16, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 16, 4, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 1, 4, 1>>();
#endif
#ifdef PARETO_TAIL_GENOME // Section 5.4.2
  benchmark.template Run<sPGM<uint64_t, 1, 262144, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 65536, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4096, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 1024, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 256, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 64, 16, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 16, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 1, 4, 4, 1>>();
  benchmark.template Run<sPGM<uint64_t, 4, 1, 4, 1>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_spgm, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_spgm, uint64_t);
