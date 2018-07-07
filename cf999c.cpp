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

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;int k;cin >> n >> k;
    string s; cin >> s;
    int a[26] ={0};
    For(i,0,n){
    	a[s[i]-'a'] += 1;
    }
    For(i,0,26){
    	// Debug(a[i])
    	if(a[i] >= k){
    		a[i] -= k;
    		k = 0;
    		
    	}else{
    		k -= a[i];
    		a[i] = 0;
    	}
    	// Debug(a[i])
    }
    std::vector<char> v;
    for(int i = n-1;i>=0;i--){
    	if(a[s[i]-'a'] > 0){
    		v.push_back(s[i]);
    		a[s[i]-'a'] -= 1;
    	}
    }
    // Debug(v.size())

	for(int i = v.size()-1;i>=0;i--){
		cout << v[i];
	}   
	cout << "\n";
 	//   	
    return 0;
}