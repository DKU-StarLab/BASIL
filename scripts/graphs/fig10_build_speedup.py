# %%
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# %%
# plot color palette
muted = sns.color_palette("bright")
pastel = sns.color_palette("pastel")
col_dic = {"books":0, "stack":1, "history":2, "osm":3, "genome":4, "covid":5,
           "books large":0, "osm large":3}

# index options
rmi_options = ["segments", "outlier", "interval"]
rmi_options_types = {"segments":'int', "outlier":"float", "interval":'int'}

pgm_options = ["error", "interval", "recursive_error", "recursive_interval"]
pgm_options_types = {"error":"int", "interval":"int", "recursive_error":"int", "recursive_interval":"int"}

rs_options = ['radix_bit','error', 'interval']
rs_options_types = {'radix_bit':'int','error':'int', 'interval':'int'}

cht_options = ['num_bins_','error', 'interval']
cht_options_types = {'num_bins_':'int','error':'int', 'interval':'int'}

indexes = ['sRMI(Expo)', 'sPGM', 'sRS', 'sCHT']
index_options = [rmi_options, pgm_options, rs_options, cht_options]
index_col_types = [rmi_options_types, pgm_options_types, rs_options_types, cht_options_types]

# result file info
file_path = "./results/"
file_suffix = "_uint64_results_table_speedup.csv"
datasets = ['osm_800M', 'books_800M', 'osm_200M', 'genome_200M', 'books_200M', 'covid_200M', 'stack_200M', 'history_200M']

# %%
def PlotGraph(fig, df, col_y, name):                  
    df = df[df[col_y] != 0]
    for dataset in datasets:
        df_plot = df[df['data'] == dataset]
        
        if len(df_plot) == 0:
          continue
        
        xs, ys = zip(*sorted(zip(df_plot['col_x'], df_plot[col_y])))
            
        label = dataset.replace("_200M", "").replace("syn_geasy_lhard", "syn_ge_lh").replace("syn_ghard_leasy", "syn_gh_le").replace("_800M", " large").replace("_cellids", "")
        
        try:
            if 'syn' in dataset:
                fig.plot(xs, ys, label=label, marker='^', color=muted[col_dic[label]])
            elif '800M' in dataset:
                fig.plot(xs, ys, label=label, marker='s', color=pastel[col_dic[label]], markersize=9)
            else:
                fig.plot(xs, ys, label=label, marker='o' , color=muted[col_dic[label]])
        except:
            pass

# %%
def SafeIntervalDfIndex(df, index, dataset, metric, error=0.05):
    if "RMI" in index:
        x_axis = 'segments'
    else:
        x_axis = 'error'
                
    segments = df[x_axis].unique()
    
    result = []
    for seg in segments:
        df_seg = df[df[x_axis]==seg]
        non_sampling = df_seg[df_seg['interval']==1]
        
        non_sampling_plus_error = round((non_sampling[metric].values[0]) * (1 + error))
        safe_intervals = df_seg[df_seg[metric] <= non_sampling_plus_error]
        max_safe_interval = safe_intervals['interval'].max()
        max_safe_interval_row = df_seg[df_seg['interval'] == max_safe_interval]
        build_speedup = non_sampling['build'].values[0] / max_safe_interval_row['build'].values[0]
        
        result += [[index, dataset, seg, max_safe_interval, build_speedup]]     
    
    df_result = pd.DataFrame(result, columns=["index", "data", "col_x", metric+"_interval", metric+'_build'])
    return df_result

# %%
def ReadCsv(file, index, index_option, index_col_type): 
    df = pd.read_csv(file)
    df = df[df['index'] == index]

    for i, opt in enumerate(index_option):
        df[opt] = df.options.str.split('/').str[i]

    df = df.astype(index_col_type)
                
    if ("PGM" in index) | ("RS" in index):
        df['search_length'] = 2*df['interval'] + 2*df['error'] - 1
        df['error'] = df['search_length']/2
    elif "CHT" in index:  
        df['search_length'] = df['interval'] + df['error']
        df['error'] = df['search_length']/2
                            
    return df

