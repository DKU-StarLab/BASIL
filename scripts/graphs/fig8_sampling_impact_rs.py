# %%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import math

# %%
def getYLabel(y):
    if y == "build":
        col = "(a) Build time (ms)"
    elif y == "space":
        col = "(b) Index size (MB)"     
    elif y == "total":
        col = "(c) Lookup latency (ns)"  
    elif y == "density":
        col = "(d) # of splines / bin"     
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
    else:
        col = y
    return col

# %%
def plotGraph(fig, df, ycol):
    unique_segs = df['search_length'].unique()
    unique_segs = np.sort(unique_segs)[::-1]
    
    k = 0
    for i, segs in enumerate(unique_segs):
        temp = df[df['search_length'] == segs]
        intervals = temp['interval'].unique()      

        log_search_length = "{" +str(int(math.log2(segs/2))) + "}"
        label_ = r"$\varepsilon$" + f"$=\mathcal{{2}}^{log_search_length}$"
        
        xs, ys = zip(*sorted(zip(temp['interval'], temp[ycol])))
        fig.plot(xs, ys, label=label_, c=tab20(14-k*2), marker="o", markersize=4)
        k += 1

    return temp

# %%
tab20 = plt.get_cmap('tab20')

# Read separate benchmark results
ori = pd.read_csv("./results/history_200M_uint64_results_sep_meta.csv")
df = ori[ori['index'] == "msRS"]

# msRS index meta data
options = ['radix_bit','error', 'interval', 'radix_size', 'spline_size', 'avg_abs_error']
col_types = {'radix_bit':'int','error':'int', 'interval':'int', 'radix_size':'float', 'spline_size':'float', 'avg_abs_error':'float'}

for i, opt in enumerate(options):
    df[opt] = df.options.str.split('/').str[i]

df = df.astype(col_types)
df['search_length'] = 2*(df['error'] + df['interval']) -1    
df['density'] = df['spline_size']/4194304

# Read cache benchmark results
cdf = pd.read_csv("./results/history_200M_uint64_results_perf_perf.csv")
cdf = cdf[(cdf['index'] == "sRS") & (cdf['perf type'] == 'LLC miss')]

perf_options = ['radix_bit','error', 'interval']
perf_opt_types = {'radix_bit':'int','error':'int', 'interval':'int'}

for i, opt in enumerate(perf_options):
    cdf[opt] = cdf.options.str.split('/').str[i]

cdf = cdf.astype(perf_opt_types)
cdf['search_length'] = 2*(cdf['error'] + cdf['interval']) -1    

# Graph figure configurations 
ncol = 3; nrow = 3
fig, axes = plt.subplots(nrow, ncol)
fig.set_size_inches((7, 6.5))

# X-axis label
x_axis_values = [r'$1$', r'$2^{4}$',r'$2^{8}$',r'$2^{12}$',r'$2^{16}$'] 
x_axis_ticks= list(map(lambda x: 16 ** x, range(0, len(x_axis_values))))

# aY-axis label (build time)
ay_axis_values = [r'$10^{-1}$', r'$10^{1}$', r'$10^{3}$']
ay_axis_ticks = list(map(lambda x: 10 **(5+2*x), range(0, len(ay_axis_values))))

# bY-axis label (index size)
by_axis_values = [r'$10^{0}$',r'$10^{1}$',r'$10^{2}$', r'$10^{3}$']
by_axis_ticks = list(map(lambda x: 10 **(6+x), range(0, len(by_axis_values))))

ycols = ['build', 'space','total', 'density','perf_predict', 'predict', 'avg_abs_error','perf_correct', 'correct']

for i, ycol in enumerate(ycols):
    row = i//3; col = i%3
    subfig = axes[row, col]

    if 'perf' in ycol:
        plotGraph(subfig, cdf, ycol)
    else:
        plotGraph(subfig, df, ycol)

    # X-axis
    subfig.set_xscale('log')                      
    subfig.set_xticks(x_axis_ticks)
    subfig.set_xticklabels(x_axis_values) 
    subfig.set_xlabel('Sampling interval', size=10)

    if ycol in ['perf_predict', 'perf_correct','predict', 'correct', 'total', 'density']:
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
lines, labels = axes[0,1].get_legend_handles_labels()    
lines = lines[::-1]
labels = labels[::-1] 
fig.legend(lines, labels, bbox_to_anchor=(1.075, 0.5), loc = 'center', ncol=1, fontsize=11)
fig.text(1.075, 0.29, r"$\varepsilon$: error bound", ha='center', va='center', fontsize=11)

plt.tight_layout()
plt.savefig("./results/graphs/fig8_sampling_impact_rs.svg", bbox_inches="tight")

# %% [markdown]
# 


