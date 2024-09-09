# %%
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.tri import Triangulation

# %%
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

# result file
datasets = ['history_200M']
file = "./results/history_200M_uint64_results_table_design_space.csv"

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
        nsamp_build, nsamp_search, nsamp_space = non_sampling['build'].values[0], non_sampling['average'].values[0], non_sampling['space'].values[0]
        
        # max safe interval
        non_sampling_plus_error = round((non_sampling[metric].values[0]) * (1 + error))
        safe_intervals = df_seg[df_seg[metric] <= non_sampling_plus_error]
        max_safe_interval = safe_intervals['interval'].max()
        max_safe_interval_row = df_seg[df_seg['interval'] == max_safe_interval]
        build_speedup = non_sampling['build'].values[0] / max_safe_interval_row['build'].values[0]
        safe_build, safe_search, safe_space = max_safe_interval_row['build'].values[0], max_safe_interval_row['average'].values[0], max_safe_interval_row['space'].values[0]
        
        # max interval
        max_row = df_seg[df_seg['interval']==df_seg['interval'].max()]
        max_build, max_search, max_space = max_row['build'].values[0], max_row['average'].values[0], max_row['space'].values[0]
        
        result += [[index, dataset, seg, max_safe_interval, build_speedup, safe_build, safe_search, safe_space, nsamp_build, nsamp_search, nsamp_space, max_build, max_search, max_space]]     
    
    df_result = pd.DataFrame(result, columns=["index", "data", "x_axis", metric+"_interval", metric+'_build', 'safe_build', 'safe_search', 'safe_space', 'nsamp_build', 'nsamp_search', 'nsamp_space', 'max_build', 'max_search', 'max_space'])
    return df_result

# %%
def SafeInterval(index, index_option, index_col_type):
    is_first = True

    for metric in ['average', 'space']:
        for dataset in datasets:
            file = "./results/history_200M_uint64_results_table_design_space.csv"
            df = ReadCsv(file, index, index_option, index_col_type)
            df_safe_df_idx = SafeIntervalDfIndex(df, index, dataset, metric)
                    
            if is_first is True:
                final = df_safe_df_idx
                is_first = False
            else:
                final = final.merge(df_safe_df_idx, on=['index', 'data', 'x_axis'])
  
    final['min_interval'] = final[['average_interval', 'space_interval']].min(axis=1)
    final['min_build'] = final[['average_build', 'space_build']].min(axis=1)

    return final

# %%
def Plot3D(fig, axs, ax, df, index, safe, legend=False, safe_interval=False):
    df = df[df['index'] == index]
             
    # triangulation & scatter
    xs = np.log2(df['build'])
    ys = np.log2(df['space'])
    zs = np.array(df['average'])   
    
    triang = Triangulation(xs, ys)
    surface = ax.plot_trisurf(triang, zs, linewidth=0.2, antialiased=True, shade=True, alpha=0.3, vmin = 0, vmax= 1000, cmap="jet", edgecolor='none')
    ax.scatter(xs, ys, zs, s=20, color='grey')
    
    # no sampling
    safe = safe[safe['data'] == 'history_200M']            
    ds, xs, ys, zs = zip(*sorted(zip(safe['x_axis'], np.log2(safe['nsamp_build_x']), np.log2(safe['nsamp_space_x']), safe['nsamp_search_x'])))
    ax.plot(xs, ys, zs, color='red', linewidth=2, marker="s", markersize=9, label='Without sampling')
    
    # max sampling
    ds, xs, ys, zs = zip(*sorted(zip(safe['x_axis'], np.log2(safe['max_build_x']), np.log2(safe['max_space_x']), safe['max_search_x'])))
    ax.plot(xs, ys, zs, color='g', linewidth=2, marker="o", markersize=9, label='Max down-sampling')

    # safe interval
    if safe_interval:
        ds, xs, ys, zs = zip(*sorted(zip(safe['x_axis'], np.log2(safe['safe_build']), np.log2(safe['safe_space']), safe['safe_search'])))
        ax.plot(xs, ys, zs, color='blue', linewidth=2, marker="X", markersize=10,label='Safe Down-Sampling')

    # legend & cbar
    if legend & ("CHT" in index):
        cbar = fig.colorbar(surface, ax=axs, orientation='vertical', shrink=0.25, aspect=10, pad=0.1, fraction=0.046, anchor=(0.5,0.5))
        cbar.set_label('Lookup Latency (ns)', labelpad=10, size=13)
        
        lines, labels = ax.get_legend_handles_labels()
        fig.legend(lines, labels, bbox_to_anchor=(0.95, 0.335), loc = 'lower center', ncol=1, fontsize=13) 
    else:
        cbar = lines = labels = 1
    
    return cbar, lines, labels

# %%
fig, axs = plt.subplots(2, 2, figsize=(16, 16), subplot_kw={'projection': '3d'})

for k, (index, index_option, index_col_type) in enumerate (
        zip (indexes, index_options, index_col_types)):
    # figure configs
    # ax = fig.add_subplot (2, 2, 1 + i, projection='3d')
    i = k//2; j = k%2
    axs[i,j].view_init (30, 37.5)
    axs[i,j].xaxis.pane.fill = False
    axs[i,j].yaxis.pane.fill = False
    axs[i,j].zaxis.pane.fill = False
    axs[i,j].xaxis.pane.set_edgecolor('w')
    axs[i,j].yaxis.pane.set_edgecolor('w')
    axs[i,j].zaxis.pane.set_edgecolor('w')

    # Plot Graphs
    df = ReadCsv(file, index, index_option, index_col_type)
    safe_interval = SafeInterval(index, index_option, index_col_type)
    cbar, lines, labels = Plot3D(fig, axs,axs[i,j], df, index, safe_interval, legend=True, safe_interval=False)

    # X, Y, Z axis
    xy_axis_values = [r'$10^{-3}$', r'$10^{-1}$', r'$10^{1}$', r'$10^{3}$']
    xy_axis_xticks = list(map(lambda x: np.log2 (10 ** (3 + 2*x)), range(0, len (xy_axis_values))))

    axs[i,j].set_xticks (xy_axis_xticks)
    axs[i,j].set_yticks (xy_axis_xticks)
    
    axs[i,j].set_xticklabels (xy_axis_values, size= 13)
    axs[i,j].set_yticklabels (xy_axis_values, size= 13)
    
    axs[i,j].set_xlim (np.log2 (9 * 10 ** 3), np.log2 (0.1 * 10 ** 11))
    axs[i,j].set_ylim (np.log2 (5 * 10 ** 1), np.log2 (0.1 * 10 ** 11))
    axs[i,j].set_zlim (0, 1000)
    
    axs[i,j].set_xlabel ('Build time (ms)', size= 13)
    axs[i,j].set_ylabel ('Index size (MB)', size= 13)
    axs[i,j].set_zlabel ('Lookup latency (ns)', size= 13)
    
    # Titles
    if "RMI" in index:
        title = "(a) sRMI"
    elif "PGM" in index:
        title = "(b) sPGM"
    elif "RS" in index:
        title = "(c) sRS"
    elif "CHT" in index:
        title = "(d) sCHT"
    
    axs[i,j].set_title (title, size=20)
    
plt.tight_layout ()
plt.savefig("./results/graphs/fig11_design_space.svg", bbox_inches="tight")


