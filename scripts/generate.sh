#! /usr/bin/env bash

cd build

mkdir -p ../results

function generate_lookups() {
    echo "Generating lookups for $1"
    [ -f ../data/$1_equality_lookups_10M ] || ./generate ../data/$1 10000000
    [ -f ../data/$1_equality_lookups_1M ] || ./generate ../data/$1 1000000
}

echo "Generating queries..."

generate_lookups history_200M_uint64
generate_lookups stack_200M_uint64
generate_lookups covid_200M_uint64
generate_lookups books_200M_uint64
generate_lookups genome_200M_uint64
generate_lookups osm_200M_uint64

generate_lookups fb_200M_uint64
generate_lookups libio_200M_uint64
generate_lookups planet_200M_uint64
generate_lookups wise_200M_uint64
generate_lookups wiki_200M_uint64

generate_lookups books_800M_uint64
generate_lookups osm_800M_uint64
