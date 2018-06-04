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
    	int n;cin >> n;
    	int a[n];
    	For(i,0,n) cin >> a[i];
    	int c[n] = {0};
    	int inx[n] = {0};
    	For(i,0,n) inx[i] = i;
    	int b[n];int cl = n,pcl=n;
    	int ans[n] = {0};
    	For(i,0,n){
    		For(j,1,pcl-1){
    			if(a[j] < a[j-1] && a[j] < a[j+1]){
    				c[j] = 1;cl--;
    				ans[inx[j]] = i+1;
    				Debug(j)
    				Debug(inx[j])
    			}

    		}
    		int dif = 0;
    		For(j,0,pcl){
    			if(c[j] == 0){
    				b[j] = a[j];
    				inx[j] += dif;
    			}else{
    			 b[j] = -1;
    			 dif += 1;
    			 inx[j] += dif;
    			}
    		}
    		int ind = 0;
    		For(j,0,pcl){
    			if(b[j] > 0 ){
    			 a[ind] = b[j];
    			 ind++;
    			}
    		}
    		pcl = cl;
    	}
    	For(i,0,n){
    		cout << ans[i] << " ";
    	}
    	cout << "\n";
    }

 	//   	
    return 0;
}	