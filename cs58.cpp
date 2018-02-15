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

 	int n;
 	 cin >> n;
 	 int a[n],b[n];
 	 std::vector<pii> v;
 	 For(i,0,n){
 	 	cin >> a[i] >> b[i];
 	 	v.push_back(make_pair(a[i],b[i]));
 	 }    
 	 sort(v.begin(), v.end());
 	 int d[n];
 	 d[0] = 0;
 	 For(i,1,n){
 	 	d[i] = v[i].first - v[i-1].second;
 	 }
 	 long long int best = 12312312312123;
 	 For(i,0,n){
 	 	long long int c = 0,curr = 0;
 	 	for(int j = i; j >= 1;j--) {
 	 		c += curr + d[j];
 	 		curr += d[j];
 	 	}
 	 	curr = 0;
 	 	For(j,i+1,n) {
 	 		c += curr + d[j];
 	 		curr += d[j];
 	 	}
 	 	if(c < best) best = c;
 	 }

 	 cout << best;
    return 0;
}