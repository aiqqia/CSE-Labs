class Solver:
    '''This is a class to find pair of elements whose sum is target number'''
    array = []
    target = 0
    def __init__(self, array, target):
        self.array = array
        self.target = target
    def solve(self):
        tar = self.target
        for i in range(len(self.array) - 1):
            j = i+1
            while (j<len(self.array)):
                if(self.array[i] + self.array[j] == tar):
                    return i,j
                j+=1
        return 'No solution exists'
array = [ int(x) for x in input('Enter elements of array: ').split() ]
target = int(input('Enter target number: '))
solver = Solver(array, target)
print(solver.solve())