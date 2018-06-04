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
    int a[n];
    For(i,0,n) cin >> a[i];
    int g[300];
    int taken[300];
    For(i,0,256) g[i] = i;
    For(i,0,256) taken[i] = 0;
    For(i,0,n){
    	int cr = a[i];
    	int tr = a[i] + 1 - k;
    	if(g[cr] < cr || taken[cr] == 1){
    		//gr is already formed
    		a[i] = g[cr];
    		continue;
    	}
    	//gr not formed
    	if(tr < 0) tr = 0;
    	int csize = 1;
    	int start = cr,val = cr;
    	for(int j = cr-1; j >= tr; j--){
    		if(g[j] == j){
    			start--;val = j;csize++;
    		}else{
    			//gr already formed
    			int pgsize = j + 1 - g[j];//present gr size
    			if(pgsize + csize <= k){
    				//extend the group
    				val = g[j];
    			}else{
    				// Debug(j)
    				// Debug(g[j])
    				// Debug(cr)
    				break;
    			}
    		}
    	}
    	// Debug(start)
    	taken[start] = 1;
    	For(j,start,cr+1){
    		g[j] = val;
    	}
    	a[i] = g[cr];
    }
    For(i,0,n){
    	cout << a[i] << " ";
    	// Debug(taken[a[i]])

    }


    return 0;
}