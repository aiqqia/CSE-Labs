x = [int(i) for i in input("Enter 3 user inputs: ").split()]

max = x[0]
for i in range(len(x)):
    if max < x[i]:
        max = x[i]

print('The largest number is ', str(max))


