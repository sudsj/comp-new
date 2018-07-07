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

void lambdafunctor(std::vector<double>& v){
	transform(v.begin(), v.end(), v.begin(),
		[](double d) -> double {//this is the lambda functor
			if(d < 8.0){
				return d;
			}else return d - 0.33;
		} 
	 );
}

void lambdafunctor2(std::vector<double>& v, int eps, std::vector<int> &z){
	transform(v.begin(), v.end(), z.begin(),
		[eps](double d) -> int {//this is the lambda functor
			//capturing eps by value and specifying output type as integer
			if(d < 8.0){
				return (int) d*10 + eps;
			}else return (int) d - 0.33 + eps*10;
		} 
	 );
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    std::vector<double> v;
    std::vector<int> z(10);
    For(i,0,5) v.push_back(1.0*i + 6.33);
    For(i,0,5) Debug(v[i])
    lambdafunctor(v);
    lambdafunctor2(v, 5, z);
    For(i,0,5) Debug(v[i])
 	For(i,0,5) Debug(z[i])   	
    return 0;
}