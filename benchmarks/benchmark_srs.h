#pragma once
#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/wrapper_srs.h"

template <template <typename> typename Searcher>
void benchmark_32_srs(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_srs(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER 
  benchmark.template Run<sRS<uint64_t, 18, 16, 1>>();
#endif
#ifdef PERF // Section 5.1
  benchmark.template Run<sRS<uint64_t, 18, 4, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 16, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 13, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 64, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 61, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 49, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 256, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 253, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 241, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 193, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 1024, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 1021, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 1009, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 961, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 769, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 4096, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 4093, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 4081, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 4033, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 3841, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 3073, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 16384, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 16381, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 16369, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 16321, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 16129, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 15361, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 12289, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t, 18, 65536, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 65533, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 65521, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 65473, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 65281, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 64513, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 61441, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 49153, 16384>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 65536>>();
#endif
#ifdef SPEEDUP // Section 5.2
  benchmark.template Run<sRS<uint64_t, 18, 4, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 3, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 16, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 15, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 13, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 9, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 64, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 63, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 61, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 57, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 49, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 33, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 256, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 255, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 253, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 249, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 241, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 225, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 193, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 129, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 1024, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 1023, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 1021, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 1017, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 1009, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 993, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 961, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 897, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 769, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 513, 512>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 4096, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 4095, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 4093, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 4089, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 4081, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 4065, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 4033, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 3969, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 3841, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 3585, 512>>();
  benchmark.template Run<sRS<uint64_t, 18, 3073, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 2049, 2048>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 16384, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 16383, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 16381, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 16377, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 16369, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 16353, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 16321, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 16257, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 16129, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 15873, 512>>();
  benchmark.template Run<sRS<uint64_t, 18, 15361, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 14337, 2048>>();
  benchmark.template Run<sRS<uint64_t, 18, 12289, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 8193, 8192>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t, 18, 65536, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 65535, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 65533, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 65529, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 65521, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 65505, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 65473, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 65409, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 65281, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 65025, 512>>();
  benchmark.template Run<sRS<uint64_t, 18, 64513, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 63489, 2048>>();
  benchmark.template Run<sRS<uint64_t, 18, 61441, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 57345, 8192>>();
  benchmark.template Run<sRS<uint64_t, 18, 49153, 16384>>();
  benchmark.template Run<sRS<uint64_t, 18, 32769, 32768>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t, 18, 262144, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 262143, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 262141, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 262137, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 262129, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 262113, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 262081, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 262017, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 261889, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 261633, 512>>();
  benchmark.template Run<sRS<uint64_t, 18, 261121, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 260097, 2048>>();
  benchmark.template Run<sRS<uint64_t, 18, 258049, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 253953, 8192>>();
  benchmark.template Run<sRS<uint64_t, 18, 245761, 16384>>();
  benchmark.template Run<sRS<uint64_t, 18, 229377, 32768>>();
  benchmark.template Run<sRS<uint64_t, 18, 196609, 65536>>();
  benchmark.template Run<sRS<uint64_t, 18, 131073, 131072>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048576, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048575, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048573, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048569, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048561, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048545, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048513, 64>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048449, 128>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048321, 256>>();
  benchmark.template Run<sRS<uint64_t, 18, 1048065, 512>>();
  benchmark.template Run<sRS<uint64_t, 18, 1047553, 1024>>();
  benchmark.template Run<sRS<uint64_t, 18, 1046529, 2048>>();
  benchmark.template Run<sRS<uint64_t, 18, 1044481, 4096>>();
  benchmark.template Run<sRS<uint64_t, 18, 1040385, 8192>>();
  benchmark.template Run<sRS<uint64_t, 18, 1032193, 16384>>();
  benchmark.template Run<sRS<uint64_t, 18, 1015809, 32768>>();
  benchmark.template Run<sRS<uint64_t, 18, 983041, 65536>>();
  benchmark.template Run<sRS<uint64_t, 18, 917505, 131072>>();
  benchmark.template Run<sRS<uint64_t, 18, 786433, 262144>>();
  benchmark.template Run<sRS<uint64_t, 18, 524289, 524288>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 1048576>>();
#endif
#ifdef DESIGNSPACE // Section 5.3
  benchmark.template Run<sRS<uint64_t, 22, 4, 1>>();
  benchmark.template Run<sRS<uint64_t, 22, 3, 2>>();
  benchmark.template Run<sRS<uint64_t, 22, 1, 4>>();
  benchmark.template Run<sRS<uint64_t, 20, 16, 1>>();
  benchmark.template Run<sRS<uint64_t, 20, 15, 2>>();
  benchmark.template Run<sRS<uint64_t, 20, 13, 4>>();
  benchmark.template Run<sRS<uint64_t, 20, 9, 8>>();
  benchmark.template Run<sRS<uint64_t, 20, 1, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 64, 1>>();
  benchmark.template Run<sRS<uint64_t, 18, 63, 2>>();
  benchmark.template Run<sRS<uint64_t, 18, 61, 4>>();
  benchmark.template Run<sRS<uint64_t, 18, 57, 8>>();
  benchmark.template Run<sRS<uint64_t, 18, 49, 16>>();
  benchmark.template Run<sRS<uint64_t, 18, 33, 32>>();
  benchmark.template Run<sRS<uint64_t, 18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t, 16, 256, 1>>();
  benchmark.template Run<sRS<uint64_t, 16, 255, 2>>();
  benchmark.template Run<sRS<uint64_t, 16, 253, 4>>();
  benchmark.template Run<sRS<uint64_t, 16, 249, 8>>();
  benchmark.template Run<sRS<uint64_t, 16, 241, 16>>();
  benchmark.template Run<sRS<uint64_t, 16, 225, 32>>();
  benchmark.template Run<sRS<uint64_t, 16, 193, 64>>();
  benchmark.template Run<sRS<uint64_t, 16, 129, 128>>();
  benchmark.template Run<sRS<uint64_t, 16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t, 14, 1024, 1>>();
  benchmark.template Run<sRS<uint64_t, 14, 1023, 2>>();
  benchmark.template Run<sRS<uint64_t, 14, 1021, 4>>();
  benchmark.template Run<sRS<uint64_t, 14, 1017, 8>>();
  benchmark.template Run<sRS<uint64_t, 14, 1009, 16>>();
  benchmark.template Run<sRS<uint64_t, 14, 993, 32>>();
  benchmark.template Run<sRS<uint64_t, 14, 961, 64>>();
  benchmark.template Run<sRS<uint64_t, 14, 897, 128>>();
  benchmark.template Run<sRS<uint64_t, 14, 769, 256>>();
  benchmark.template Run<sRS<uint64_t, 14, 513, 512>>();
  benchmark.template Run<sRS<uint64_t, 14, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t, 12, 4096, 1>>();
  benchmark.template Run<sRS<uint64_t, 12, 4095, 2>>();
  benchmark.template Run<sRS<uint64_t, 12, 4093, 4>>();
  benchmark.template Run<sRS<uint64_t, 12, 4089, 8>>();
  benchmark.template Run<sRS<uint64_t, 12, 4081, 16>>();
  benchmark.template Run<sRS<uint64_t, 12, 4065, 32>>();
  benchmark.template Run<sRS<uint64_t, 12, 4033, 64>>();
  benchmark.template Run<sRS<uint64_t, 12, 3969, 128>>();
  benchmark.template Run<sRS<uint64_t, 12, 3841, 256>>();
  benchmark.template Run<sRS<uint64_t, 12, 3585, 512>>();
  benchmark.template Run<sRS<uint64_t, 12, 3073, 1024>>();
  benchmark.template Run<sRS<uint64_t, 12, 2049, 2048>>();
  benchmark.template Run<sRS<uint64_t, 12, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t, 10, 16384, 1>>();
  benchmark.template Run<sRS<uint64_t, 10, 16383, 2>>();
  benchmark.template Run<sRS<uint64_t, 10, 16381, 4>>();
  benchmark.template Run<sRS<uint64_t, 10, 16377, 8>>();
  benchmark.template Run<sRS<uint64_t, 10, 16369, 16>>();
  benchmark.template Run<sRS<uint64_t, 10, 16353, 32>>();
  benchmark.template Run<sRS<uint64_t, 10, 16321, 64>>();
  benchmark.template Run<sRS<uint64_t, 10, 16257, 128>>();
  benchmark.template Run<sRS<uint64_t, 10, 16129, 256>>();
  benchmark.template Run<sRS<uint64_t, 10, 15873, 512>>();
  benchmark.template Run<sRS<uint64_t, 10, 15361, 1024>>();
  benchmark.template Run<sRS<uint64_t, 10, 14337, 2048>>();
  benchmark.template Run<sRS<uint64_t, 10, 12289, 4096>>();
  benchmark.template Run<sRS<uint64_t, 10, 8193, 8192>>();
  benchmark.template Run<sRS<uint64_t, 10, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t, 8, 65536, 1>>();
  benchmark.template Run<sRS<uint64_t, 8, 65535, 2>>();
  benchmark.template Run<sRS<uint64_t, 8, 65533, 4>>();
  benchmark.template Run<sRS<uint64_t, 8, 65529, 8>>();
  benchmark.template Run<sRS<uint64_t, 8, 65521, 16>>();
  benchmark.template Run<sRS<uint64_t, 8, 65505, 32>>();
  benchmark.template Run<sRS<uint64_t, 8, 65473, 64>>();
  benchmark.template Run<sRS<uint64_t, 8, 65409, 128>>();
  benchmark.template Run<sRS<uint64_t, 8, 65281, 256>>();
  benchmark.template Run<sRS<uint64_t, 8, 65025, 512>>();
  benchmark.template Run<sRS<uint64_t, 8, 64513, 1024>>();
  benchmark.template Run<sRS<uint64_t, 8, 63489, 2048>>();
  benchmark.template Run<sRS<uint64_t, 8, 61441, 4096>>();
  benchmark.template Run<sRS<uint64_t, 8, 57345, 8192>>();
  benchmark.template Run<sRS<uint64_t, 8, 49153, 16384>>();
  benchmark.template Run<sRS<uint64_t, 8, 32769, 32768>>();
  benchmark.template Run<sRS<uint64_t, 8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t, 6, 262144, 1>>();
  benchmark.template Run<sRS<uint64_t, 6, 262143, 2>>();
  benchmark.template Run<sRS<uint64_t, 6, 262141, 4>>();
  benchmark.template Run<sRS<uint64_t, 6, 262137, 8>>();
  benchmark.template Run<sRS<uint64_t, 6, 262129, 16>>();
  benchmark.template Run<sRS<uint64_t, 6, 262113, 32>>();
  benchmark.template Run<sRS<uint64_t, 6, 262081, 64>>();
  benchmark.template Run<sRS<uint64_t, 6, 262017, 128>>();
  benchmark.template Run<sRS<uint64_t, 6, 261889, 256>>();
  benchmark.template Run<sRS<uint64_t, 6, 261633, 512>>();
  benchmark.template Run<sRS<uint64_t, 6, 261121, 1024>>();
  benchmark.template Run<sRS<uint64_t, 6, 260097, 2048>>();
  benchmark.template Run<sRS<uint64_t, 6, 258049, 4096>>();
  benchmark.template Run<sRS<uint64_t, 6, 253953, 8192>>();
  benchmark.template Run<sRS<uint64_t, 6, 245761, 16384>>();
  benchmark.template Run<sRS<uint64_t, 6, 229377, 32768>>();
  benchmark.template Run<sRS<uint64_t, 6, 196609, 65536>>();
  benchmark.template Run<sRS<uint64_t, 6, 131073, 131072>>();
  benchmark.template Run<sRS<uint64_t, 6, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048576, 1>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048575, 2>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048573, 4>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048569, 8>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048561, 16>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048545, 32>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048513, 64>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048449, 128>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048321, 256>>();
  benchmark.template Run<sRS<uint64_t, 4, 1048065, 512>>();
  benchmark.template Run<sRS<uint64_t, 4, 1047553, 1024>>();
  benchmark.template Run<sRS<uint64_t, 4, 1046529, 2048>>();
  benchmark.template Run<sRS<uint64_t, 4, 1044481, 4096>>();
  benchmark.template Run<sRS<uint64_t, 4, 1040385, 8192>>();
  benchmark.template Run<sRS<uint64_t, 4, 1032193, 16384>>();
  benchmark.template Run<sRS<uint64_t, 4, 1015809, 32768>>();
  benchmark.template Run<sRS<uint64_t, 4, 983041, 65536>>();
  benchmark.template Run<sRS<uint64_t, 4, 917505, 131072>>();
  benchmark.template Run<sRS<uint64_t, 4, 786433, 262144>>();
  benchmark.template Run<sRS<uint64_t, 4, 524289, 524288>>();
  benchmark.template Run<sRS<uint64_t, 4, 1, 1048576>>();
#endif
#ifdef PARETO_AVG_STACK // Section 5.4.1
  benchmark.template Run<sRS<uint64_t,8, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,14, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,18, 4, 16>>();
  benchmark.template Run<sRS<uint64_t,22, 4, 4>>();
  benchmark.template Run<sRS<uint64_t,20, 4, 1>>();
#endif
#ifdef PARETO_AVG_COVID // Section 5.4.1
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,18, 8, 16>>();
  benchmark.template Run<sRS<uint64_t,20, 8, 4>>();
  benchmark.template Run<sRS<uint64_t,22, 4, 1>>();
  benchmark.template Run<sRS<uint64_t,30, 1, 1>>();
#endif
#ifdef PARETO_AVG_HISTORY // Section 5.4.1
  benchmark.template Run<sRS<uint64_t,8, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,20, 8, 4>>();
  benchmark.template Run<sRS<uint64_t,20, 8, 1>>();
  benchmark.template Run<sRS<uint64_t,30, 1, 1>>();
#endif
#ifdef PARETO_AVG_BOOKS // Section 5.4.1
  benchmark.template Run<sRS<uint64_t,8, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,20, 16, 4>>();
  benchmark.template Run<sRS<uint64_t,28, 1, 4>>();
  benchmark.template Run<sRS<uint64_t,30, 1, 1>>();
#endif
#ifdef PARETO_AVG_OSM // Section 5.4.1
  benchmark.template Run<sRS<uint64_t,8, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,20, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,22, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,24, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,24, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,28, 16, 4>>();
  benchmark.template Run<sRS<uint64_t,32, 2, 1>>();
#endif
#ifdef PARETO_AVG_GENOME // Section 5.4.1
  benchmark.template Run<sRS<uint64_t,10, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,20, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,20, 8, 4>>();
  benchmark.template Run<sRS<uint64_t,22, 4, 1>>();
  benchmark.template Run<sRS<uint64_t,32, 2, 1>>();
#endif
#ifdef PARETO_TAIL_STACK // Section 5.4.2
  benchmark.template Run<sRS<uint64_t,6, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,14, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,16, 4, 16>>();
  benchmark.template Run<sRS<uint64_t,20, 4, 1>>();
#endif
#ifdef PARETO_TAIL_COVID // Section 5.4.2
  benchmark.template Run<sRS<uint64_t,6, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,14, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,20, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,16, 16, 16>>();
  benchmark.template Run<sRS<uint64_t,16, 16, 4>>();
  benchmark.template Run<sRS<uint64_t,16, 16, 1>>();
  benchmark.template Run<sRS<uint64_t,22, 4, 1>>();
#endif
#ifdef PARETO_TAIL_HISTORY // Section 5.4.2
  benchmark.template Run<sRS<uint64_t,8, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,8, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,18, 16, 16>>();
  benchmark.template Run<sRS<uint64_t,16, 16, 4>>();
  benchmark.template Run<sRS<uint64_t,18, 16, 1>>();
#endif
#ifdef PARETO_TAIL_BOOKS // Section 5.4.2
  benchmark.template Run<sRS<uint64_t,6, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,10, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,14, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,20, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,20, 16, 4>>();
  benchmark.template Run<sRS<uint64_t,24, 8, 1>>();
#endif
#ifdef PARETO_TAIL_OSM // Section 5.4.2
  benchmark.template Run<sRS<uint64_t,6, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,20, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,22, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,24, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,26, 16, 1>>();
  benchmark.template Run<sRS<uint64_t,32, 4, 1>>();
#endif
#ifdef PARETO_TAIL_GENOME // Section 5.4.2
  benchmark.template Run<sRS<uint64_t,10, 1, 262144>>();
  benchmark.template Run<sRS<uint64_t,12, 1, 65536>>();
  benchmark.template Run<sRS<uint64_t,14, 1, 16384>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 4096>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 1024>>();
  benchmark.template Run<sRS<uint64_t,16, 1, 256>>();
  benchmark.template Run<sRS<uint64_t,18, 1, 64>>();
  benchmark.template Run<sRS<uint64_t,18, 64, 1>>();
  benchmark.template Run<sRS<uint64_t,22, 4, 1>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_srs, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_srs, uint64_t);
