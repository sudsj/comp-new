import random
import progressbar

n = 5
m = 10000000000000
count = 0
def findmin(lis):
	mans = 10000000000
	n = len(lis)
	deli = 0
	for i in range(len(lis)):
		if(lis[i] + lis[(i+1)%n] < mans):
			deli = i
			mans = lis[i] + lis[(i+1)%n]
	return mans		

def vsimple(lis):
	if len(lis) == 1:
		return 0
	else:
		mans = 10000000000
		n = len(lis)
		# tlis = [x for x in lis]
		# olis = [x for x in lis]
		deli = 0
		for i in range(len(lis)):
			if(lis[i] + lis[(i+1)%n] < mans):
				deli = i
				mans = lis[i] + lis[(i+1)%n]
		tp = lis[deli]
		l = len(lis)
		pty = lis[(deli+1)%l] + tp
		lis[(deli+1)%l] += tp
		lis.pop(deli)
		return  pty + vsimple(lis)

def simple(lis):
	if len(lis) == 1:
		return 0
	else:
		mans = 10000000000
		n = len(lis)
		tlis = [x for x in lis]
		olis = [x for x in lis]
		deli = 0
		for i in range(len(lis)):
			if(lis[i] + lis[(i+1)%n] < mans):
				deli = i
				mans = lis[i] + lis[(i+1)%n]
		tp = lis[deli]
		l = len(lis)
		pty = lis[(deli+1)%l] + tp
		lis[(deli+1)%l] += tp
		lis.pop(deli)
		# second min
		sdeli = 0
		mans = 10000000000
		for i in range(len(tlis)):
			if(i == deli):
				continue	
			if(tlis[i] + tlis[(i+1)%n] < mans):
				sdeli = i
				mans = tlis[i] + tlis[(i+1)%n]
		tp = tlis[sdeli]
		l = len(tlis)
		spty = tlis[(sdeli+1)%l] + tp
		tlis[(sdeli+1)%l] += tp
		tlis.pop(sdeli)	
		# print(lis)
		# print(pty)
		if(spty + findmin(tlis) < pty + findmin(lis)):
			# print("diff = ", findmin(tlis) - findmin(lis), spty + findmin(tlis) - pty - findmin(lis))
			# print(olis)
			# print(tlis)
			# print(lis)
			# print("\n")
			return spty + simple(tlis)
		else:
		 	return  pty + simple(lis)		
		# return  min(pty + simple(lis), spty + simple(tlis))

def penalty(lis):
	# count+=1
	if len(lis) == 1:
		return 0
	else:
		deli = random.randint(0,len(lis)-1)
		tp = lis[deli]
		l = len(lis)
		pty = lis[(deli+1)%l] + tp
		lis[(deli+1)%l] += tp
		lis.pop(deli)
		# print(lis)
		# print(pty)
		return  pty + penalty(lis)

# for j in range(101):
# 	lis = []
# 	for i in range(8):
# 		lis.append(random.randint(1,10))
# 	# print(lis)
# 	# lis = [6, 5, 3, 3, 5]
	# mans = 1000000000000000000
	# for i in range(1000):
	# 	tlis = [x for x in lis]
	# 	mans = min(mans,penalty(tlis))
# 	tlis = [x for x in lis]
# 	vtlis = [x for x in lis]
# 	sans = simple(tlis)
# 	vsans = vsimple(vtlis)
# 	# print(j)
# 	if(sans!= mans and mans != vsans):
# 		print(lis)
# 		print(mans,sans,vsans)
# 		print("\n")
# 	# print(j,lis)
# 	# print(mans,sans)	
# 	if(j%100 == 0):
# 		print(j/100,"%% complete")
# print("finished")

count = 0
m = 1000000000000
d = {}
def solve(lis,k,penalty,n):
	tlis1 = [x for x in lis]
	if(k==n):
		# print (penalty)
		global m
		m = min(m,penalty)
	else:
		if k==1:
			for i in range(n):
				d[i+1] = 0
		l = len(tlis1)
		for i in range(l):
			tlis1 = [x for x in lis]
			t = tlis1[(i+1)%l] + tlis1[i]
			tlis1[(i+1)%l] = tlis1[(i+1)%l] + tlis1[i]
			tlis1.pop(i)
			solve(tlis1,k+1,penalty + t,n)




# lis = [2,3,4,9,4]
# m = 1000000000000
# solve(lis,1,0,len(lis))
# print(m)

cases = 1
print(cases)
for j in progressbar.progressbar(range(cases)):
	lis = []
	m = 1000000000000
	size = 25
	for i in range(size):
		d[i+1] = 0
		lis.append(random.randint(1,1000000000))
	# lis = [4,9,4,4]
	# solve(lis,1,0,len(lis))
	mans = 1000000000000000000
	for i in progressbar.progressbar(range(10000000)):
		tlis = [x for x in lis]
		mans = min(mans,penalty(tlis))
	# print(lis,m)
	print(size)
	for x in lis:
		print(x, end = ' ')
	print()
	print(mans)
