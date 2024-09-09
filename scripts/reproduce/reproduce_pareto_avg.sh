#! /usr/bin/env bash

source ./scripts/common.sh

# Make
build_project_after_cleaning "-DPARETO_AVG=ON" "pareto average latency ($.5.4.1)"

# Execute
for dataset in $(cat ./scripts/reproduce/datasets_pareto.txt); do
    do_benchmark "$dataset" "--suffix pareto" || true
done

build_project_after_cleaning "-DPARETO_AVG_STACK=ON" "pareto average latency ($.5.4.1)"
do_benchmark "stack_200M_uint64" "--suffix pareto" || true

build_project_after_cleaning "-DPARETO_AVG_COVID=ON" "pareto average latency ($.5.4.1)"
do_benchmark "covid_200M_uint64" "--suffix pareto" || true

build_project_after_cleaning "-DPARETO_AVG_HISTORY=ON" "pareto average latency ($.5.4.1)"
do_benchmark "history_200M_uint64" "--suffix pareto" || true

build_project_after_cleaning "-DPARETO_AVG_BOOKS=ON" "pareto average latency ($.5.4.1)"
do_benchmark "books_200M_uint64" "--suffix pareto" || true

build_project_after_cleaning "-DPARETO_AVG_OSM=ON" "pareto average latency ($.5.4.1)"
do_benchmark "osm_200M_uint64" "--suffix pareto" || true

build_project_after_cleaning "-DPARETO_AVG_GENOME=ON" "pareto average latency ($.5.4.1)"
do_benchmark "genome_200M_uint64" "--suffix pareto" || true