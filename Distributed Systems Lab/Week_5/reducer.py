import sys

cword = None
ccount = 0
word = None

for line in sys.stdin:
    line = line.strip()
    word, count = line.split('\t',1)
    count = int(count)
    if cword == word:
        ccount += count
    else:
        if cword:
            print('%s\t%s'%(cword, ccount))
        cword = word
        ccount = count

print('%s\t%d'%(cword,ccount))