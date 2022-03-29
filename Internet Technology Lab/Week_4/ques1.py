class Solver:
    '''This is a class to find unique subsets'''
    array = []
    def __init__(self, array):
        self.array = array
    def solve(self):
        return self.subsetsRecur([], sorted(self.array))
    def subsetsRecur(self, current, sset):
        if sset:
            return self.subsetsRecur(current, sset[1:]) + self.subsetsRecur(current + [sset[0]], sset[1:])
        return [current]
array = [ int(x) for x in input('Enter distinct elements of array: ').split() ]
solver = Solver(array)
print(solver.solve())