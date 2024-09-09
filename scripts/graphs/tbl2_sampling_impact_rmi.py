# %%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math

# %%
tab20 = plt.get_cmap('tab20')

# Read separate benchmark results
ori = pd.read_csv("./results/history_200M_uint64_results_sep_meta.csv")
df = ori[ori['index'] == "msRMI(Expo)"]

# msRMI(NB) index meta data
options = ["segments", "outlier", "interval", "total_avg_error", "constant"]
opt_types = {"segments":'int', "outlier":"float", "interval":'int', "total_avg_error":"float", "constant":'int'}

for i, opt in enumerate(options):
    df[opt] = df.options.str.split('/').str[i]

df['options'] = df['options'] = df['options'].apply(lambda x: '/'.join(x.split('/')[:3]))
df = df.astype(opt_types)
df['constant_ratio'] = (df['constant'] / df['segments']) * 100

# Read cache benchmark results
cdf = pd.read_csv("./results/history_200M_uint64_results_perf_perf.csv")
cdf = cdf[(cdf['index'] == "sRMI(Expo)")]

# sRMI(NB) index meta data
perf_options = ["segments", "outlier", "interval"]
perf_opt_types = {"segments":'int', "outlier":"float", "interval":'int'}

for i, opt in enumerate(perf_options):
    cdf[opt] = cdf.options.str.split('/').str[i]
    
cdf = cdf.astype(perf_opt_types)


# %%
pivot_df = cdf.pivot_table(
    index='options',
    columns='perf type',
    values=['perf_predict', 'perf_correct'],
    aggfunc='sum'
)

pivot_df.columns = ['_'.join(col).strip() for col in pivot_df.columns.values]

result_df = pd.merge(pivot_df, df[['options', 'predict', 'correct']], on='options', how='left')

predict_corr = result_df[['predict', 'perf_predict_Instructions', 'perf_predict_Branch miss', 'perf_predict_TLB miss', 'perf_predict_LLC miss']].corr()
correct_corr = result_df[['correct', 'perf_correct_Instructions', 'perf_correct_Branch miss', 'perf_correct_TLB miss', 'perf_correct_LLC miss']].corr()
predict_corr.columns = ['latency', 'Instructions', 'Branch misses', 'TLB misses', 'LLC misses']
correct_corr.columns = ['latency', 'Instructions', 'Branch misses', 'TLB misses', 'LLC misses']

combined_corr = pd.concat([predict_corr, correct_corr])
combined_corr = combined_corr.drop(columns=['latency'])
combined_corr = combined_corr.loc[['predict', 'correct']]
combined_corr = combined_corr.rename(index={'predict': 'Pred. Lat.', 'Corr. Lat.': 'Correction'})
combined_corr = combined_corr.round(3)

fig, ax = plt.subplots(figsize=(5, 2))
ax.axis('off')

table = ax.table(cellText=combined_corr.values, colLabels=combined_corr.columns, rowLabels=combined_corr.index, cellLoc='center', loc='center')

plt.savefig("./results/graphs/tbl2.svg", bbox_inches='tight', pad_inches=0.1)


