import fileinput
transactions_count = 0
sales_total = 0
for line in fileinput.input():
	data = line.strip().split('\t')
	if len(data) != 2:
		continue
	current_key, current_value = data
	transactions_count += 1
	sales_total += float(current_value)
print(transactions_count, '\t', sales_total)
