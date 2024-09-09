#! /usr/bin/env bash

source ./scripts/common.sh

# Make
build_project_after_cleaning "-DMETA=ON" "sampling impact ($.5.1)"

# Execute
echo "Executing sampling impact ($.5.1) and saving results..."

for dataset in $(cat ./scripts/reproduce/datasets_meta.txt); do
    do_benchmark "$dataset" "--sep --suffix meta" || true
done

build_project_after_cleaning "-DPERF=ON" "sampling impact ($.5.1)"

for dataset in $(cat ./scripts/reproduce/datasets_meta.txt); do
    do_benchmark "$dataset" "--perf --search binary -o 0 --suffix perf" || true
    do_benchmark "$dataset" "--perf --search binary -o 1 --suffix perf --only sRMI_CPP" || true
    do_benchmark "$dataset" "--perf --search binary -o 2 --suffix perf --only sRMI_CPP" || true
    do_benchmark "$dataset" "--perf --search binary -o 2 --suffix perf --only sCHT" || true
    do_benchmark "$dataset" "--perf --search binary -o 3 --suffix perf --only sRMI_CPP" || true
done