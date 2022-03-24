str = input('Enter a sentence with words: ')
words = str.split(' ')
for i in range(len(words)-1):
    j = i+1
    min = i
    while j<len(words):
        if (words[j]<words[min]):
            min = j
        j = j+1
    temp = words[i]
    words[i] = words[min]
    words[min] = temp

print(words)