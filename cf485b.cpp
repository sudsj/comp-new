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

    int n;cin >> n;
    long long int a[n],b[n];
    For(i,0,n) cin >> a[i];
    For(i,0,n) cin >> b[i];
 	
    //higher pair
    long long int next[n],anext[n];
    For(i,0,n){
    	long long int x = a[i],min = INT_MAX;
    	next[i] = -1;
    	For(j,i+1,n){
    		if(a[j] > a[i]){
    			if(b[j] < min){
    				min = b[j];
    				next[i] = min + b[i];
    			}
    		}
    	}
    }
    int flag = 0;
    For(i,0,n){
        // Debug(next[i])

    	long long int x = a[i],min = 1000000000*1LL;
    	anext[i] = -1;
    	For(j,i+1,n){
    		if(a[j] > a[i]){
    			if(next[j] == -1) continue;
    			if(next[j] < min){
                    // Debug(i)
                    // Debug(b[i])
                    // Debug(next[j])
    				flag = 1;
    				min = next[j];
    				anext[i] = min + b[i];
    			}
    		}
    	}
    }
    if(flag == 0){
    	cout << "-1";
    }else{
        long long int ans = 1000000000*1LL;
        For(i,0,n){
            if(anext[i] == -1) continue;
            if(anext[i] < ans){
             ans = anext[i];
             // Debug(i) Debug(ans)
            }
        }
        cout << ans << "\n";
    }
    return 0;
}