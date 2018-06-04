import math
tests = input();
tests = int(tests);
for tt in range(tests):
	print("Case #",tt+1,": ",sep='',end='');
	# n = input();
	val = list(map(int, input().strip().split()));
	n = val[0];p=val[1];
	# n = int(n);
	# p = input(p);
	p = float(p);
	wid = [];
	ht = [];
	for xx in range(n):
		val = list(map(int, input().strip().split()));
		# wi = input();hi = input();
		wi = float(val[0]); hi = float(val[1]);
		# print(wi)
		wid.append(wi);
		ht.append(hi);
	# print(w);	
	w = float(wid[0]);
	h = float(ht[0]);
	smin = 2*min(w,h);
	smax = 2*math.sqrt(w*w + h*h);
	dif = smax-smin;
	# ca = 0.0;
	ca = n*2*(w+h);
	ca = float(ca);
	count = 0;
	for xx in range(n):
		if(ca + smin <= p):
			ca = ca+smin;
			count = count+1;
		else:
			break;

	for xx in range(count):
		if(ca + dif <= p):
			ca = ca+dif;
		elif(ca <= p and ca + dif > p):
			ca = p;break;	
		else:
			break;		
	print(ca)		