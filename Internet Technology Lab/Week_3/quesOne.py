a = int(input('Enter first number: '))
b = int(input('Enter second number: '))
c = int(input('Enter 1 for Addition, 2 for Subtraction, 3 for Multiplication, 4 for Division \n'))
if (c == 1):
    print('Sum is ',(a+b))
elif(c == 2):
    print('Difference is ',(a-b))
elif(c == 3):
    print('Product is ',(a*b))
elif(c == 4):
    print('Quotient is ',(a/b))
else:
    print('Invalid Choice')