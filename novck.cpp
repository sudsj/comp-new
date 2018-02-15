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
int vis[1000][1000] = {{0}};
int v[1000][1000] = {{0}};
int n=0,m=0,k=0;


void dfs(int x, int y){
	
	if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0){
		// Debug(x) Debug(v[x][y])
		vis[x][y] = 1;

		if(x+1 < n && v[x+1][y] <= v[x][y] ) dfs(x+1,y);
		if(y+1 < m && v[x][y+1] <= v[x][y] ) dfs(x,y+1);
		if(x-1 >= 0 && v[x-1][y] <= v[x][y] ) dfs(x-1,y);
		if(y-1 >= 0 && v[x][y-1] <= v[x][y] ) dfs(x,y-1);
		// dfs(x,y-1);
		// dfs(x-1,y);
		// dfs(x,y+1);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
 	   freopen("input.txt", "r", stdin);
 	   freopen("output.txt", "w", stdout);
    #endif
 	  //  For(i,0,1000){
 	  //  	For(j,0,1000) vis[i][j] = 0;
 	  //  }
 	tests{
 		//int n,m,k;
 		 cin >> n >> m;
//  		std::vector<int> v[n];
//  		std::vector<int> vis[n];
 		For(i,0,n){
 			For(j,0,m) vis[i][j] = 0;
 		}
 		std::vector< pair<int, pii > > s;
 		For(i,0,n){
 			For(j,0,m){
 				cin >> v[i][j];
 			// 	v[i].push_back(k);
 				s.push_back(make_pair(v[i][j],make_pair(i,j)));
 			}
 		}
 		sort(s.begin(),s.end());
 		int ans = 0;
 		for(int i = n*m - 1; i >= 0; i--){
 			// Debug(ans)
 			if(vis[(s[i].second).first][(s[i].second).second] == 0){
 				ans ++;//Debug((s[i].second).second)
 				dfs((s[i].second).first, (s[i].second).second);
 			}
 		}
        cout << ans <<"\n";
 	}
    return 0;
}