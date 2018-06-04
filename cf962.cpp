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

    int n,a,b;
    cin >> n >> a >> b;
    string s;cin >>s;int ans = a+b;
    int pa=1,pb=1;
    For(i,0,n){
    	if(s[i] == '*'){
    	 pa = 1; pb = 1;
    	 continue;
    	}
    	if(pa == 1 && pb == 1){
    		if(a > b){
    			if(a <= 0) continue;
    			a--;pa=0;
    		}else{
    			if(b <= 0) continue;
    			b--;pb=0;
    		}
    		continue;	
    	}
    	if(pa == 1){
    		swap(pa,pb);
    		if(a <= 0) continue;
    		a--;
    	}else{
    		swap(pa,pb);
    		if(b <= 0) continue;
    		b--;
    	}
    	// swap(pa,pb);
    	
 	   	
    
    }
    cout << ans - a - b;
}