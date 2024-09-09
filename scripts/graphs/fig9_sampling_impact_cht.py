# %%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os
import matplotlib as mpl
import math
import seaborn as sns

# %%
header_list = ['index', 'options', 'search', 'space', 'build', 'search type', 'dataset']
tab20 = plt.get_cmap('tab20')

searchs = ["total", "predict", "correct"]
search_types = {"total":"float", "predict":"float", "correct":"float"}                        

bright = sns.color_palette("bright")

options = ['num_bins_','sampled_error', 'interval', 'table_cnt', 'flatten_build', 'search_length', 'avg_height', 'avg_search_length', 'cnt_leaf', 'cnt_pointer', 'cnt_empty', 'avg_abs_error']
col_types = {'num_bins_':'int','sampled_error':'int', 'interval':'int','search_length':'float', 'flatten_build':'float', 'table_cnt':'float', 'avg_height':'float', 'avg_search_length':'float', 'cnt_leaf':'int', 'cnt_pointer':'int', 'cnt_empty':'int', 'avg_abs_error':'float'}

# %%
def getYLabel(y):
    if y == "build":
        col = "(a) Build time (ms)"
    elif y == "space":
        col = "(b) Index size (MB)"        
    elif y == "total":
        col = "(c) Lookup latency (ns)"
    elif y == "avg_height":
        col = "(d) Mean height"
    elif y == "perf_predict":
        col = "(e) Pred. cache misses"
    elif y == 'predict':
        col = "(f) Pred. latency (ns)"     
    elif y == 'avg_abs_error':
        col = "(g) MSE"           
    elif y == "perf_correct":
        col = "(h) Corr. cache misses"
    elif y == 'correct':
        col = "(i) Corr. latency (ns)"
    elif y == 'lookup_empty':
        col = "(j) Used empty bin ratio (%)"
    elif y == 'branch_ratio':
        col = "(K) Pos. branch ratio (%)"        
    else:
        col = y
    return col

# %%
def getLabel(seg, y):
    label = ''

    if y == 'avg_abs_error':
        log = "{" +str(int(math.log2(seg))) + "}"
        if seg == 9:
            label = r"$\varepsilon$" + f"$=\mathcal{{2}}^{log} - 1$"
        else:
            label = r"$\varepsilon$" + f"$=\mathcal{{2}}^{log} - 1$"
    elif seg == 9:
        if y == 'build':
            label = 'overall'
        elif y == 'flatten_build':
            label = 'flatten'
        elif(y == 'empty_size'):
            label = 'empty'
        elif (y == 'space'):
            label = 'overall'
    
    return label

# %%
def plotGraph(fig, df, ycol):
    unique_segs = df['search_length'].unique()
    unique_segs = np.sort(unique_segs)[::-1]

    k = 0
    for i, search_length in enumerate(unique_segs):
        temp = df[df['search_length'] == search_length]
        intervals = temp['interval'].unique()
        
        log_search_length = "{" +str(int(math.log2(search_length))) + "}"
        label_ = r"$\varepsilon$" + f"$=\mathcal{{2}}^{log_search_length} - 1$"
        
        xs, ys = zip(*sorted(zip(temp['interval'], temp[ycol])))
        fig.plot(xs, ys, c=bright[len(unique_segs) -1 - k], marker="o", markersize=4, label=label_)
        k += 1
        
    return temp

# %%
pastel = sns.color_palette("pastel")

# Read separate benchmark results
ori = pd.read_csv("./results/history_200M_uint64_results_sep_meta.csv")
df = ori[ori['index'] == "msCHT"]

# index meta data
options = ['num_bins_','error', 'interval', 'avg_abs_error', 'avg_height', 'lookup_empty', 'branch_ratio']
col_types = {'num_bins_':'int','error':'int', 'interval':'int','avg_abs_error':'float', 'avg_height':'float', 'lookup_empty':'float', 'branch_ratio':'float'}

