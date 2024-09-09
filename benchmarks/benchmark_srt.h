#pragma once

#include "benchmark.h"
#include "benchmarks/common.h"
#include "wrappers/wrapper_srt.h"

template <template <typename> typename Searcher>
void benchmark_32_srt(sosd::Benchmark<uint32_t, Searcher>& benchmark) {}

template <template <typename> typename Searcher>
void benchmark_64_srt(sosd::Benchmark<uint64_t, Searcher>& benchmark) {
/**
 * The following configurations are used in the paper and are intended for reproduce experiments.
 * Since BASIL, like SOSD, uses hard-coded configurations, #ifdef and #endif are employed to reduce
 * benchmark build times. If you wish to use a different configuration, please declare it outside 
 * the #ifdef and #endif blocks and use it without additional compile macro options.
*/
#ifdef USER
    benchmark.template Run<sRadixTable<uint64_t, 10, 1>>();
#endif
#ifdef PARETO_AVG_STACK // Section 5.4.1
    benchmark.template Run<sRadixTable<uint64_t, 8, 4194304>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 4>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
#endif
#ifdef PARETO_AVG_COVID // Section 5.4.1
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 4>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_AVG_HISTORY // Section 5.4.1
    benchmark.template Run<sRadixTable<uint64_t, 10, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 4>>();
    benchmark.template Run<sRadixTable<uint64_t, 28, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
#endif
#ifdef PARETO_AVG_BOOKS // Section 5.4.1
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_AVG_OSM // Section 5.4.1
    benchmark.template Run<sRadixTable<uint64_t, 4, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 4, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 4096>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 28, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_AVG_GENOME // Section 5.4.1
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_TAIL_STACK // Section 5.4.2
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 4096>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 4>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_TAIL_COVID // Section 5.4.2
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 4>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_TAIL_HISTORY // Section 5.4.2
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 12, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 28, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
#endif
#ifdef PARETO_TAIL_BOOKS // Section 5.4.2
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 28, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_TAIL_OSM // Section 5.4.2
    benchmark.template Run<sRadixTable<uint64_t, 4, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 4, 262144>>();
    benchmark.template Run<sRadixTable<uint64_t, 6, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 8, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 4096>>();
    benchmark.template Run<sRadixTable<uint64_t, 24, 256>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 28, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 1>>();
    benchmark.template Run<sRadixTable<uint64_t, 34, 1>>();
#endif
#ifdef PARETO_TAIL_GENOME // Section 5.4.2
    benchmark.template Run<sRadixTable<uint64_t, 4, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 2, 1048576>>();
    benchmark.template Run<sRadixTable<uint64_t, 14, 65536>>();
    benchmark.template Run<sRadixTable<uint64_t, 16, 16384>>();
    benchmark.template Run<sRadixTable<uint64_t, 18, 4096>>();
    benchmark.template Run<sRadixTable<uint64_t, 20, 1024>>();
    benchmark.template Run<sRadixTable<uint64_t, 22, 64>>();
    benchmark.template Run<sRadixTable<uint64_t, 26, 16>>();
    benchmark.template Run<sRadixTable<uint64_t, 30, 4>>();
    benchmark.template Run<sRadixTable<uint64_t, 32, 1>>();
#endif
}

INSTANTIATE_TEMPLATES(benchmark_32_srt, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_srt, uint64_t);
