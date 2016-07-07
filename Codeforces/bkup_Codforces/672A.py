def readArray():
    return map(int, raw_input().split(' '))

def readInt():
    return int(raw_input())

n = readInt()
string = ''
for i in range(1, n+1):
    string += str(i)

print string[n-1]
