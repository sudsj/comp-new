import math as mth

def hexarea(theta):
	l0 = mth.sqrt(0.5*0.5 + 0.5)
	alpha = mth.degrees(mth.atan(1/mth.sqrt(2)))
	lp = l0*mth.cos(mth.radians(90-theta - alpha))
	area = mth.sqrt(2)*( (mth.cos(mth.radians(theta)))/2 + lp )
	return area

t = input()
t = int(t)
for i in range(t):
	k = float(input())
	

	print('Case #',i+1,':',sep='')
	if(k < 1.4142135623730951) :
		k = mth.asin(k/mth.sqrt(2)) - (mth.pi)/4.0
		# print(k)
		print(-0.5*mth.sin(k),0.5*mth.cos(k),0)
		print(0.5*mth.cos(k),0.5*mth.sin(k),0)
		print(0,0,0.5)
	else:
		# larger areas
		# print(hexarea(0),hexarea(35.26),hexarea(42),hexarea(15))
		theta = mth.asin(k/mth.sqrt(3)) - mth.atan(mth.sqrt(2))
		# print(mth.degrees(theta))
		tt = 1/mth.sqrt(2)
		tt = tt*0.5
		print(tt,tt*mth.cos(theta)*(-1.0),tt*mth.sin(theta))
		print(tt,tt*mth.cos(theta),tt*mth.sin(theta)*(-1.0))
		print(0,0.5*mth.sin(theta),0.5*mth.cos(theta))

	

	




