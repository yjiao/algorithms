def readArray():
    return map(int, raw_input().split(' '))

def readInt():
    return int(raw_input())

n, t = readArray()

ar = [0] * 60
ar[0] = t
idx = 0
start = 0
for lv in range(1, n):
    start += lv
    for j in range(lv):
	parent = start - lv + j
	overflow = max(ar[parent] - 1, 0)
	ch1 = start + j
	ch2 = start+j+1

	ar[ch1] += overflow*0.5
	ar[ch2] += overflow*0.5

print sum([1 for i in ar if i >= 1.0])
