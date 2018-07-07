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
    int n,k;cin >> n >> k;
    int a[n],c[n]; long long int ans[n];
    For(i,0,n) cin >> a[i];
    For(i,0,n) cin >> c[i];
    std::vector< pii > v;
    For(i,0,n){
    	// Debug(a[i])
    	v.push_back(make_pair (a[i],c[i]));
    }
    map< long long int, long long int > m;
    sort(v.begin(), v.end());
    int ls = 0;
    // int siz
    int s[10] = {0};int mins = 0;long long int sum = 0;
    For(i,0,n){
    	// Debug(v[i].first)
    	
    		
    	
    	int kills = 0;
    	long long int ex = sum;
    	// for(int j = i-1;j >= 0;j--){
    	// 	if(kills >= k) break;
    	// 	if(v[i].first > v[j].first){
    	// 		ex += v[j].second*1LL;
    	// 		kills++;
    	// 	}
    	// }
    	// // pii tp = make_pair()
     //    // ans[i] = ex ;//+ v[i].second;
        long long int indd = v[i].first*1LL;
        m[ indd] = ex;
    	if(v[i].second > mins){
    			For(j,0,k){
    				if(s[j] == mins){
    					
    					s[j] = v[i].second;break;
    				}
    			}
    			int minn = 1000000001;
    			sum = 0;
    			For(j,0,k){
    				// Debug(s[j])
    				minn = min(minn,s[j]);
    				sum += s[j]*1LL;
    			}
    			mins = minn;
    			// Debug(mins)
    	}
    	// Debug(ex)
    }

    For(i,0,n){
    	long long int indd = a[i]*1LL;
    	ans[i] = c[i]*1LL + m[a[i]]*1LL;
    	// Debug(m[a[i]])
    	cout << ans[i] << " ";
    }
 	//   	
    return 0;
}