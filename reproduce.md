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

### **3.3. Section 5.1: Sampling Impact**  
- **Experiment:**  
  - `./scripts/reproduce/reproduce_meta.sh`: Measures changes in performance counters for prediction and correction.  
  - `sudo ./scripts/reproduce/reproduce_perf.sh`: Measures changes in performance counters for prediction and correction (Root privileges are required to access performance counters).  

- **Reproduce Figure:**  
  - `python3 ./scripts/graphs/fig6_sampling_impact_srmi.py`  
  - `python3 ./scripts/graphs/tbl2_sampling_impact_rmi.py`  
  - `python3 ./scripts/graphs/fig7_sampling_impact_spgm.py`  
  - `python3 ./scripts/graphs/fig8_sampling_impact_srs.py`  
  - `python3 ./scripts/graphs/fig9_sampling_impact_scht.py`  

- **Configurations:**  
  - **Index Structure:** sRMI, sPGM, sRS, sCHT  
  - **Dataset:** `history` listed in `datasets_meta.txt`  
  - **Compiler Macro:** `PERF` in `\benchmarks`  

### **3.4. Section 5.2: Build Speedup**  
- **Experiment:**  
  - `./scripts/reproduce/reproduce_speedup.sh`: Measures build speedup based on the safe interval.  

- **Reproduce Figure:**  
  - `python3 ./scripts/graphs/fig10_build_speedup.py`  

- **Configurations:**  
  - **Index:** sRMI, sPGM, sRS, sCHT  
  - **Dataset:** 8 different datasets listed in `datasets_speedup.txt`  
  - **Compiler Macro:** `SPEEDUP` in `\benchmarks`  

### **3.5. Section 5.3: Design Space**  
- **Experiment:**  
  - `./scripts/reproduce/reproduce_design_space.sh`: Measures the broadened design space through sampling.  

- **Reproduce Figure:**  
  - `python3 ./scripts/graphs/fig11_design_space.py`  

- **Configurations:**  
  - **Index Structure:** sRMI, sPGM, sRS, sCHT  
  - **Dataset:** `history` listed in `datasets_meta.txt`  
  - **Compiler Macro:** `DESIGNSPACE` in `\benchmarks`  

### **3.6. Section 5.4: Pareto Analysis**  
- **Experiment:**  
  - `./scripts/reproduce/reproduce_pareto_avg.sh`: Compares the average lookup latency based on build time.  
  - `./scripts/reproduce/reproduce_pareto_avg.sh`: Compares the 99.9th percentile lookup latency based on build time.  

- **Reproduce Figure:**  
  - `python3 ./scripts/graphs/fig12_13_pareto.py`  

- **Configurations:**  
  - **Index Structure:** Binary Search, sART, sBTree, sIBTree, sRT, sCHT, sRMI, sPGM, sRS  
  - **Dataset:** 6 different datasets listed in `datasets_pareto.txt`  
  - **Compiler Macro:**  
    - Average Latency: `PARETO_AVG_STACK`, `PARETO_AVG_COVID`, `PARETO_AVG_HISTORY`, `PARETO_AVG_BOOKS`, `PARETO_AVG_OSM`, `PARETO_AVG_GENOME` in `\benchmarks`  
    - Tail Latency: `PARETO_TAIL_STACK`, `PARETO_TAIL_COVID`, `PARETO_TAIL_HISTORY`, `PARETO_TAIL_BOOKS`, `PARETO_TAIL_OSM`, `PARETO_TAIL_GENOME` in `\benchmarks`  

### **3.7. Section 4.3: Dataset Hardness**  
- **Experiment:**  
  - Dataset hardness is measured during query file generation (`./scripts/generate.sh`), and results are saved in `results/dataset_hardness.csv`.  

- **Reproduce Figure:**  
  - `python3 ./scripts/graphs/fig5_hardness.py`  

### **4. Flexibility**  
- **Datasets:**  
  - Modify the dataset list file specified in each experimental configuration in Section 3 to conduct experiments with different datasets.  
  - For more details about the datasets, refer to Section 3.2 of the README.  

- **Index Parameters:**  
  - By modifying the index parameters of the macro options specified in each experimental configuration in Section 3, you can conduct experiments with adjusted parameters.  
  - These changes will impact metrics such as lookup latency, build time, index size, and performance counters.  
  - For more details about the index parameters, refer to Sections 3.3 and 3.4 of the README.  

- **New Experiments:**  
  - Refer to Sections 3.1 through 3.4 of the README to conduct new experiments with different datasets and parameters.  
