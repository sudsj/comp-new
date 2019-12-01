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
    

    int n,m;
    cin >> n;
    long long int a[n];
    For(i,0,n) cin >> a[i];
    cin >> m;
    long long int b[m];
   	For(i,0,m) cin >> b[i];
   	int da[n] = {0};
   	int db[n] = {0};
   	int inda = 0;
   	int indb = 0;
   	int flag = 0;
   	int ans = 0;
   	while(inda < n && indb < m){
   		if(a[inda] == b[indb]){
   			inda ++;
   			ans ++;
   			indb ++;
   		}else if(a[inda] > b[indb]){
   			//increment indb
   			b[indb + 1] += b[indb];
   			indb++;
   		}else if(a[inda] < b[indb]){
   			a[inda + 1] += a[inda];
   			inda ++ ;
   		}
   		// Debug(inda)
   		// Debug(indb)
   		if(inda >= n || indb >= m){
   			if(inda == n && indb == m){
   				flag = 0;
   				if(a[inda-1] != b[indb-1]) flag = 1;
   				break;
   			}else{
   				flag = 1;
   				break;
   			}
   			
   		}
   		// Debug(ans)
   	}
   	if(ans == 0) ans = -1;
   	if(flag == 1) ans = -1;
   	// Debug(flag)
   	cout << ans;
    ///////////
    return 0;
}