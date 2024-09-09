cmake_minimum_required(VERSION 3.10)
project(SOSD)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

option(USER "Enable USER macro" OFF)
option(META "Enable META macro" OFF)
option(PERF "Enable PERF macro" OFF)
option(SPEEDUP "Enable SPEEDUP macro" OFF)
option(DESIGNSPACE "Enable DESIGNSPACE macro" OFF)
option(PARETO_AVG "Enable PARETO_AVG macro" OFF)
option(PARETO_AVG_STACK "Enable PARETO_AVG_STACK macro" OFF)
option(PARETO_AVG_COVID "Enable PARETO_AVG_COVID macro" OFF)
option(PARETO_AVG_HISTORY "Enable PARETO_AVG_HISTORY macro" OFF)
option(PARETO_AVG_BOOKS "Enable PARETO_AVG_BOOKS macro" OFF)
option(PARETO_AVG_OSM "Enable PARETO_AVG_OSM macro" OFF)
option(PARETO_AVG_GENOME "Enable PARETO_AVG_GENOME macro" OFF)

option(PARETO_TAIL "Enable PARETO_TAIL macro" OFF)
option(PARETO_TAIL_STACK "Enable PARETO_TAIL_STACK macro" OFF)
option(PARETO_TAIL_COVID "Enable PARETO_TAIL_COVID macro" OFF)
option(PARETO_TAIL_HISTORY "Enable PARETO_TAIL_HISTORY macro" OFF)
option(PARETO_TAIL_BOOKS "Enable PARETO_TAIL_BOOKS macro" OFF)
option(PARETO_TAIL_OSM "Enable PARETO_TAIL_OSM macro" OFF)
option(PARETO_TAIL_GENOME "Enable PARETO_TAIL_GENOME macro" OFF)

if(USER)
  add_compile_definitions(USER)
endif()

if(META)
  add_compile_definitions(META)
endif()

if(PERF)
  add_compile_definitions(PERF)
endif()

if(SPEEDUP)
  add_compile_definitions(SPEEDUP)
endif()

if(DESIGNSPACE)
  add_compile_definitions(DESIGNSPACE)
endif()

if(PARETO_AVG)
  add_compile_definitions(PARETO_AVG)
endif()

if(PARETO_AVG_STACK)
  add_compile_definitions(PARETO_AVG_STACK)
endif()

if(PARETO_AVG_COVID)
  add_compile_definitions(PARETO_AVG_COVID)
endif()

if(PARETO_AVG_HISTORY)
  add_compile_definitions(PARETO_AVG_HISTORY)
endif()

if(PARETO_AVG_BOOKS)
  add_compile_definitions(PARETO_AVG_BOOKS)
endif()

if(PARETO_AVG_OSM)
  add_compile_definitions(PARETO_AVG_OSM)
endif()

if(PARETO_AVG_GENOME)
  add_compile_definitions(PARETO_AVG_GENOME)
endif()

if(PARETO_TAIL)
  add_compile_definitions(PARETO_TAIL)
endif()

if(PARETO_TAIL_STACK)
  add_compile_definitions(PARETO_TAIL_STACK)
endif()

if(PARETO_TAIL_COVID)
  add_compile_definitions(PARETO_TAIL_COVID)
endif()

if(PARETO_TAIL_HISTORY)
  add_compile_definitions(PARETO_TAIL_HISTORY)
endif()

if(PARETO_TAIL_BOOKS)
  add_compile_definitions(PARETO_TAIL_BOOKS)
endif()

if(PARETO_TAIL_OSM)
  add_compile_definitions(PARETO_TAIL_OSM)
endif()

if(PARETO_TAIL_GENOME)
  add_compile_definitions(PARETO_TAIL_GENOME)
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math -Wall -Wfatal-errors -march=native")


# Enable OpenMP if available
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-fopenmp HAS_OPENMP)
if (HAS_OPENMP)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(dtl)

set(SOURCE_FILES util.h)
file(GLOB_RECURSE BENCH_SOURCES "benchmarks/*.h")

add_executable(generate generate.cc ${SOURCE_FILES})
target_link_libraries(generate Threads::Threads)

add_executable(benchmark benchmark.cc ${SOURCE_FILES})
target_include_directories(benchmark
        PRIVATE "indexes/srs/include"
        PRIVATE "indexes/sPGM-index/include"
        PRIVATE "indexes/sCHT/include"
        PRIVATE "indexes/anaylsis-srmi/include"
        PRIVATE "indexes/stx-btree-0.9/include"
        pgmindexlib)

target_link_libraries(benchmark
        PRIVATE Threads::Threads dtl
        PRIVATE dl)