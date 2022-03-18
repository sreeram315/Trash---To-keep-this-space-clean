# proprietary to BEERA // DO NOT COPY

import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt 
from time import sleep
import seaborn as sns
import numpy as np 




# df = pd.read_csv('big_Sales_Records.csv')#, parse_dates=[7])
df = pd.read_csv('big_Sales_Records.csv')#, parse_dates=[7])
print('red')

# df = df.sort_values('Ship Date',ascending=True)
df.groupby(['Item Type']).sum().to_csv('byitemtype_data.csv')
exit()
# print(min(df['Ship Date']))

# print(df.groupby(['Sales Channel']).count())
# print(df['Sales Channel'].value_counts().to_dict()['Offline'])
df['Order Priority'].value_counts().to_csv('priority_count.csv')
# df.groupby(['Country']).sum().to_csv('stats_by_country.csv')
# print(df)
exit()


# print(len(df['Item Type'].unique()))
# print(len(df['Country'].unique()))
# print(len(df['Order Priority'].unique()))

df_count = pd.DataFrame({'Order_count': df.groupby(['Region']).size()}).reset_index()
df = df_count

plt.figure()
fig, ax = plt.subplots()
sns.set(style="darkgrid")
# start, end = 210, 410
# ax.yaxis.set_ticks(np.arange(start, end, 2))

axes = plt.gca()
# axes.set_xlim([xmin,xmax])
axes.set_ylim([210,325])
fig.autofmt_xdate()

annot = ax.annotate("", xy=(0,0), xytext=(-20,20),textcoords="offset points",
                    bbox=dict(boxstyle="round", fc="black", ec="b", lw=2),
                    arrowprops=dict(arrowstyle="->"))
annot.set_visible(True)




df_count.to_csv('region_to_no_of_sales.csv')
exit()
bars = plt.bar(df_count['Country'], df_count['Order_count'], width = 1 , align='center')



def update_annot(bar):
    x = list(df[df['Order_count'] == bar.get_y()+bar.get_height()]['Country'])[0]
    y = bar.get_y()+bar.get_height()
    annot.xy = (x,y)
    text = f'{x},{y}'
    annot.set_text(text)
    annot.get_bbox_patch().set_alpha(0.4)


def hover(event):
    vis = annot.get_visible()
    if event.inaxes == ax:
        for bar in bars:
            cont, ind = bar.contains(event)
            if cont:
                update_annot(bar)
                annot.set_visible(True)
                fig.canvas.draw_idle()
                return
    if vis:
        annot.set_visible(True)
        fig.canvas.draw_idle()


plt.xlabel('Countries')
plt.ylabel('Order Count')
plt.title('No. of orders by Countries')
fig.canvas.mpl_connect("motion_notify_event", hover)

plt.show()






















