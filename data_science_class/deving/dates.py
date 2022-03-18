# proprietary to BEERA // DO NOT COPY

import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt 
from time import sleep
import seaborn as sns
import numpy as np 




df = pd.read_csv('10000_Sales_Records.csv', parse_dates=[7])
print('red')
df = df.sort_values('Ship Date',ascending=True)
df = df[df['Sales Channel'] == 'Online']


df = df.groupby(['Ship Date']).sum()

print(df)

exit()

df = df.sort_values('Ship Date',ascending=True)
df = df.sort_values('diff',ascending=True)
plt.figure()

plt.plot(df['Ship Date'], df['Total Revenue'])

plt.show()