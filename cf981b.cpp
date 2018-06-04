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
struct comp_pair_int {
    bool operator()(const pair<long long int,long long int> &a, const long long int & b)
    {
        return (a.first < b);
    }
    bool operator()(const long long int & a,const pair< long long int, long long int> &b)
    {
        return (a < b.first);
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

 	 int n,m;
 	 cin >> n;
 	 long long int a[n],x[n];
 	 For(i,0,n){
 	 	cin >> a[i];
 	 }
 	 For(i,0,n){
 	 	cin >> x[i];
 	 }
 	 cin >> m;
 	 long long int b[m],y[m];
 	 For(i,0,m){
 	 	cin >> b[i];
 	 }
 	 For(i,0,m){
 	 	cin >> y[i];
 	 }
 	sort(a,a+n);
 	long long int ans = 0;
 	For(i,0,n) ans += x[i];
 	std::vector< pair < long long int, long long int > > v;
 	For(i,0,n){
 		v.push_back( make_pair(a[i],x[i]));
 	}
 	For(i,0,m){
 		if(binary_search(v.begin(),v.end(), b[i], comp_pair_int())){
 		        // cout<<"Key found"<<endl;
 			auto lower = std::lower_bound(v.begin(), v.end(), b[i], comp_pair_int());
			Debug(*lower.first) 			

 		}else ans += y[i];
 		// if (std::binary_search (v.begin(), v.end(), b[i])){
 		// 	if(y[i] ) 
 		// }else ans += y[i];
 	} 
 	cout << ans;
    return 0;
}