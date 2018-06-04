#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS


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
// std::vector<long long int> v[62];
set<long long int> s;
long long int mm = 1e18;

// long long int pow(int a, int p){
// 	long long int ans = 1;
// 	// if(p )
// 	while(p > 0){
// 		 ans *= 
// 	}
// }

ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    For(i,2,1000001){
    	long long int n = i*i*1LL;
    	n *= i;
    	if(n > mm) break;
    	For(j,3,60){
    		s.insert(n);
    		// v[j].push_back(n);
    		n *= i;	
    		if(n > mm) break;
    	}
    }
    // Debug(s.size())
    std::vector<long long int> v(s.begin(),s.end()),w;
    // Debug(v.size())
    For(i,0,v.size()){
    	if(v[i] > 0){
    	 long long int x = sqrt(v[i]);
    	 if(x*x == v[i]) continue;
    	 w.push_back(v[i]);
    	}
    }
    sort(w.begin(), w.end());
    // Debug(w[24])

    // cout << endl;
    // cout << w.back();
    tests{
    	long long int l,r,ans=0;
    	cin >> l >> r;
    	long long int lw = root(l);
    	long long int hr = root(r);
    	
    	ans = hr - lw;if(lw*lw == l) ans++;
    	// if(l == 1) ans++;
    	int ll = (int) (lower_bound(w.begin(), w.end(), l) - w.begin());
    	int lr = (int) (lower_bound(w.begin(), w.end(), r) - w.begin());
    	if(lower_bound(w.begin(), w.end(),l) != w.end()) {
    		if(w[lr] > r) ans--;
    		ans += (lr - ll+1);
    	}
    	cout << ans << "\n";

    }	
    return 0;
    
}