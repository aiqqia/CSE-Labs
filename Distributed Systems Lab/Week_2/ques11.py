x = [11,-21,0,45,66,-93]
p,n = 0,0
for i in x:
    if i>=0 : 
        p+=1
    else:
        n+=1
print('There are {0} positive numbers and {1} negative numbers'.format(p,n))