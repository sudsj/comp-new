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
    int tnn = 0;
    tests{
    	tnn++;
    	int n,p;
 	   	cin >> n >> p;
 	   	int a[n];
 	   	For(i,0,n) cin >> a[i];
 	   	cout << "Case #"<<tnn<<": ";
 	   	int ans = 0;
 	   	int b[5]={0};
 	   	For(i,0,n){
 	   		b[a[i]%p]++;
 	   	}
 	   	if(p == 2){
 	   		ans = b[0];
 	   		ans += (b[1]+1)/2;
 	   	}else if(p == 3){
 	   		ans = b[0];
 	   		int dif = min(b[1],b[2]);
 	   		ans += dif;
 	   		int mx = max(b[1],b[2]);
 	   		mx -= dif;
 	   		ans += (mx+2)/3;
 	   	}else{
 	   		ans = b[0];
 	   		int dif = min(b[1],b[3]);
 	   		ans += dif;
 	   		int mx = max(b[1],b[3]);
 	   		mx -= dif;
 	   		int m2 = b[2];
 	   		int diff = mx/2;
 	   		mx -= 2*diff;
 	   		m2 += diff;
 	   		int diff2 = m2/2;
 	   		ans += diff2;
 	   		m2 -= 2*diff2;
 	   		if(m2 > 0 || mx > 0) ans++;

 	   	}
 	   	cout <<ans<<"\n";

    
    }
    return 0;
}