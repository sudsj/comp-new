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
const long double PI  = 3.141592653589793238463;

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false),cin.tie(0),cout.precision(15);
   	
   	long double dd = sqrt(2)*0.5;//distance to diagonal
   	long double cd = 0.5;//centre distance from origin
   	int cn = 0;
   	tests{
   		cn++;
   		cout << "Case #"<<cn<<": ";
   		long double ta;//target area
   		cin >> ta;
   		// long double divr = 
   		// long double cstmff = ta/(2.0*dd);//cos (theta - 45)
   		// // Debug(cstmff)
   		// cstmff = acos(cstmff);
   		// cstmff *= 180.0;
   		// cstmff /= PI;
   		// // Debug(cstmff)
   		// cstmff = 45.0 - cstmff;

   		//method 2
   		long double k = ta;

   		long double disc = k*k - 2.0*(k*k - 1);
   		disc = sqrt(disc);
   		long double cosx = k - disc;
   		cosx = cosx/2.0;
   		// Debug(cosx)
   		long double sinx = 1.0 - cosx*cosx;
   		sinx = sqrt(sinx);

   		//
   		// long double cst = cos(cstmff);
   		// Debug(cst)
   		// long double sint = sin(cstmff);
   		long double cr1 = 0.5*cosx;
   		long double cr2 = 0.5*sinx;
   		cout << -1.0*cr2 << " " << cr1<<" 0\n";
   		cout << cr1 << " "<<cr2<<" 0\n";
   		
   		cout << "0 0 0.5\n";

   	}
 	   	


 	 

 	   	
    return 0;
}