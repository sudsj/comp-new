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
    

    int n; cin >> n;
    std::vector<int> v[n];
    int bag = 0;int flag = 1;
    For(i,1,n*n+1){
    	v[bag].push_back(i);
    	if(flag) bag++;
    	if(!flag) bag--;
    	if(bag == n){
    		flag = 0;
    		bag = n-1;
    	}
    	if(bag == -1){
    		flag = 1;
    		bag = 0;
    	}
    }
    For(i,0,n){
    	For(j,0,v[i].size()){
    		cout << v[i][j] << " ";
    	}
    	cout << "\n";
    }

    ///////////
    return 0;
}