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
int a[26] = {0};


void cleara(){
	For(i,0,26) a[i] = 0;
}
int checksum(int tsum){
	For(i,0,26){
		if(a[i] == 0 || a[i] == tsum){
			continue;
		}else return 0;
	}
	return 1;
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
    	string s; cin >> s;
    	int k; cin >> k;
    	int mink = 0;
    	int dist = 0;
    	int tsum = 0;
    	int samesum = 0;
    	long long int ans = 0;
    	int n  = s.length();
    	For(i,0,n){
    		cleara();
    		mink = 0;
    		dist = 0;
    		tsum = 0;
    		For(j,i,n){
    			char c = s[j];
    			int cc = c - 'a';
    			if(a[cc] == 0) dist++;
    			if(dist >= k) mink = 1;
    			a[cc] += 1;
    			if(a[cc] > tsum){
    				tsum = a[cc];
    			}
    			
    				// Debug(mink)
    				// Debug(checksum(tsum))
    			if(mink && checksum(tsum)){
    				ans++;
    				// Debug(i)
    				// Debug(j)

    			}

    		}
    	}
    	cout << ans << "\n";

 	   	
    
    // return 0;
    }
    return 0;
}