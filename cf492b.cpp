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
vector<long long> f(1101,1);

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD)
{
	if(n < r) return 0;
    
    
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,r,p;
    p = 998244353;

    for (int i=2; i<=1100;i++){
        f[i]= (f[i-1]*i) % p;
    }
    cin >> n;
    int a[n];
    For(i,0,n) cin >> a[i];
    long long int fans = 0;
    long long int ans[n+100] = {0};
    // Debug(C(1,5,p))
    for(int i = n-1;i >=0;i--){
    	// ans[i] = ans[i+1];
    	if(a[i]>0){
    		//only can start subsequence with a1 > 0
    		if(n-1-i < a[i]) continue;
    		int start = i+1;
    		// Debug(i+1)
    		ans[i] = C(n-1-i,a[i],p);
    		// Debug(ans[i])
    		For(j,i+2,n){
    			ans[i] += C(j-1-i,a[i],p)*ans[j];
    			if(ans[i]>p) ans[i] = ans[i]%p;
    			
    		}
    		// Debug(ans[i])
    	}
    }
    For(i,0,n){
    	fans += ans[i];
    	if(fans>p) fans = fans%p;
    }
    cout << fans
;    return 0;
}