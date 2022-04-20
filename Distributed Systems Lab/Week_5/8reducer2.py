import sys
total = [0] * 2
for line in sys.stdin:
	count, number = line.strip().split('\t', 1)
	total[int(number) % 2] += int(count)
print('Even count:\t', str(total[0]))
print('Odd count:\t', str(total[1]))
