import sys
mostFreq = []
currentMax = -1

for line in sys.stdin:
	count, word = line.strip().split('\t', 1)
	count = int(count)
	if count > currentMax:
		currentMax = count
		mostFreq = [word]
	elif count == currentMax:
		mostFreq.append(word)

for word in mostFreq:
	print('%s\t%s' %(word, currentMax))
