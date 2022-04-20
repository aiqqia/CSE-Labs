import pandas as pd
df = pd.read_csv('covid_19_data.csv')
for country in df['Country/Region']:
	country = country.strip("(),'")
	print('%s\t%d' %(country, 1))
