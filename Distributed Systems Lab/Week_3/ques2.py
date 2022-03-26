import numpy as np

A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(A)
rowSum = np.sum(A, axis = 1)
print('Row Sum is ', rowSum)
colSum = np.sum(A, axis = 0)
print('Column Sum is ', colSum)