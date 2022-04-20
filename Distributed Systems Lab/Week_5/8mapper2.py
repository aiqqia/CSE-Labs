import sys
for line in sys.stdin:
	number, count = line.strip().split('\t', 1)
	print('%s%s%s' %(count, '\t', number))
