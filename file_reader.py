# File Reader: gives out information about a chosen file
# Iván Butera

import sys

#supposing to-read file is on current directory...
fname = input('Enter file name: ')
fdir = sys.path[0] + '\\' + fname
fhan = open(fdir, 'r')


char_count = 0
word_count = 1
for char in fhan.read():    
    if (char == ' ' or char == '\n'):
        word_count = word_count + 1
        char_count = char_count + 1
    else:
        char_count = char_count + 1

fhan = open(fdir, 'r')
line_count = 0
for line in fhan:
    line_count = line_count + 1

print('Character count:', char_count)
print('Word count:', word_count)
print('Line count:', line_count)


fhan = open(fdir, 'r')
fin = fhan.read()
search = input('Enter a word to search for: ')
search_pos = fin.find(search)

print('The first appearance of', '"' + search + '"', 'is at position', search_pos)




fhan.close()


