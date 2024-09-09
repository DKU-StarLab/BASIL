#! /usr/bin/env bash

function build_project() {
    set -e
    echo "Compiling $2 benchmark ..."

    mkdir -p build
    cd build
    
    cmake $1 -DCMAKE_BUILD_TYPE=Release ..
    make -j 16
    
    cd ..
}

function build_project_after_cleaning() {
    set -e
    echo "Compiling $2 benchmark ..."

    mkdir -p build
    cd build

    rm -rf CMakeCache.txt CMakeFiles/
    
    cmake $1 -DCMAKE_BUILD_TYPE=Release ..
    make -j 16
    
    cd ..
}

function do_benchmark() {
    mkdir -p ./results

    BENCHMARK=build/benchmark

    if [ ! -f $BENCHMARK ]; then
        echo "benchmark binary does not exist"
        exit
    fi
    
    echo "Executing workload $1 and printing to CSV"
    $BENCHMARK ./data/$1 ./data/$1_equality_lookups_10M --csv $2
}
