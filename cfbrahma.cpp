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
    int a[n];
    For(i,0,n) cin >> a[i];
    int t[101] ={0};
    For(i,0,n){
    	
    }
    int total = 0;
    std::vector<int> v(n);
    For(i,0,n){
    	int sum = total + a[i];int ans = 0;
    	// Debug(a[i])
    	// Debug(total)
    	if(total + a[i] > m){
    		for(int j = 100; j>=0;j--){
    			if(sum - j*t[j] <= m){
    				int x = sum - m;
    				int y = x/j;
    				if(y*j < x) y++;
    				ans += y;
    				break;
    			}else{
    				sum -= j*t[j];
    				ans += t[j];
    			}
    		}
    	}
    	total += a[i];
    	v[i] = ans;
    	t[a[i]] += 1;
    }
    For(i,0,n){
    	cout << v[i] << " ";
    }

    ///////////
    return 0;
}