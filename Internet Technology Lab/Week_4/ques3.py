class Solver:
    '''This is a class to implement pow(x,n)'''
    x,n = 0,0
    result = 1
    def __init__(self, x, n):
        self.x = x
        self.n = n
    def solve(self):
        i = 1
        while(i<=n):
            self.result = self.result * self.x
            i+=1
        return 'pow(x,n) is {0}'.format(self.result)
x = int(input('Enter number x: '))
n = int(input('Enter number n: '))
solver = Solver(x, n)
print(solver.solve())