#include <bits/stdc++.h>
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
int n;
long double xx[200000];
long double yy[200000];
long double eps = 1e-6;
bool ccheck(long double x, long double r){
	long double cx = x;long double cy = r;
	long double dist,rs = r*r;
	For(i,0,n){
		dist = (xx[i]-cx)*(xx[i]-cx)  + (yy[i]-cy)*(yy[i]-cy);
		if(dist > rs){
			return false;
		}
	}
	return true;
}

long double rfind(long double x, long double low, long double high){
	long double r = low + high;
	long double one = 1.0;
	long double two = 2.0;
	r = r/two;
	long double dif = high - low;
	long double div = max(one,high);
	dif = dif/div;
	// Debug(x)
	// Debug(dif)
	// Debug(r)	
	if(dif < 1e-10){
		return r;
	}
	// Debug(ccheck(x,r))
	// Debug(low)
	// Debug(high)
	if(ccheck(x,r)){
		//reduce
		return rfind(x,low,r);
	}else return rfind(x,r,high);
}

double rsearch(double x){
	double rmax = 0.0;
	double r = 0.0;
	For(i,0,n){
		r = (xx[i]-x)*(xx[i]-x) + yy[i]*yy[i];
		r = r/(2.0*abs(yy[i]));
		rmax = max(rmax,r);
	}
	return rmax;
}

long double xfind(long double low, long double high){
	long double x  = low + high; x = x/2.0;
	long double dif = high - low;
	long double one = 1.0;
	long double div = max(one,high);
	dif = dif/div;
	// cout << "x = " << x << " with low = " << low << " high = " << high<<"\n";
	if(dif < 1e-9){
		return x;
	}
	// long double r = rfind(x,0.0,1e15);
	// long double rl = rfind(x-eps,0.0,1e15);
	// long double rr = rfind(x+eps,0.0,1e15);
	long double r = rsearch(x);
	long double rl = rsearch(x-eps);
	long double rr = rsearch(x+eps);
	// Debug(r)
	// Debug(rl)
	// Debug(rr)
	if(r <= rl && r <= rr){
		return x;
	}
	if(rl <= r){
		//go left
		return xfind(low,x);
	}else{
		//go right
		
		return xfind(x,high);
	}

}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout << setprecision(15);
    cin >> n;
    long double xmin = 1e8;
    long double xmax = -1e8;
    bool pos = 0;bool neg = 0;
    For(i,0,n){
    	cin >> xx[i] >> yy[i];
    	if(yy[i] > 0) pos = 1;
    	if(yy[i] < 0) neg = 1;
    	xmin = min(xmin,xx[i]);
    	xmax = max(xmax,xx[i]);
    }
    if(pos && neg){
    	cout << "-1";
    	return 0;
    }
    long double x = xfind(xmin,xmax);
    // Debug(x)
    long double r = rsearch(x);
    cout << r;

    ///////////
    return 0;
}