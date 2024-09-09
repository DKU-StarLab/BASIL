# %%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math

# %%
def getYLabel(y):
    if y == "build":
        col = "(a) Build time (ms)"
    elif y == "space":
        col = "(b) Index size (MB)"        
    elif y == "total":
        col = "(c) Lookup latency (ns)"
    elif y == "constant_ratio":
        col = "(d) Const. seg. ratio (%)"      
    elif y == "perf_predict":
        col = "(e) Pred. cache misses"          
    elif y == 'predict':
        col = "(f) Pred. latency (ns)"
    elif y == 'total_avg_error':
        col = "(g) MSE"     
    elif y == "perf_correct":
        col = "(h) Corr. cache misses"           
    elif y == 'correct':
        col = "(i) Corr. latency (ns)"
    else:
        col = y
    return col

# %%
def getLabel(seg, y):
    label = ''
    
    if y == 'build':
        log = "{" +str(int(math.log2(seg))) + "}"
        label = f"$b=\mathcal{{2}}^{log}$"
            
    return label

# %%
def plotGraph(fig, df, ycol):
    unique_segs = df['segments'].unique()
    
    for i, segs in enumerate(unique_segs):
        temp = df[df['segments'] == segs]
        intervals = temp['interval'].unique()
        
        xs, ys = zip(*sorted(zip(temp['interval'], temp[ycol])))
        label2 = getLabel(segs, ycol)
        fig.plot(xs,ys, label=label2, c=tab20(i*2), marker="o", markersize=4)


# %%
def plotPerf(fig, df, y):
    unique_segs = df['segments'].unique()
    
    for i, segs in enumerate(unique_segs):
        group = df[df['segments'] == segs]
        
        xs, ys = zip(*sorted(zip(group['interval'], group[y])))
        label2 = getLabel(segs, y)
        fig.plot(xs,ys, label=label2, c=tab20(i*2), marker="o", markersize=4)

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
    
df = df.astype(opt_types)
df['constant_ratio'] = (df['constant'] / df['segments']) * 100

# Read cache benchmark results
cdf = pd.read_csv("./results/history_200M_uint64_results_perf_perf.csv")
cdf = cdf[(cdf['index'] == "sRMI(Expo)") & (cdf['perf type'] == 'LLC miss')]

# sRMI(NB) index meta data
perf_options = ["segments", "outlier", "interval"]
perf_opt_types = {"segments":'int', "outlier":"float", "interval":'int'}

for i, opt in enumerate(perf_options):
    cdf[opt] = cdf.options.str.split('/').str[i]
    
cdf = cdf.astype(perf_opt_types)

# Graph figure configurations 
ncol = 3; nrow = 3
fig, axes = plt.subplots(nrow, ncol)
fig.set_size_inches((7, 6.5))

# X-axis label
x_axis_values = [r'$1$', r'$2^{4}$',r'$2^{8}$',r'$2^{12}$',r'$2^{16}$'] 
x_axis_ticks= list(map(lambda x: 16 ** x, range(0, len(x_axis_values))))
    
# aY-axis label (build time)
ay_axis_values = [r'$10^{0}$', r'$10^{2}$', r'$10^{4}$']
ay_axis_ticks = list(map(lambda x: 10 **(6+2*x), range(0, len(ay_axis_values))))

# bY-axis label (index size)
by_axis_values = [r'$10^{-1}$', r'$10^{1}$', r'$10^{3}$']
by_axis_ticks = list(map(lambda x: 10 **(5+2*x), range(0, len(by_axis_values))))

ycols = ['build', 'space', 'total', 'constant_ratio','perf_predict','predict','total_avg_error','perf_correct','correct']
        
# Plot sub-figs        
for i, ycol in enumerate(ycols):
    row = i//3; col = i%3
    subfig = axes[row, col]

    if 'perf_' in ycol:
        plotGraph(subfig, cdf, ycol)
    else:
        plotGraph(subfig, df, ycol)

    # X-axis
    subfig.set_xscale('log')                      
    subfig.set_xticks(x_axis_ticks)
    subfig.set_xticklabels(x_axis_values) 
    subfig.set_xlabel('Sampling interval', size=10)

    # Y-axis
    if ycol in ['perf_predict', 'perf_correct', 'predict', 'correct', 'total', 'constant_ratio']:
        subfig.set_yscale('linear')
    else:
        subfig.set_yscale('log')

    if 'build' in ycol:                                      
        subfig.set_yticks(ay_axis_ticks)
        subfig.set_yticklabels(ay_axis_values)
    elif 'space' in ycol:
        subfig.set_yticks(by_axis_ticks)
        subfig.set_yticklabels(by_axis_values)
    
    subfig.grid(linestyle='--')
    subfig.set_ylabel(getYLabel(ycol))

# Legend    
lines, labels = axes[0,0].get_legend_handles_labels()    
fig.legend(lines, labels, bbox_to_anchor=(1.075, 0.525), loc = 'center', ncol=1, fontsize=11)
fig.text(1.1, 0.37, f"b: # of segments \n (branching factor)", ha='center', va='center', fontsize=11)

# Save
plt.tight_layout()
plt.savefig("./results/graphs/fig6_sampling_impact_rmi.svg", bbox_inches="tight")

# %%



