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
long long int dpsum(int cs,int fs,int ci,int fi,int lim){
	if(ci > fi ) return 0;
	if(ci == fi){
		For(i,0,lim+1){
			if(cs + i == fs){
				return 1;
			}
		}
		return 0;
	}
	if(cs > fs) return 0;
	if(cs == fs) return 1;
	//cs < fs
	long long int ans = 0;
	For(i,0,lim+1){
		ans += dpsum(cs+i,fs,ci+1,fi,lim);
	}
	return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

 	    cout << dpsum(0,4,1,1,1);
    return 0;
}