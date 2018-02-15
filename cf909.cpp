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
 	int n,k;
 	cin >> n >> k;
 	std::vector<int> v(n);
 	For(i,0,k) cin >> v[i];
 	int s = 1;int flag = 0;
 	For(i,0,k-1){
 		if(v[i] == s){
 			s++;
 		}else{
 			if(v[i] < v[i+1]){
 				flag = 1;goto skip;
 			}
 		}
 	}
 	//put 
 	
 	skip : ;
 	if(flag == 1){
 		cout << "-1";
 	}else{
 		For(i,0,n){
 			cout << v[i] << " ";
 		}
 	}
    return 0;
}