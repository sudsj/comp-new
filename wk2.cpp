#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      ForD(i, m, n)     for(int i = m; i >= n; i--)
#define      fill(a,k)         For(i,0,sizeof(a)/sizeof(a[0])) a[i] = k;
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      in(n)             scanf("%d",&n)
#define      out(n)            printf("%d\n",n)
#define      llin(n)           scanf("%lld",&n)
#define      llout(n)          printf("%lld\n",n)
#define      Debug(x)          cout<<"> "<<#x<<" : "<<x<<endl
#define      DebugArr(a,n)     For(i,0,n) cout<<i<<" : "<<a[i]<<endl
#define      FAST              ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define      tests             int T; cin >> T; while(T--) 
 
typedef long long ll;
const int mod = 1000000007, N = 200005;const ll inf = 1e18;
 
// all varibles global :P 
string s;
int n;
 
void solve() {
	int l = 0, r= 0;
	For(i,0,n) {
	    if(s[i] == '(') l++;
	    else r++;
	    if(r > 2*l) {
	        cout << "NO\n";
	        return ;
	    }
	    
	}
	cout << "YES\n";
	
    return;
}
 
int main() {
 
    tests {
      	cin >> s;
      	n = s.length();
      	
        solve();
    }
 
    return 0;
}