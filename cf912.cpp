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


ll f[100001];
 
ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a; 
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
 
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
 return pow(n,MOD-2,MOD);
}
 
ll C(ll n, ll r, ll MOD)
{
 
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}


///////
int ops[1010] = {0};int ks[10] = {0};
int count(int n){
	int count=0;
	while(n!=0){
	  n = n&(n-1);
	  count++;
	}
	return count;
}
int op(int n){
	if(n == 1) return 0;
	int ans = 1;
	while(count(n) != 1){
		n = count(n);ans++;
	}
	return ans;
	// else return op(count(n))
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
 	    ///////////
 	    f[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++)
		f[i] = (f[i-1]*i)%mod;
 	// cout << C(10000,2,mod) << endl;


 	//////////    
 	long long int ans = 0;
 	For(i,1,1001){
 		ops[i] = op(i);
 		// ans = max(ans,op(i));
 		ks[ops[i]] ++;
 		// if(op(i) == 4) Debug(i);
 	}
 	// Debug(op(1000));
 	// cout <<ks[4];
 	string s;cin >> s;int k; cin >> k;
 	if(k >= 6){
 		cout << "0";return 0;
 	}
 	if(k == 0){
 		cout << "1";return 0;
 	}
 	int sl = s.length();int ones = 0,n,kf=k-1,x;
 	For(i,0,sl){
 		if(s[i] == '1'){
 			ones++;
 			//we can use this as 0 and control the rest
 			n = sl - 1 - i;//freely controllable places
 			//we want k - 1 operations
 			// kf = k-1;
 			// Debug(i)
 			For(j,ones-1,ones-1 + n + 1){//number of 1's
 				//we can have this many ones
 				// if(n == 0) Debug(j)
 				if(j == 0) continue;
 				if(ops[j] == kf){
 					x = j + 1 - ones;//free digits
 					if(x == 0){
 						ans += 1;
 					}else{
 						ans += C(n,x,mod);//n C x
 						if(ans >= mod) ans = ans%mod;
 					}
 				}
 			}

 		}
 	}
 	//check once finally for original number
 	if(ops[ones] == kf){
 		ans += 1;
 	}
 	if(ans >= mod) ans = ans%mod;
 	cout << ans;
    return 0;
}