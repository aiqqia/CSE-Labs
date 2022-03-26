import numpy as np

x = [float(i) for i in input().split()]
A = np.array(x)
print(A)
t = tuple([float(i) for i in input().split()])
B = np.array(t)
print(B)
C = np.zeros((3, 4))
print(C)
D = np.reshape(C, (2, 2, 3))
print(D)
E = np.arange(0, 20, 5)
print(E)
F = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(np.min(F, axis=1), np.min(F, 0), np.max(F, 1), np.max(F, 0), np.sum(F, 1), np.sum(F, 0))