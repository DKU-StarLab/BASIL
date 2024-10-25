#! /usr/bin/env bash
set -e
echo "Reproducing artifacts ..."

sudo apt -y update
sudo apt -y install zstd python3-pip m4 cmake clang libboost-all-dev 
pip3 install -r requirements.txt

# Download Dataset
./scripts/download.sh

# Build Benchmark
./scripts/prepare.sh

# Generate Queries
./scripts/generate.sh

mkdir -p ./results/graphs

# Section 5.1 (Table 2 & Fig 6, 7, 8, 9)
./scripts/reproduce/reproduce_meta.sh

# Section 5.2 (Fig 10)
./scripts/reproduce/reproduce_speedup.sh

# Section 5.3 (Fig 11)
./scripts/reproduce/reproduce_design_space.sh

# Section 5.4.1 (Fig 12)
./scripts/reproduce/reproduce_pareto_avg.sh

# Section 5.4.2 (Fig 13)
./scripts/reproduce/reproduce_pareto_tail.sh

# Plot figures
./scripts/reproduce/reproduce_graph.sh