"""reducer.py"""
import sys
lastNumber = 0
count = 0

for line in sys.stdin:
	curNumber, curCount = line.strip().split('\t')
	curNumber = int(curNumber)
	curCount = int(curCount)

	if count > 0 and lastNumber != curNumber:
		print('%d%s%d' %(lastNumber, '\t', count))
		count = 0
	lastNumber = curNumber
	count += curCount

if count > 0:
	print('%d%s%d' %(lastNumber, '\t', count))