for i, opt in enumerate(options):
    df[opt] = df.options.str.split('/').str[i]

df = df.astype(col_types)
df['branch_ratio'] = df['branch_ratio'] * 100
df['search_length'] = df['error'] + df['interval'] + 1

# Read cache benchmark results
pdf = pd.read_csv("./results/history_200M_uint64_results_perf_perf.csv")
pdf = pdf[pdf['index'] == "sCHT"]

# index meta data
perf_options = ['num_bins_','error', 'interval', ]
perf_opt_types = {'num_bins_':'int','error':'int', 'interval':'int'}

for i, opt in enumerate(perf_options):
    pdf[opt] = pdf.options.str.split('/').str[i]

pdf = pdf.astype(perf_opt_types)
pdf['search_length'] = pdf['error'] + pdf['interval'] + 1

cdf = pdf[pdf['perf type'] == 'LLC miss']
bdf = pdf[pdf['perf type'] == 'Branch miss']

# Graph figure configurations     
ncol = 3; nrow = 4
fig, axes = plt.subplots(nrow, ncol)
fig.set_size_inches((7, 8.75))

# X-axis label
x_axis_values = [r'$1$', r'$2^{4}$',r'$2^{8}$',r'$2^{12}$',r'$2^{16}$'] 
x_axis_ticks= list(map(lambda x: 16 ** x, range(0, len(x_axis_values))))

# aY-axis label (build time)
ay_axis_values = [r'$10^{0}$', r'$10^{2}$', r'$10^{4}$']
ay_axis_ticks = list(map(lambda x: 10 **(6+2*x), range(0, len(ay_axis_values))))

sx_values = [r'$10^{0}$', r'$10^{2}$', r'$10^{4}$']
sx_xticks = list(map(lambda x: 10 **(6+2*x), range(0, len(sx_values))))

ycols = ['build','space','total','avg_height','perf_predict','predict','avg_abs_error','perf_correct','correct', 'lookup_empty', 'branch_ratio', 'branch_miss']

for i, ycol in enumerate(ycols):
    row = i//3; col = i%3
    subfig = axes[row, col]
    
    if 'perf' in ycol:
        plotGraph(subfig, cdf, ycol)
    elif ycol == 'branch_miss':
        temp = 'perf_correct'
        print(temp)
        plotGraph(subfig, bdf, temp)
    else:
        plotGraph(subfig, df, ycol)
        
    # X-axis
    subfig.set_xscale('log')                      
    subfig.set_xticks(x_axis_ticks)
    subfig.set_xticklabels(x_axis_values) 
    subfig.set_xlabel('Sampling interval', size=10)

    if ycol in ['build', 'space', 'avg_abs_error']:
        subfig.set_yscale('log')
    else:
        subfig.set_yscale('linear')
        
    if 'build' in ycol:                                      
        subfig.set_yticks(ay_axis_ticks)
        subfig.set_yticklabels(ay_axis_values)
    elif 'branch_ratio' in ycol:
        subfig.set_yticks([50, 75, 100])
        subfig.set_yticklabels(['50', '75', '100'])
    if i == 3:
        subfig.set_yticks([2, 2.5, 3])
    
    subfig.grid(linestyle='--')
    
    if ycol == 'branch_miss':
        subfig.set_ylabel('(l) Corr. branch misses')
    else:
        subfig.set_ylabel(getYLabel(ycol))
        
lines, labels = axes[2,0].get_legend_handles_labels()    
lines = lines[::-1]
labels = labels[::-1] 

fig.legend(lines, labels, bbox_to_anchor=(1.1, 0.5), loc = 'center', ncol=1, fontsize=11)
fig.text(1.1, 0.34, r"$\varepsilon$: error bound", ha='center', va='center', fontsize=11)

plt.tight_layout()
plt.savefig("./results/graphs/fig9_sampling_impact_cht.svg")


