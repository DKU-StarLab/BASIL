#! /usr/bin/env bash

source ./scripts/common.sh

# Make
build_project_after_cleaning "-DDESIGNSPACE=ON" "design space ($.5.3)"

# Execute
echo "Executing design space ($.5.3) and saving results..."

for dataset in $(cat ./scripts/reproduce/datasets_meta.txt); do
    do_benchmark "$dataset" "--suffix design_space" || true
done
