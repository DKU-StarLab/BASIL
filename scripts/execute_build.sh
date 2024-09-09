#! /usr/bin/env bash

source ./scripts/common.sh

echo "Executing build time benchmark and saving results..."

for dataset in $(cat scripts/datasets_run.txt); do
    do_benchmark "$dataset" "--build"
done