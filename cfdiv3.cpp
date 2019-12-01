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
    	int b,w;cin >> b >> w;
    	int start;
    	std::vector<int> on;
    	std::vector<int> tw;
    	std::vector<int> tr;
    	if(b < w){
    		start = 2;
    		w--;
    	}else{
    		start = 3;
    		b--;
    	}
    	int m = min(b,w);
    	tw.push_back(start);
    	int cur = start;
    	For(i,0,m){
    		cur += 1;
    		tw.push_back(cur);
    		cur += 1;
    		tw.push_back(cur);
    		b--;w--;
    	}
    	if(b > 0){
    		//black is left
    		//put on top of white
    		For(i,start,cur+1){
    			if(i%2 == 0){
    				if(b > 0){
    					on.push_back(i);
    					b--;
    				}
    				if(b > 0){
    					tr.push_back(i);
    					b--;
    				}
    			}
    		}
    	}
    	if(w > 0){
    		//white is left
    		//put on top of black
    		For(i,start,cur+1){
    			if(i%2 == 1){
    				if(w > 0){
    					on.push_back(i);
    					w--;
    				}
    				if(w > 0){
    					tr.push_back(i);
    					w--;
    				}
    			}
    		}
    	}
    	int flag = 0;
    	if(b == 0){
    		if(w == 0){
    			flag = 1;
    		}
    	}
    	if(flag){
    		cout << "YES\n";
    		For(i,0,on.size()){
    			cout << 1 << " " << on[i] << "\n";
    		}
    		For(i,0,tw.size()){
    			cout << 2 << " " << tw[i] << "\n";
    		}
    		For(i,0,tr.size()){
    			cout << 3 << " " << tr[i] << "\n";
    		}
    	}else{
    		cout << "NO\n";
    	}

    }







    ///////////
    return 0;
}