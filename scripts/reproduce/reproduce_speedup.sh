#! /usr/bin/env bash

source ./scripts/common.sh

# Make
build_project_after_cleaning "-DSPEEDUP=ON" "speedup ($.5.2)"

# Execute
echo "Executing speedup ($.5.2) benchmark and saving results..."

for dataset in $(cat ./scripts/reproduce/datasets_speedup.txt); do
    do_benchmark "$dataset" "--suffix speedup" || true
done