"""mapper.py"""
import sys
import pandas as pd
df = pd.read_csv('heart_disease_data.csv')
for age in df['age']:
	print('%s\t%s' %(age, 1))
