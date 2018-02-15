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
    std::cout << std::setprecision(10);
 	int n,r; cin >> n >> r;
 	int xi[n];double y[n];
 	For(i,0,n){
 		cin >> xi[i];
 	}    
 	y[0] = r;int mx;double my,h,d;cout << r << " ";
 	For(i,1,n){
 		my = 0;mx = -1;
 		For(j,0,i){
 			if(abs(xi[j] - xi[i]) <= 2*r){
 				// my = max(my,y[j]);
 				if(my <= y[j] ){
 					
 				 	if(mx == -1 || my < y[j]){ 
 				 		mx = xi[j];my = y[j];
 				 	}else if(abs(mx - xi[i]) > abs(xi[j] - xi[i])){
 				 		mx = xi[j];
 				 		//my = y[j];
 				 	}


 				}
 			}
 		}
 		if(my == 0){
 			y[i] = r;
 		}else{
 			h = 4*r*r;
 			h = h*1.0;
 			d = abs(mx - xi[i]);
 			h -= d*d*1.0;
 			y[i] = my + sqrt(h);
 		}
 		cout << y[i] << " ";
 	}
    return 0;
}