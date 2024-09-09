#! /usr/bin/env bash

source ./scripts/common.sh

echo "Executing averge latency benchmark and saving results..."

for dataset in $(cat scripts/datasets_run.txt); do
    do_benchmark "$dataset"
done
