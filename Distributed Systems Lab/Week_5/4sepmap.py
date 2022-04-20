"""A more advanced mapper using python iterators and generators"""
import sys
import pandas as pd

def main(seperator = '\t'):
	G = pd.read_excel('German Credit.xlsx', sheet_name = 'Sheet1')
	for index, row in G.iterrows():
		print('%d%s%d' %(row['DurationOfCreditInMonths'], seperator, 1))

if __name__ == '__main__':
	main('\t->')
