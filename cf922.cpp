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
    // std::vector<int> ff;long long int an = 1;
    // For(i,1,20){
    // 	an *= i;//Debug(an)
    // 	ff.push_back(an);
    // }
 	long long int n,k;
 	cin >> n >> k;
 	int flag = 1;
 	if(k >= 20 || k >= n){
 		cout << "No";
 	}else{
 		For(i,1,k+1){
 			if(n%i == i-1){

 			}else{
 				flag = 0;
 			}
 		}
 		if(flag == 1) cout << "Yes";
 		if(flag == 0) cout << "No";
 	}  	
    return 0;
    
}