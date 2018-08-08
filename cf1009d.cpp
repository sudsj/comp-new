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

    int n,m; cin >> n >> m;
    if(m < n - 1){
    	cout << "Impossible";return 0;
    } 
    int mm = m;
    std::vector< pair< int, int > > v;
    For(i,1,n){
    	For(j,i+1,n+1){
    		if(__gcd(i,j) == 1){
    		 m--;
    		 v.push_back(make_pair(i,j));
    		}
    		if(m == 0) break;
    	}
    	if(m == 0) break;
    } 
 	if(m > 0){
 		cout << "Impossible";
 	}else{
 		cout << "Possible\n";
 		For(i,0,mm){
 			cout << v[i].first << " " << v[i].second << "\n";
 		}
 	}   	
    return 0;
}