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
int a[400][400];
int n;
int gettr(int x, int y){
	int trace = 0;
	For(i,x,n){
		if(i >= n) break;
		if(y >= n) break;
		trace += a[i][y];
		y++;
	}
	return trace;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    tests{
    	cin >> n;
    	For(i,0,n){
    		For(j,0,n){
    			cin >> a[i][j];
    		}
    	}
    	int traces[3*n] = {0};
    	For(i,0,n){
    		traces[i] = gettr(i,0);
    	}
    	For(i,0,n){
    		traces[i+n] = gettr(0,i);
    	}
    	int maxt = -1;
    	For(i,0,2*n){
    		// Debug(traces[i])
    		if(traces[i] > maxt) maxt = traces[i];
    	}
    	cout << maxt << "\n";
    }

 	
 	//

    return 0;
}