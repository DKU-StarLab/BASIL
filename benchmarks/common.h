#include "config.h"
#include "searches/branching_binary_search.h"
#include "searches/branchless_binary_search.h"
#include "searches/interpolation_search.h"
#include "searches/linear_search.h"

#ifdef FAST_MODE
#define INSTANTIATE_TEMPLATES(func_name, type_name) \
  template void func_name<BranchingBinarySearch>(   \
      sosd::Benchmark<type_name, BranchingBinarySearch>&)
#else
#define INSTANTIATE_TEMPLATES(func_name, type_name)         \
  template void func_name<LinearSearch>(                    \
      sosd::Benchmark<type_name, LinearSearch>&);           \
  template void func_name<BranchingBinarySearch>(           \
      sosd::Benchmark<type_name, BranchingBinarySearch>&);  \
  template void func_name<BranchlessBinarySearch>(          \
      sosd::Benchmark<type_name, BranchlessBinarySearch>&); \
  template void func_name<InterpolationSearch>(             \
      sosd::Benchmark<type_name, InterpolationSearch>&)
#endif

#ifdef FAST_MODE
#define INSTANTIATE_TEMPLATES_RMI(func_name, type_name) \
  template void func_name<BranchingBinarySearch>(       \
      sosd::Benchmark<type_name, BranchingBinarySearch>&, const std::string&)
#else
#define INSTANTIATE_TEMPLATES_RMI(func_name, type_name)                        \
  template void func_name<LinearSearch>(                                       \
      sosd::Benchmark<type_name, LinearSearch>&, const std::string&);          \
  template void func_name<BranchingBinarySearch>(                              \
      sosd::Benchmark<type_name, BranchingBinarySearch>&, const std::string&); \
  template void func_name<BranchlessBinarySearch>(                             \
      sosd::Benchmark<type_name, BranchlessBinarySearch>&,                     \
      const std::string&);                                                     \
  template void func_name<InterpolationSearch>(                                \
      sosd::Benchmark<type_name, InterpolationSearch>&, const std::string&)
#endif