# %%
def SafeInterval(index, index_option, index_col_type):
    is_dataset_first = True
    is_metric_first = True

    for metric in ['average', 'space']:
        for dataset in datasets:
            file = file_path + dataset + file_suffix
            df = ReadCsv(file, index, index_option, index_col_type)
            df_safe_df_idx = SafeIntervalDfIndex(df, index, dataset, metric)
                    
            if is_dataset_first is True:
                result = df_safe_df_idx
                is_dataset_first = False
            else:
                result = pd.concat([result, df_safe_df_idx], ignore_index=True)
                
        if is_metric_first is True:
            final = result
            is_metric_first = False
        else:
            final = final.merge(result, on=['index', 'data', 'col_x'])
        is_dataset_first = True

    final['min_interval'] = final[['average_interval', 'space_interval']].min(axis=1)
    final['min_build'] = final[['average_build', 'space_build']].min(axis=1)

    return final

# %%
# figure init
ncol = 2; nrow = 2
fig, axes = plt.subplots(nrow, ncol)
fig.set_size_inches((8, 6.25))

# Get SafeIntervals
results = []
for index, index_option, index_col_type in zip(indexes, index_options, index_col_types):
    temp = SafeInterval(index, index_option, index_col_type)
    results += [temp]

# Plot Graphs
col = "min_build"
PlotGraph(axes[0,0], results[0], col, "RMI")
PlotGraph(axes[0,1], results[1], col, "PGM")
PlotGraph(axes[1,0], results[2], col, "RS")
PlotGraph(axes[1,1], results[3], col, "CHT")        

# X, Y ticks
x_axis_values = [r'$2^{3}$',r'$2^{6}$',r'$2^{9}$',r'$2^{12}$',r'$2^{15}$',r'$2^{18}$',r'$2^{21}$'] 
x_axis_ticks= list(map(lambda x: 8*8 ** x, range(0, len(x_axis_values))))
    
rmi_x_axis_values = [r'$2^{10}$',r'$2^{14}$',r'$2^{18}$',r'$2^{22}$',r'$2^{26}$'] 
rmix_axis_xticks= list(map(lambda x: 2**10 * 16 ** x, range(0, len(rmi_x_axis_values))))

y_axis_values = [r'$1$', r'$2^{4}$',r'$2^{8}$',r'$2^{12}$',r'$2^{16}$',r'$2^{20}$'] 
y_axis_yticks= list(map(lambda x: 16 ** x, range(0, len(y_axis_values))))

for i in range(0, nrow):
    for j in range(0, ncol):
        row_fig = axes[i, j]        
        
        row_fig.set_xscale('log')
        row_fig.set_yscale('log')
        row_fig.set_ylim(bottom=0.5, top=2*2**20)
         
        row_fig.set_yticks(y_axis_yticks)
        row_fig.set_yticklabels(y_axis_values)

        if (i==0) & (j == 0):
            row_fig.set_xticks(rmix_axis_xticks)
            row_fig.set_xticklabels(rmi_x_axis_values)
        else:
            row_fig.set_xticks(x_axis_ticks)
            row_fig.set_xticklabels(x_axis_values)
    
        row_fig.grid(linestyle='--')

# Titles
axes[0,0].set_title('(a) sRMI', fontsize=14)
axes[0,1].set_title('(b) sPGM',  fontsize=14)
axes[1,0].set_title('(c) sRS', fontsize=14)
axes[1,1].set_title('(d) sCHT', fontsize=14)

# X, Y labels
axes[0,0].set_xlabel('Num of segments (b)', fontsize=12)
axes[0,1].set_xlabel(r"Error bound ($\varepsilon$)", fontsize=12)
axes[1,0].set_xlabel(r"Error bound ($\varepsilon$)", fontsize=12)
axes[1,1].set_xlabel(r"Half of error bound ($\varepsilon$/2)", fontsize=12)

axes[0,0].set_ylabel("Build speedup", fontsize=12)
axes[1,0].set_ylabel("Build speedup", fontsize=12)   

# Legends
lines, labels = fig.axes[0].get_legend_handles_labels()   
lines = lines[::-1]
labels = labels[::-1]    

fig.legend(lines, labels, bbox_to_anchor=(1.1, 0.5), loc = 'center', ncol=1 , fontsize=12)
plt.tight_layout()
plt.savefig("./results/graphs/fig10_build_speedup.svg", bbox_inches="tight")


