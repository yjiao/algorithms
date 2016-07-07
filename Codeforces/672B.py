def readArray():
    return map(int, raw_input().split(' '))

def readInt():
    return int(raw_input())

def solve(n, word):
    if n > 26:
	return '-1'
    
    ch = set(list(word))
    return len(word) - len(ch)
#    ch = [ord(w)-ord('a') for w in word]
#    print ch
#    for i in range(26):
#	for j in range(26):
#	    pass



n = readInt()
word = raw_input()

print solve(n, word)
