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
std::vector<int> v[100];
int dpr[20][201];
int dp(int n, int mleft){
	if(mleft < 0) return -1;
	if(n < 0) return 0;
	
	if(dpr[n][mleft] != -10) return dpr[n][mleft];
	int size = v[n].size();
	int val,maxval= -1;
	For(i,0,size){
		if(v[n][i] <= mleft){
			val = dp(n-1,mleft-v[n][i]);
			if(val < 0) continue; 
			val += v[n][i];
			if(maxval < val) maxval = val;
		}
	}
	dpr[n][mleft] = maxval;
	return maxval;
}


int main()
{
 	int cases; cin >> cases;
	For(cn,1,cases+1){
 	    
 		int mt,gt,k,tp;
 		cin >> mt >> gt;
 		For(i,0,20){
 			For(j,0,201){
 				dpr[i][j] = -10;
 			}
 		}
 		//if(cn == 38) cout << mt << " " << gt << "\n";
 		For(i,0,gt){
 			cin >> k;
 			For(j,0,k){
 				cin >> tp;
 				//if(cn == 38) cout << tp << " ";
 				v[i].push_back(tp);

 			}
 			//if(cn == 38) cout << "\n";
 		}
 		int ans = dp(gt-1,mt);
 		//if(cn == 38) {
 		if(ans == -1){
 		    cout << "no solution\n";
 		}else cout << ans << "\n";
 		//cout << ;
 		For(i,0,gt){
 			v[i].clear();
 		}
 	}   
    return 0;
}