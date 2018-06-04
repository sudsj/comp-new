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

    tests{
    	int m,cost,k,items;cin >> m >> items;
    	std::vector<int> v[items];
    	For(i,0,items){
    		cin >> k;
    		For(j,0,k){
    			cin >> cost;
    			v[i].push_back(cost);
    		}
    	}
    	int r[items+1][m+1] = {0};//stores reachable states
    	For(i,0,items+1){
    		For(j,0,m+1){
    			r[i][j] = 0;
    		}
    	}
    	//we buy the first item type so money left will be m - item_price
    	For(i,0,v[0].size()){
    		if(m-v[0][i] >= 0){
    		 r[0][m-v[0][i]] = 1;
    		 // Debug(m-v[0][i])
    		}
    	}//set those money left stages to be reachable after buying first item

    	For(i,1,items){
    		// cout<<"\n\n";
    		// Debug(i)
    		For(j,0,v[i].size()){
    			int costi = v[i][j];
    			For(p,0,m+1){
    				if(r[i-1][p] == 1){// Debug(j) Debug(p)
    					if(p - costi >= 0) r[i][p-costi] = 1;
    				}
    			}

    		}
    	}
    	int flag = 0,ans=-1;
    	For(i,0,m+1){
    		if(r[items-1][i] == 1){//that much money left
    			ans = m - i;//amount used
    			flag = 1;break;
    		}
    	}
    	if(flag){
    		cout << ans << "\n";
    	}else cout << "no solution\n"; 

    } 
 	   	
    
    return 0;
}