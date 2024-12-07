# %%
import seaborn as sns
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# %%
col_dic_avg = {"sRS":4, "sCHT":6 , "sPGM":2, "sRMI(Expo)":0,
           "ART": 12, "BTree": 8, "IBTree": 10, "sRT":16}

col_dic_tail = {"sRS":2, "sCHT":3 , "sPGM":1, "sRMI(Expo)":0,
           "ART": 6, "BTree": 4, "IBTree": 5, "sRT":16}

tab20 = plt.get_cmap('tab20')
tab20c = plt.get_cmap('tab20c')
muted = sns.color_palette("bright")

traditional = ["BinarySearch", "BTree", "IBTree", "ART"]
rt = ["sRT", "sCHT"]
learned = ["sRMI(Expo)", "sPGM", "sRS"]

indexes = traditional + rt  + learned 

# %%
def plotIndexAvg(fig, df, index, x_axis, y_axis, size=7):
    df = df[df['index'] == index]

    if not index.startswith('s'):
        label = 's' + index
    else:
        label = index
            
    try:
        xs, ys = zip(*sorted(zip(df[x_axis], df[y_axis])))
    except:
        return
    
    if index == "BinarySearch":
        fig.axhline(ys, 0, 1, label="BinarySearch", color='black')
    elif index in traditional:
        fig.plot(xs, ys, label=label, marker='<', c=tab20(col_dic_avg[index]), markersize=size, lw=1.375)
    elif index in learned:
        fig.plot(xs, ys, label=label.replace("(Expo)",""), marker='o' , c=tab20(col_dic_avg[index]), markersize=size, lw=1.375)
    elif "CHT" in index:
        fig.plot(xs, ys, label=label, marker='X', c=tab20(col_dic_avg[index]), markersize=size, lw=1.375)
    elif "RT" in index:
        fig.plot(xs, ys, label=label, marker='X', c=tab20c(col_dic_avg[index]), markersize=size, lw=1.375)
        

# %%
def plotIndexTail(fig, df, index, x_axis, y_axis, size=7):
    df = df[df['index'] == index]
    
    if not index.startswith('s'):
        label = 's' + index
    else:
        label = index
            
    try:
        xs, ys = zip(*sorted(zip(df[x_axis], df[y_axis])))
    except:
        return
    
    if index == "BinarySearch":
        fig.axhline(ys, 0, 1, label="BinarySearch", color='black')
    elif index in traditional:
        fig.plot(xs, ys, label=label, marker='<', c=muted[col_dic_tail[index]], markersize=size, lw=1.375)
    elif index in learned:
        fig.plot(xs, ys, label=label.replace("(Expo)",""), marker='o' , c=muted[col_dic_tail[index]], markersize=size, lw=1.375)
    elif "CHT" in index:
        fig.plot(xs, ys, label=label, marker='X', c=muted[col_dic_tail[index]], markersize=size, lw=1.375)
    elif "RT" in index:
        fig.plot(xs, ys, label=label, marker='X', c=tab20c(col_dic_tail[index]), markersize=size, lw=1.375)

# %%
def Plot2DPareto(indexes, tail=False, size=7):    
    datasets = ['stack', 'covid', 'history', 'books', 'osm', 'genome']
    path = "./results/"
    y_axis_step = 0
    
    if not tail:
        suffix = "_200M_uint64_results_table_pareto.csv"
        y_axis_step = 200
        df_col = 'average'
    else:
        suffix = "_200M_uint64_results_tail_pareto.csv"
        y_axis_step = 300
        df_col = '0.999'
        
    fig, axes = plt.subplots(2, 3)
    fig.set_size_inches((11, 7))
    
    y_axis_min = 100000000; y_axis_max = 0
    
    for k, dataset in enumerate(datasets):
        i = k // 3; j = k % 3
        df = pd.read_csv(path + dataset + suffix)
        
        for index in indexes:
            if not tail:
                plotIndexAvg(axes[i, j], df, index, 'build', df_col, size)
            else:
                plotIndexTail(axes[i, j], df, index, 'build', df_col, size)
        
        temp_y_axis_min = df[df_col].min()
        temp_y_axis_max = df[df['index']=="BinarySearch"][df_col].values[0]
        
        if y_axis_min > temp_y_axis_min:
            y_axis_min = temp_y_axis_min
        
        if y_axis_max < temp_y_axis_max:
            y_axis_max = temp_y_axis_max

    # y-axis
    y_axis_min = (int) (y_axis_min // 100) * 100 - 100
    y_axis_max = (int) (y_axis_max // 100 + 1) * 100
    if tail: y_axis_max += 100
    
    if y_axis_min < 0:
        y_axis_min = 0
        
    y_axis_values = list(range(y_axis_min, y_axis_max + 1, y_axis_step))
    y_axis_ticks= list(map(lambda x: y_axis_min + y_axis_step * x, range(0, len(y_axis_values))))
    
    # x-axis
    x_axis_values = [r'$10^{0}$', r'$10^{1}$', r'$10^{2}$', r'$10^{3}$', r'$10^{4}$']
    x_axis_ticks = list(map(lambda x: 10 **(6+x), range(0, len(x_axis_values))))
    
    for k, dataset in enumerate(datasets):
        i = k // 3; j = k % 3
                
        axes[i,j].set_title(dataset, size=14)
        axes[i,j].set_xscale('log')
        axes[i,j].grid(linestyle='--')
        
        axes[i,j].set_xlim(7.5*10**4, 3.5* 10**10)
        axes[i,j].set_xticks(x_axis_ticks)
        axes[i,j].set_xticklabels(x_axis_values)
        axes[i,j].set_xlabel('Build time (ms)', size=14)
        
        axes[i,j].set_ylim(y_axis_min, y_axis_max)
        axes[i,j].set_yticks(y_axis_ticks)
        axes[i,j].set_yticklabels(y_axis_values)
  
        if j == 0:
            if not tail:
                axes[i,j].set_ylabel('Avg. lookup latency (ns)', size=14)
            else:
                axes[i,j].set_ylabel('99.9%th lookup latency (ns)', size=14)
        
    lines, labels = fig.axes[-1].get_legend_handles_labels()    

    fig.legend(lines, labels, bbox_to_anchor=(1.1, 0.5), loc = 'right', ncol=1, frameon=True, fontsize=13)    
    plt.subplots_adjust(left=0.1, right=0.9, bottom=0.1, top=0.9, wspace=0.2, hspace=0.4)
    
    if not tail:
        plt.savefig("./results/graphs/fig12_pareto_avg.svg", bbox_inches="tight")
    else:
        plt.savefig("./results/graphs/fig12_pareto_tail.svg", bbox_inches="tight")

# %%
Plot2DPareto(indexes, tail=False)
Plot2DPareto(indexes, tail=True)


