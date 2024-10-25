## Notice of Minor Update for Reviewers
Dear Reviewers,

I would like to inform you of a minor update to the submitted artifact. **If this update causes any issues during your review, please kindly evaluate the previously [submitted commit version](https://github.com/DKU-StarLab/BASIL/tree/a142fdb66c56261bd62e19029fe7aed151578c4f).**

- Flexibility: We have added more detailed explanations in the README.md regarding the dataset and hyper-parameter setup.

- Single Execution: Previously, users had to manually install dependencies via commands before running the single execution script. Now, the installation commands for dependencies are included in the single execution process.

Please note that the artifact's code itself has not been modified in any way, so the changes will not affect the experiments or reproducibility of the results. These updates are purely to provide more clarity and convenience for users.

I apologize for any inconvenience this may have caused.

## Reproduction
We provide all the experimental results of the paper for reproduction. 

### 1. Environment and Hardware
- Environment (in the paper): 
  - OS: Ubuntu 20.04 LTS
  - CPU: a dual-socket machine with two 32-core Intel(R) Xeon(R) Gold 6338 CPUs (2.00 GHz, 48 MB L3)
  - MEM: 512 GB
  - ⚠️ Note: sCHT can have a large memory footprint depending on hyperparameters and dataset complexity, potentially causing termination if memory is insufficient. Thus, sCHT is executed last in each experiment, starting with configurations that use less memory. Even if a benchmark terminates prematurely, the shell script skips it and continues execution.

### 2. Reproduce all with a single execution
```bash
git clone https://github.com/DKU-StarLab/BASIL.git
cd BASIL
sudo ./scripts/reproduce/reproduce.sh
```
- Results will be saved as CSV files in the `results/` folder, and graphs will be saved in the `results/graphs/` folder.
- Root privileges are required for perf counter
- Depending on the hardware, the tests may take several days.
  - In my environment, it took approximately **3 ~ 4 days** to complete all the experiments.

### 3. Reproduce each experiment result and graph individually
#### 3.1. Clone the repository and install dependencies.
```bash
git clone https://github.com/DKU-StarLab/BASIL.git
cd BASIL
sudo apt -y update
sudo apt -y install zstd python3-pip m4 cmake clang libboost-all-dev 
pip3 install -r requirements.txt
```

#### 3.2. Download datasets, build benchmarks, and generate query files.
```bash
./scripts/download_data.sh
./scripts/prepare.sh
./scripts/generate.sh
```

#### 3.3. Section 5.1: Sampling Impact
- `./scripts/reproduce/reproduce_meta.sh`: Measures the impact on the internal structure, accuracy, and changes in prediction/correction latency of indexes such as sRMI, sPGM, sRS, and sCHT according to the sampling interval.
- `sudo ./scripts/reproduce/reproduce_perf.sh`: Measures changes in the perf counter for prediction/correction of sRMI, sPGM, sRS, and sCHT according to the sampling interval. (Root privileges are required for perf counter)
- `fig6_sampling_impact_srmi.py`, `tbl2_sampling_impact_rmi.py`, `fig7_sampling_impact_spgm.py`, `fig8_sampling_impact_srs.py`, `fig9_sampling_impact_scht.py`: Reproduce each graph and table.

#### 3.4. Section 5.2: Build Speedup
- `./scripts/reproduce/reproduce_speedup.sh`: Measures the build speedup according to the safe interval of sRMI, sPGM, sRS, and sCHT on various 8 datasets.
- `./scripts/graphs/fig10_build_speedup.py`: Reproduce graph. 

#### 3.5. Section 5.3: Design Space
- `./scripts/reproduce/reproduce_speedup.sh`: Measures the boarden design space through sampling of sRMI, sPGM, sRS, and sCHT in the History dataset.
- `./scripts/graphs/fig10_build_speedup.py`: Reproduce graph.

#### 3.6. Section 5.4: Pareto Anaylsis
- `./scripts/reproduce/reproduce_pareto_avg.sh`: Compares the average lookup latency according to build time of 8 different indexes on various 6 datasets.
- `./scripts/reproduce/reproduce_pareto_avg.sh`: Compares the 99.9%th lookup latency according to build time of 8 different indexes on various 6 datasets.
- `./scripts/graphs/fig12_13_pareto.py`: Reproduce graphs.

#### 3.7. Section 4.3: Dataset Hardness
- The hardness of the dataset has already been measured when generating the query file (`./scripts/generate.sh`), and the results are saved in `results/dataset_hardness.csv`.
- `./scripts/graphs/fig5_hardness.py`: Reproduce graph.

### 4. Flexibility 
- You can conduct various experiments by referring to sections 3.1 to 3.4 of the README.md.
