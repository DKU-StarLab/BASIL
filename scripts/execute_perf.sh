#! /usr/bin/env bash

source ./scripts/common.sh

echo "Executing perf benchmark and saving results..."

for dataset in $(cat scripts/datasets_run.txt); do
    do_benchmark "$dataset" "--perf --search binary -o 0"
    do_benchmark "$dataset" "--perf --search binary -o 1"
    do_benchmark "$dataset" "--perf --search binary -o 2"
    do_benchmark "$dataset" "--perf --search binary -o 3"
done
