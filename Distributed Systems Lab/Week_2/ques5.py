x = [int(i) for i in input("Enter 3 user inputs: ").split()]
i = 0
while i<len(x) :
    if x[i]%2 == 0:
        print('Even')
    else:
        print('Odd')
    i+=1
