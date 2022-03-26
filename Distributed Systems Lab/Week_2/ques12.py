x = [int(i) for i in input().split()]
x = list(filter(lambda i: i%2 != 0, x))
print(x)