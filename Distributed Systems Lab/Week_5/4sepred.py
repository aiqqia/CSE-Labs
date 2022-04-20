from itertools import groupby
from operator import itemgetter
import sys

def red_mapper_output(file, seperator = '\t'):
	for line in file:
		yield line.rstrip().split(seperator, 1)

def main(seperator = '\t'):
	data = red_mapper_output(sys.stdin, seperator)
	for current_word, group in groupby(data, itemgetter(0)):
		try:
			total_count = sum(int(count) for current_word, count in group)
			print('%s%s%d' %(current_word, seperator, total_count))
		except ValueError:
			pass

if __name__ == '__main__':
	main('\t->')
