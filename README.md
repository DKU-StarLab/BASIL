<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="./utils/title.png">
    <img alt="BASIL" src="./utils/title.png" width=55%>
  </picture>
</p>

<h3 align="center">
Benchmark for Sampling Applied (Learned) Indexes
</h3>

<p align="center">
| <a href="https://dl.acm.org/doi/10.1145/3654919"><b>Paper</b></a> | <a href="https://min-guk.github.io/assets/pdf/%5BSlides%5D%20Can%20Learned%20Indexes%20be%20Built%20Efficiently.pdf"><b>Slides</b></a> | <a href="https://min-guk.github.io/assets/pdf/%5BPoster%5D%20Can%20Learned%20Indexes%20be%20Built%20Efficiently.pdf"><b>Poster</b></a> | <a href="https://www.youtube.com/watch?v=PFNs0-UCWmg"><b>Video</b></a> |

</p>


---
🌿 **BASIL** is a benchmark that evaluates the performance of 8 state-of-the-art learned and traditional indexes using sampling on sorted datasets. It is an artifact of ["Choi et al. Can Learned Indexes be Built Efficiently? A Deep Dive into Sampling Trade-offs. SIGMOD 2024"](https://dl.acm.org/doi/abs/10.1145/3654919). It is built on the earlier benchmark [SOSD](https://github.com/learnedsystems/SOSD).

## 1. Contents
```
LIST
├── ...
├── benchmarks            // configurations to be compiled and executed
├── data                  // datasets
├── indexes               // source code of sampling applied indexes
├── results               // results of benchmark execution
├── scripts               // scripts for benchmark automation
│   └── reproduce         // scripts for reproduction
└── wrappers              // interface of indexes
     └── meta             // interface of indexes for measuring internal changes
```

## 2. Build
### (1) Clone the repository and install dependencies.
On vanilla Ubuntu 20.04 LTS:
```bash
git clone https://github.com/DKU-StarLab/BASIL.git
cd BASIL
sudo apt -y update
sudo apt -y install zstd python3-pip m4 cmake clang libboost-all-dev 
pip3 install -r requirements.txt
```
### (2) Download datasets, build benchmarks, and generate query files.
```bash
./scripts/download_data.sh
./scripts/prepare.sh
./scripts/generate.sh
```

## 3. Run
### (1) Benchmarks Types
Five types of benchmarks can be conducted using the following scripts. All benchmarks measure the build time and index size according to the hyper-parameters of each index. The results from the scripts are saved as CSV files in the `results/` folder.
- `scripts/excute_avg.sh`: Measures the average lookup latency.
- `scripts/excute_tail.sh`: Measures the lookup latency at 0/50/90/99/99.9/99.99%th percentiles.
- `scripts/excute_sep.sh`: Measures the average latency of prediction and correction separately.
- `scripts/excute_perf.sh`: Measures the perf counter (LLC, TLB, Branch, Instructions) of prediction and correction separately.
- `scripts/excute_build.sh`: Does not perform lookups. 

### (2) Index Hyper-parameter Setting (Templates)
- Benchmarks can be performed by setting each index using the templates in the `benchmarks/` folder. This method of using templates is inherited from SOSD to avoid accidentally measuring vtable lookup times. However, this can lead to long benchmark build times.
- The `benchmarks/` folder contains parameters used in the paper's experiments. To avoid unnecessary long build times by compiling unnecessary templates, conditional compilation directives (`#ifdef`, `#endif`) were used to restrict compilation to only the required templates.
- If a user wants to perform a benchmark with newly defined parameters, they can input the parameters in the section defined by `#ifdef USER`, compile with `scripts/prepare.sh`, and then run the benchmark execution scripts described above.
- ⚠️ Note: When changing conditional compilation directives (`#ifdef`, `#endif`) for a build, please reset the macro options stored in the CMake cache (`rm -rf build/CMakeCache.txt build/CMakeFiles/`). Otherwise, previously used conditional compilation directives may be included in the build. 

### (3) Reproduction
For reproduction, please refer to [reproduce.md](./reproduce.md) file.


## 4. References
We have developed the 🌿 **BASIL** based on various previous benchmarks, open-source projects, and papers. We thank the researchers for their valuable contributions. 

### Benchmark
- Kipf, Andreas, et al. "SOSD: A benchmark for learned indexes." [(MLSys@NeurIPS '19)](https://mlforsystems.org/assets/papers/neurips2019/sosd_kipf_2019.pdf) [:octocat:](https://github.com/learnedsystems/SOSD)
- Marcus, Ryan, et al. "Benchmarking learned indexes." [(VLDB '20)](https://vldb.org/pvldb/vol14/p1-marcus.pdf) [:octocat:](https://github.com/learnedsystems/SOSD)
- Wongkham, Chaichon, et al. "Are updatable learned indexes ready?." [(VLDB '22)](https://vldb.org/pvldb/vol15/p3004-wongkham.pdf) [:octocat:](https://github.com/gre4index/GRE)

### Index
- Kraska, Tim, et al. "The case for learned index structures." [(SIGMOD '18)](https://dl.acm.org/doi/abs/10.1145/3183713.3196909) [:octocat:](https://github.com/learnedsystems/RMI)
- Marcus, Ryan, et al. "Cdfshop: Exploring and optimizing learned index structures." [(SIGMOD '20)](https://dl.acm.org/doi/abs/10.1145/3318464.3384706) [:octocat:](https://github.com/learnedsystems/RMI)
- Maltry, Marcel, et al. "A critical analysis of recursive model indexes." [(VLDB '22)](https://vldb.org/pvldb/vol15/p1079-maltry.pdf) [:octocat:](https://github.com/BigDataAnalyticsGroup/analysis-rmi)
- Ferragina, Paolo, et al. "The PGM-index: a fully-dynamic compressed learned index with provable worst-case bounds." [(VLDB '20)](https://www.vldb.org/pvldb/vol13/p1162-ferragina.pdf) [:octocat:](https://github.com/gvinciguerra/PGM-index)
- Kipf, Andreas, et al. "RadixSpline: a single-pass learned index." [(aiDM@SIGMOD '20)](https://dl.acm.org/doi/abs/10.1145/3401071.3401659) [:octocat:](https://github.com/learnedsystems/RadixSpline)
- Crotty, Andrew. "Hist-Tree: Those Who Ignore It Are Doomed to Learn." [(CIDR '21)](https://www.cidrdb.org/cidr2021/papers/cidr2021_paper20.pdf)
- Stoian, Mihail, et al. "Towards Practical Learned Indexing." [(AIDB@VLDB '21)](https://sites.google.com/view/aidb2021/home/accepted-papers?authuser=0) [:octocat:](https://github.com/stoianmihail/PLEX)

## 5. Citation
```
@article{choi2024can,
  title={Can Learned Indexes be Built Efficiently? A Deep Dive into Sampling Trade-offs},
  author={Choi, Minguk and Yoo, Seehwan and Choi, Jongmoo},
  journal={Proceedings of the ACM on Management of Data},
  volume={2},
  number={3},
  pages={1--25},
  year={2024},
  publisher={ACM New York, NY, USA}
}
```
