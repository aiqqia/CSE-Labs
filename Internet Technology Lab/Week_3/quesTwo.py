#!/usr/bin/python -tt
import sys

def reverse(file_r,file_w):
    f1 = open(file_r,'r')
    f2 = open(file_w,'w')
    text = f1.read()
    text_w = text[::-1]
    f2.write(text_w)
    f1.close()
    f2.close()

def main():
    f1 = input("Enter file to read: ")
    f2 = input("Enter file to write in: ")
    reverse(f1,f2)

if __name__ == '__main__':
    main()