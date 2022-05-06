import sys
import pandas as pd
import fileinput

# df = pd.read_csv('covid_19_data.csv')

# for age in df['Province/State']:
#     print("%s\t%s"%(age,1))
flag = 0

for line in fileinput.input():
    if flag == 0:
        flag = 1
        continue
    words = line.strip().split(',')
    print("{0}\t{1}".format(words[3], words[5]))
