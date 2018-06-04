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
std::vector<int> v(5001000, 0);

long long int mpow(long long int x,long long int n,long long int p) {
    long long int res = 1;
    x %= p;
    while(n > 0) {
        if(n & 1) res = (res*x*1LL) % p; // if y is odd
        n = n>>1; // n/2
        x = (x*x*1LL) % p;
    }
    return res;
}

void pre(int r){
	v[1] = 0;v[2] = 1;v[3] = 3;
	long long int best,tp;
	int numg;
	For(i,4,r+1){
		int up = sqrt(i);up += 2;
		best = i*(i-1);
		best = best/2;//base
		For(j,2,up){
			if(i%j == 0){
				//form group of size j
				numg = i/j;
				tp = i*(j-1);
				tp = tp/2;
				tp += v[numg];
				best = min(best,tp);
				//form group of size i/j
				tp = i*(numg-1);
				tp = tp/2;
				tp += v[j];
				best = min(best,tp);
			}
		}
		v[i] = best;
		// Debug(v[i])
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

    long long int t,l,r,ans=0,step;
    cin >> t >> l >> r;
    pre(r);
    For(i,l,r+1){
    	step = v[i];
    	step = step%mod;
    	step *= mpow(t,i-l,mod);
    	step = step%mod;
    	ans += step;
    	ans = ans%mod;
    }
    cout << ans;

 	   	
    return 0;
}