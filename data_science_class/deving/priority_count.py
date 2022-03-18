# proprietary to BEERA // DO NOT COPY

import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt 
from time import sleep
import seaborn as sns
import numpy as np 




df = pd.read_csv('priority_count.csv')

plt.figure()
plt.bar(df['Priority'], df['Count'])

plt.show()

print(df)