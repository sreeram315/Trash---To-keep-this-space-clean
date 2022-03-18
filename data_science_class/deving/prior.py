# proprietary to BEERA // DO NOT COPY

import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt 
from time import sleep
import seaborn as sns
import numpy as np 




df = pd.read_csv('100_Sales_Records.csv', parse_dates=[5, 7])
df = df[df['Sales Channel'] == 'Online']

df = df[['Order Priority', 'Order Date', 'Ship Date']]

df['diff'] = df['Ship Date'] - df['Order Date']


def defff(row):
	a = int(row['diff'].days)
	if row['Ship Date'].year >= 2013: a -= 3
	if row['Ship Date'].year == 2014: a -= 6
	if row['Ship Date'].year >= 2014: a -= 6
	if row['Ship Date'].year >= 2015: a -= 2
	if row['Ship Date'].year >= 2016: a -= 3
	return a


df = df.sort_values('Ship Date',ascending=True)
# df['diff'] = str(df['diff'])
# print(df)
df['deff'] = 0

# for index, row in df.iterrows():
# 	row['deff'] = int(row['diff'].days)
# 	print(int(row['diff'].days))
# print(df)

df['deff'] = df.apply(defff, axis = 1)
# print(df)

df.to_csv('priorty.csv')
exit()
print(df)

# df = df.sort_values('diff',ascending=True)
plt.figure()

plt.plot(df['Ship Date'], df['deff'])

plt.show()
