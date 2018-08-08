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
    int tn = 0;
    tests{
    	tn++;
    	long long int n,k,v; cin >> n >> k >> v;
    	long long int kk = k;
    	std::vector<string> s,ans,ansf;
    	string ins;
    	For(i,0,n){
    		cin >> ins;
    		// Debug(ins)
    		s.push_back(ins);
    	//
    	}
    	long long int ind = 0;
    	ind = 1LL*k*(v-1);
    	ind = ind%n;
    	int flag = 0;
    	int ff =0;
    	while(k > 0){
    		k--;
    		if(!flag) ans.push_back(s[ind]);
    		if(flag) ansf.push_back(s[ind]);
    		if(flag) ff++;
    		// Debug(s[ind])
    		ind++;
    		if(ind == n){
    		 ind = 0;
    		 flag = 1;
    		}
    		// Debug(k)
    	}
    	cout << "Case #" << tn << ": " ;
    	For(i,0,ff){
    		cout << ansf[i];
    		cout << " ";
    	}	
    	For(i,0,kk-ff){
    		cout << ans[i];
    		if(i != kk-ff-1) cout << " ";
    	}	
    	cout << "\n";
    }
    return 0;
}