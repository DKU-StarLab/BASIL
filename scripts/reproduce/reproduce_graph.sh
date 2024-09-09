#! /usr/bin/env bash
set -e
echo "Reproducing graphs ..."

mkdir -p ./results/graphs

python3 ./scripts/graphs/fig5_dataset.py
python3 ./scripts/graphs/fig6_sampling_impact_rmi.py
python3 ./scripts/graphs/tbl2_sampling_impact_rmi.py
python3 ./scripts/graphs/fig7_sampling_impact_pgm.py
python3 ./scripts/graphs/fig8_sampling_impact_rs.py 
python3 ./scripts/graphs/fig9_sampling_impact_cht.py
python3 ./scripts/graphs/fig10_build_speedup.py
python3 ./scripts/graphs/fig11_design_space.py
python3 ./scripts/graphs/fig12_13_pareto.py