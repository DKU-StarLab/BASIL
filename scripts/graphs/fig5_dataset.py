# %%
import matplotlib.pyplot as plt
import pandas as pd

# %%
pgm = pd.read_csv("./results/dataset_hardness.csv")

pgm = pgm[~pgm['dataset'].str.contains('800M|dup', case=False, na=False)]

fig, ax = plt.subplots(figsize=(6, 4))

for i, row in pgm.iterrows():
    ax.scatter(row.lv, row.gv, marker="o", color='black')        
        
plt.xscale('log')
plt.yscale('log')
plt.xlim(7000,0.5*10**7)
plt.ylim(10,10**4)

d_font_size = 12
font_weight = 'italic'
font1 = 'italic'
font2 = 'Times New Roman'

ax.annotate('history', (105468, 468), textcoords='offset points', xytext=(30,-15), ha='center', size=d_font_size)
ax.annotate('books', (262604, 97), textcoords='offset points', xytext=(0,-20), ha='center', size=d_font_size)
ax.annotate('osm', (661115, 5495), textcoords='offset points', xytext=(-25,-4), ha='center', size=d_font_size)
ax.annotate('genome', (1290208, 1426), textcoords='offset points', xytext=(35,-3), ha='center', size=d_font_size)
ax.annotate('stack', (17833, 133), textcoords='offset points', xytext=(-25,-4), ha='center', size=d_font_size)
ax.annotate('wise', (79035, 382), textcoords='offset points', xytext=(-25,-4), ha='center', size=d_font_size)
ax.annotate('covid', (81908, 850), textcoords='offset points', xytext=(-25,-4), ha='center', size=d_font_size)
ax.annotate('libio', (145808, 639), textcoords='offset points', xytext=(25,3), ha='center', size=d_font_size)
ax.annotate('planet', (613597, 2314), textcoords='offset points', xytext=(-30,-4), ha='center', size=d_font_size)
ax.annotate('face', (1055308, 1687), textcoords='offset points', xytext=(-20,-10), ha='center', size=d_font_size)
ax.annotate('wiki', (22084, 144), textcoords='offset points', xytext=(20,-3), ha='center', size=d_font_size)

ax.grid() 
plt.rc('xtick', labelsize=12)    # fontsize of the tick labels
plt.rc('ytick', labelsize=12)  
plt.xlabel('Local hardness $H_{\epsilon=' + str(32) + '}$', size =13)
plt.ylabel('Global hardness $H_{\epsilon=' + str(4096) + '}$', size= 13)

plt.tight_layout()
plt.savefig('./results/graphs/fig5_dataset.svg', bbox_inches="tight")


