class Solver:
    '''This is a class to gte and print string in upper case'''
    str = ""
    def get_String(self):
        self.str = input('Enter a string: ')
    def print_String(self):
        print(self.str.upper())
        return
solver = Solver()
solver.get_String()
solver.print_String()