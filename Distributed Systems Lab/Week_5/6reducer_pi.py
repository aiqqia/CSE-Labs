import sys
sum = 0
for line in sys.stdin:
	line = line.strip()
	word, count = line.split('\t', 1)
	try:
		count = float(count)
	except ValueError:
		continue
	sum += count

print('%1.5f\t0' %sum)
