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
	string s;
	int n;
    tests{
    	cin >> s;
    	n = s.length();
    	int l = 0, r= 0;
    	int lsum = 0,rsum=0;
    	For(i,0,n) {
    	    if(s[i] == '(') l++;
    	    else r++;
    	    if(r > 2*l) {
    	        cout << "NO\n";
    	        goto brk;
    	    }
    	    
    	}
    	if(r < l || r > 2*l){
    		cout << "NO\n";
    		goto brk;
    	}
    	cout << "YES\n";
    	brk : ;
    }
    return 0;
}