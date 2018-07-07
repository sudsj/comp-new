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
int fac[2000];
int p = 998244353;
/* Iterative Function to calculate (x^y)%p
in O(log y) */
int power(int x, int y)
{
	int res = 1;	 // Initialize result
	// Debug(x) Debug(y)
	x = x % p; // Update x if it is more than or
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y%2 == 1) res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
		Debug(x) Debug(y)
	}
	// Debug(x) Debug(y)
	Debug(res)
	return res;
}

// Returns n^(-1) mod p
int modInverse(int n)
{	
	// Debug(power(n,p-2))
	return power(n, p-2);
}

// Returns nCr % p using Fermat's little
// theorem.
int nCrModPFermat(int n, int r)
{
// Base case
if (r==0) return 1;

	// Fill factorial array so that we
	// can find all factorial of r, n
	// and n-r
	
	

	return (fac[n]* modInverse((fac[r]) % p) * modInverse(fac[n-r])%p)%p;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

 	int n;cin >> n;
 	Debug(n)
 	int a[n];
 	For(i,0,n){
 		cin >> a[i];
 		Debug(a[i])
 	}
 	fac[0] = 1;
 	for (int i=1 ; i<=n+1; i++){
 		fac[i] = fac[i-1]*i%p;
 		// Debug(fac[i])
 	}
 	// Debug(p)
 	Debug(nCrModPFermat(3,2))
    return 0;
}