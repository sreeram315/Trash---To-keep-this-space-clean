# proprietary to BEERA // DO NOT COPY

import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt 
from time import sleep
import seaborn as sns
import numpy as np 




df = pd.read_csv('50000_Sales_Records.csv')#, parse_dates=[7])


print(df.groupby(['Region', 'Item Type']).count())