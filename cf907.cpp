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
  int a[26] = {0};
int chk(){
	int sum = 0;
	For(i,0,26){
		sum += a[i];
	}
	// Debug(sum)
	if(sum == 1){
		return 1;
	}else return 0;
}
int main()
{
    
     int n;cin >> n;
     For(i,0,26){
        a[i] = 1;
	}
	int flag = 0;
 	  // Debug(chk())
 	string s;char c;int ans = 0;
 	For(i,0,n){
 		cin >> c;

 		cin >> s;
//  		Debug(c)
 		if(c == '.'){
 			For(i,0,s.length()){
 				a[s[i] - 'a'] = 0;
 			}
 		}else if(c == '?'){
 			if(i != n-1){
 				a[s[0] - 'a'] = 0;
 				if(flag == 1) ans++;
 			}

 		}else{
 			//!
 			int trp = 0;
 			For(j,0,26){trp=0;
 				For(i,0,s.length()){
 					if(s[i] - 'a' == j){
 						trp = 1;
 					}
 				}
 				if(trp == 0) a[j] = 0;
 			}
 			if(flag == 1) ans++;
 		}
//  		
 		if(chk() == 1){
 			flag = 1;//Debug(i)
 		}
 		// Debug(s);
 	}
 	cout << ans;    
    return 0;
}