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
    long long int s1=0,s2=0;
    int n; cin >> n;
    long long int a[n];
    For(i,0,n) cin >> a[i];
    int nf = 0;int pf = 0;
    long long int minn = 999999999999;
    long long int maxx = -999999999999;
    For(i,0,n){
    	if(a[i] >= 0){
    		pf = 1;
    	}else nf = 1;
    	minn = min(a[i],minn);
    	maxx = max(a[i],maxx);
    	s1 += a[i];
    	s2 += abs(a[i]);
    }
    if(n == 1){
    	cout << a[0];
    	return 0;
    }
    if(pf == 1 && nf == 0){
    	//only pos
    	cout << s1 - 2*minn;
    }else if(pf == 1 && nf == 1){
    	cout << s2;
    }else{
    	//nf == 1
    	// Debug(maxx)
    	//all negative
    	cout << s2 + 2*maxx;
    }
    
    ///////////
    return 0;
}