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

ll mpow(ll x,int n,ll p) {
    ll res = 1;
    x %= p;
    while(n > 0) {
        if(n & 1) res = (res*x*1LL) % p; 
        n = n>>1;
        x = (x*x*1LL) % p;
    }
    return res;
}

long long int b;
int n;


int main() {
    tests{
        
        cin >> b;
        cin >> n;
        long long int bpows[n+1];
        long long int gcds[n+1];
        bpows[0] = 1;
        For(i,1,n+1) bpows[i] = mpow(b,i,mod)%mod;
        For(i,1,n+1) {
            gcds[i] = __gcd(i,n);
        }
        long long int ans = 0;
        For(i,1,n+1) {
            if(ans >= mod) ans = ans%mod;
            ans += 1LL*bpows[i]*gcds[i];
            if(ans >= mod) ans = ans%mod;
        }
        cout<<ans<<endl;

    }
    
    return 0;
}