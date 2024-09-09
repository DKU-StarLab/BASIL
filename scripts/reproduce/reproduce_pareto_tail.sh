#! /usr/bin/env bash

source ./scripts/common.sh

# Make
build_project_after_cleaning "-DPARETO_TAIL=ON" "pareto tail latency ($.5.4.2)"

# Execute
for dataset in $(cat ./scripts/reproduce/datasets_pareto.txt); do
    do_benchmark "$dataset" "--tail --suffix pareto" || true
done

build_project_after_cleaning "-DPARETO_TAIL_STACK=ON" "pareto tail latency ($.5.4.2)"
do_benchmark "stack_200M_uint64" "--tail --suffix pareto" || true

build_project_after_cleaning "-DPARETO_TAIL_COVID=ON" "pareto tail latency ($.5.4.2)"
do_benchmark "covid_200M_uint64" "--tail --suffix pareto" || true

build_project_after_cleaning "-DPARETO_TAIL_HISTORY=ON" "pareto tail latency ($.5.4.2)"
do_benchmark "history_200M_uint64" "--tail --suffix pareto" || true

build_project_after_cleaning "-DPARETO_TAIL_BOOKS=ON" "pareto tail latency ($.5.4.2)"
do_benchmark "books_200M_uint64" "--tail --suffix pareto" || true

build_project_after_cleaning "-DPARETO_TAIL_OSM=ON" "pareto tail latency ($.5.4.2)"
do_benchmark "osm_200M_uint64" "--tail --suffix pareto" || true

build_project_after_cleaning "-DPARETO_TAIL_GENOME=ON" "pareto tail latency ($.5.4.2)"
do_benchmark "genome_200M_uint64" "--tail --suffix pareto" || true