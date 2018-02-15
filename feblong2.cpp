#include <bits/stdc++.h>
#include <time.h>
using namespace std;
typedef long long ll;
#define Debug(x) cout << "> " << #x << " : " << x << "\n";
#define DebugArr(a,n) For(i,0,n) cout << i << " : " << a[i] << "\n";
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define ForD(i,a,b) for(int i=(a);i>(b);i--)
#define tests int t; cin>>t; while(t--)
#define Imax INT_MAX
#define Imin INT_MIN
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define sz(a) int((a).size())
#define pb push_back
#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
/////////////////////////////////////////////////////////////////////

long long int imsq = 1;

pair<long long int, long long int> pairmod(pair<long long int, long long int> a){
		long long int ar = a.first,ai=a.second;
		ar = ar%mod;
		ai = ai%mod;
		return make_pair(ar,ai);
}

pair<long long int, long long int> multmod(pair<long long int, long long int> a, pair<long long int, long long int> b){
	long long int ar = a.first,ai=a.second;
	long long int br = b.first, bi = b.second;
	long long int pr,pi;
	pr = ar*br;
	pr -= ai*bi*imsq;
	pr = pr%mod;
	pi = pi%mod;
	pi = ar*bi + br*ai;
	pi = pi%mod;
	return make_pair(pr,pi);
}
 

pair<long long int, long long int> fste(pair<long long int, long long int> b, long long int exp){
	pair<long long int, long long int> res;
	res = make_pair(1,0);
	double resmr,resmi,bmr,bmi;
	while(exp > 0){
		if(exp%2 == 1){
			// res = res*b;
			res = multmod(res,b);
			res = pairmod(res);
		}
		b = multmod(b,b);
		b = pairmod(b);
		exp /= 2;
	}
	res = pairmod(res);
	return res;
}
long long int fast_exp(long long int base, long long int exp) {
    long long int res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

 
long long int mul_inv(long long int a, long long int b)
{
	long long int b0 = b, t, q;
	long long int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

long long int gcd2(long long int a, long long int b){
	if(b == 0) return a;
	return gcd2(b,a%b);
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
 	    clock_t t;
        t = clock();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);
    long long int l,d; long long int time;
    For(i,2,1000){
    	For(j,1,i){
    		l = i*10000; d = j*4050;
    		For(tim,2,4){
    			time = tim;
    			imsq = l*l - d*d;
    			pair<long long int, long long int> ansp;
    			ansp = fste(make_pair(d,1),time);
    			// cout << ansp.first << " " << ansp.second;
    			//dealing with denominator
    			long long int n,den,len=l;
    			n = ansp.first;
    			den = fast_exp(len,time-1);
    			long long int g;
    			// Debug(n)
    			n = n%mod;
    			den = den%mod;

    			long long int cn=0,cd=1;
    			if(time == 2){
    				cn = 2*((d*d)%mod); cn  -= (l*l)%mod;
    				cd = l;
    			}else{
    				cn = 4*(d*((d*d)%mod))%mod; cn  -= 3*((d*(l*l)%mod)%mod);
    				cd = l*l;
    			}
    			// Debug(l)
    			cn = cn%mod;
    			if(cn != n){
    				cout << "l is " << l << " d is " << d << "\n";
    				Debug(time)
    				Debug(n)
    				Debug(cn)
    			}
    			cd = cd%mod;
    			if(cd != den){
    				Debug(den)
    				Debug(cd)
    			}
    			g = gcd2(n,den);
    			n = n/g;
    			den = den/g;
    			// Debug(den)
    			// Debug(mod)
    			den = mul_inv(den, mod);
    			// Debug(den)
    			// Debug(n)
    			long long int ans = n*den;
    			// Debug(ans)
    			ans = ans%mod;
    			// Debug(ans)
    			if(ans < 0) ans += mod;
    			// Debug(ans)
    			// cout << ans << "\n";
    		}
    	}
    }

        // fun();
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
     	Debug(time)
        printf("fun() took %f seconds to execute \n", time_taken);

   

 	   	
    return 0;
}
