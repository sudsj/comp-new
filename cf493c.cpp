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
std::vector<int> v[101000];
std::vector<int> b(101000);

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n; int x,y;cin >> x >> y;
    string s;
    cin >> s;
    int a[n];
    For(i,0,n){
    	if(s[i] == '1'){
    		a[i]=1;
    	}else a[i]=0;
    }
    std::vector<int> zz,oo;
    int one = 0,z=0;
    For(i,0,n){
    	if(a[i] == 1){
    		if(z != 0) zz.push_back(z);
    		z = 0;
    		one++;
    	}else{
    		if(one != 0) oo.push_back(one);
    		one  = 0;
    		z++;
    	}
    }
    if(z != 0) zz.push_back(z);
    z = 0;
    long long int ans = 0,sz;
    sz = zz.size();
    if(sz == 0){
    	ans = 0;
    }else if(sz == 1){
    	ans = y;
    }else{
    	ans = sz*y*1LL;
    	if(x >= y) goto skip;
    	ans = y*1LL + x*(sz-1)*1LL;
    	
    }
    skip:
    cout << ans;
    return 0;
}