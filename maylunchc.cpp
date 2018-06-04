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
char a[800000];int n;
int pcheck(int i){
	if(i >= n) return 0;
	int start = i;
	int end = i+n-1;
	For(i,0,n){
		if(start > end) break;
		if(a[start] == a[end]){
			start++;
			end--;
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
    	n = s.length();
    	
    	
    	For(i,0,n) a[i] = s[i];
    	For(i,0,n-1) a[i+n] = s[i];

    	int ans = 0;
    	For(i,0,n){
    		if(pcheck(i)) ans++;
    	}
    	cout << ans << "\n";
 	
 	//
    }
    return 0;
}