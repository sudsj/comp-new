#include <bits/stdc++.h>
#include <iomanip>
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
 	    std::cout << std::fixed;
    std::cout << std::setprecision(7);
 	tests{
 		int n;cin >> n;
 		int a[n];
 		For(i,0,n) cin >> a[i];
 		int x,y;
 		For(i,0,n-1){
 			cin >> x >> y;
 		}
 		double sum = 0;
 		For(i,0,n){
 			sum += a[i]*1.0;
 		}
 		sum = sum/(n*1.0);
 		cout << sum << "\n";
 	}    
    return 0;
}