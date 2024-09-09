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
    
    if not tail:
        suffix = "_200M_uint64_results_table_pareto.csv"
    else:
        suffix = "_200M_uint64_results_tail_pareto.csv"
        
    fig, axes = plt.subplots(2, 3)
    fig.set_size_inches((11, 7))
    
    # x-axis
    x_axis_values = [r'$10^{0}$', r'$10^{1}$', r'$10^{2}$', r'$10^{3}$', r'$10^{4}$']
    x_axis_ticks = list(map(lambda x: 10 **(6+x), range(0, len(x_axis_values))))
    
    # average y-axis
    avg_y_axis_values = [0, 200, 400, 600, 800] 
    avg_y_axis_ticks= list(map(lambda x: 200 * x, range(0, len(avg_y_axis_values))))
    
    # tail y-axis
    tail_y_axis_values = [600, 900, 1200, 1500, 1800] 
    tail_y_axis_ticks= list(map(lambda x: 600 + 300 * x, range(0, len(tail_y_axis_values))))
    
    for k, dataset in enumerate(datasets):
        i = k // 3; j = k % 3
        df = pd.read_csv(path + dataset + suffix)
        
        for index in indexes:
            if not tail:
                plotIndexAvg(axes[i, j], df, index, 'build', 'average', size)
            else:
                plotIndexTail(axes[i, j], df, index, 'build', '0.999', size)
        
        axes[i,j].set_title(dataset, size=14)
        axes[i,j].set_xscale('log')
        axes[i,j].grid(linestyle='--')
        
        axes[i,j].set_xlim(7.5*10**4, 3.5* 10**10)
        axes[i,j].set_xticks(x_axis_ticks)
        axes[i,j].set_xticklabels(x_axis_values)
        axes[i,j].set_xlabel('Build time (ms)', size=14)
        
        if not tail:
            axes[i,j].set_ylim(0, 800)
            axes[i,j].set_yticks(avg_y_axis_ticks)
            axes[i,j].set_yticklabels(avg_y_axis_values)
        else:
            axes[i,j].set_ylim(550,1800)
            axes[i,j].set_yticks(tail_y_axis_ticks)
            axes[i,j].set_yticklabels(tail_y_axis_values)
  
        if j == 0:
            if not tail:
                axes[i,j].set_ylabel('Avg. lookup latency (ns)', size=14)
            else:
                axes[i,j].set_ylabel('99.9%th lookup latency (ns)', size=14)
        
    lines, labels = fig.axes[-1].get_legend_handles_labels()    
    # lines = lines[::-1]
    # labels = labels[::-1] 
    
    # new_order = [2, 1, 0, 3, 4, 5, 7, 6, 8]
    # lines = [lines[i] for i in new_order]
    # labels = [labels[i] for i in new_order]

    fig.legend(lines, labels, bbox_to_anchor=(1.1, 0.5), loc = 'right', ncol=1, frameon=True, fontsize=13)    
    plt.subplots_adjust(left=0.1, right=0.9, bottom=0.1, top=0.9, wspace=0.2, hspace=0.4)
    
    if not tail:
        plt.savefig("./results/graphs/fig12_pareto_avg.svg", bbox_inches="tight")
    else:
        plt.savefig("./results/graphs/fig12_pareto_tail.svg", bbox_inches="tight")

# %%
Plot2DPareto(indexes, tail=False)
Plot2DPareto(indexes, tail=True)


