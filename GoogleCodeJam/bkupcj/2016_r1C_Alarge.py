def solve(senators):
    print '----------'
    ans = []
    n = len(senators)
    is1 = [False]*n
    for i, s in enumerate(senators):
	if s == 1:
	    is1[i] = True;

    # get to [1,1,1...]
    while not all(is1):
	rval = max(senators)
	iremove = [i for i in range(n) if senators[i] == rval]
	if len(iremove) == 2:
	    ans.append(iremove)
	    for ir in iremove:
		senators[ir] -=1
		if senators[ir] == 1:
		    is1[ir] = True
	else:
	    idx = iremove[0]
	    ans.append([idx])
	    print 'ir:', idx
	    print senators[idx]
	    senators[idx] -= 1
	    print senators[idx]
	    if (senators[idx] == 1):
		print 'This is 1:', senators[idx]
		is1[idx] = True
	rval = max(senators)
    
	print senators
	print is1, rval


    # remove x at a time
    left = sum(senators)
    while left > 0:
	if left == 3:
	    a = is1.index(True)
	    ans.append([a]) 
	    senators[a] -= 1
	    is1[a] = False

	elif left == 2:
	    a = is1.index(True)
	    senators[a] -= 1
	    is1[a] = False

	    b = is1.index(True)
	    senators[b] -= 1
	    is1[b] = False

	    ans.append([a, b]) 

	else:
	    a = is1.index(True)
	    ans.append([a]) 
	    senators[a] -= 1
	    is1[a] = False
	
	left = sum(senators)
	print senators
    for i, a in enumerate(ans):
	ans[i] = ''.join( [chr(aa+ ord('A') ) for aa in a] )

    return ' '.join(ans)



file = 'A-large.in'
fileout = 'A-large.out'

cases = []
with open(file) as f:
    T = int(f.readline())
    # read in test cases
    for t in range(T):
	f.readline()
	cases.append(map(int, f.readline().split(' ')))

f = open(fileout, 'w')
# solve each test case
# + ord('a')
for i, c in enumerate(cases):
    soln = solve(c)
    f.write('Case #' + str(i+1) + ': ' + str(soln) + '\n')
f.close()