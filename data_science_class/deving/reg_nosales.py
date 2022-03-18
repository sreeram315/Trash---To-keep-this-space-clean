# proprietary to BEERA // DO NOT COPY

import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt 
from time import sleep
import seaborn as sns
import numpy as np 


df = pd.read_csv('region_to_no_of_sales.csv')


sns.set(style="darkgrid")
plt.figure()
fig, ax = plt.subplots()
plt.barh(df['Region'], df['Order_count'])#, width = 0.2)


plt.xlabel('No of Orders')
plt.ylabel('Region')
plt.title('No. of orders by Region')

for i, v in enumerate(list(df['Order_count'])):
	if len(list(df['Region'])[i]) > 20:ax.text(0 , i , str(list(df['Region'])[i]), color='black')
	if v < 40000: v += 10000
	ax.text(v , i , str(v), color='blue', fontweight='bold')
	print(i,v)

# for i, v in enumerate(list(df['Region'])):
#     ax.text(v , i , str(v), color='blue', fontweight='bold')
#     print(i,v)

fig.autofmt_xdate()
fig.savefig('sales_by_region.png', bbox_inches='tight')
plt.show()

print(df)