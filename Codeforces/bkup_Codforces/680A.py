def readArray():
    return map(int, raw_input().split(' '))

def readInt():
    return int(raw_input())

from collections import defaultdict;
A = readArray()
cnt = defaultdict(int)
for a in A:
    cnt[a] += 1

throw = 0
for key, val in cnt.iteritems():
    if val > 1:
	val = min(val, 3)
	if key * val > throw:
	    throw = key*val

print sum(A) - throw


