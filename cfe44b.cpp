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
    cin >> n >> m;
    char a[n][m];int b[n][m];
    For(i,0,n){
    	For(j,0,m){
    		cin >> a[i][j];
    	}
    }

	For(i,0,n){
    	For(j,0,m){
    		if(a[i][j] == '1'){
    			b[i][j]=1;
    		}else b[i][j]=0;
    	}
    	// cout <<"\n";
    }

    int ignore = 0;
    int bulb[m] = {0};int bulbr[m] = {0};
    For(i,0,n){
    		// if(i == ig) continue;
    		For(j,0,m){
    			if(b[i][j]) bulb[j] += 1;
    		}
    	}
    	For(i,0,n){
    		// if(i == ig) continue;
    		For(j,0,m){
    			if(b[i][j]) bulbr[j] += 1;
    		}
    	}
    int pt = 0;
    For(ig,0,n){
    	// Debug(ig)
    	For(i,0,m){
    		// Debug(bulb[i])
    		bulb[i] = bulbr[i];
    	}
    	For(j,0,m){
    			if(b[ig][j]) bulb[j] -= 1;
    	}
    	int flag = 1;
    	For(i,0,m){
    		// Debug(bulb[i])
    		if(bulb[i] == 0) flag = 0;
    	}
    	if(flag){
    		pt = 1;
    		break;
    	}
    }
    if(pt == 0){
    	cout << "NO";
    }else cout << "YES";
    return 0;
}