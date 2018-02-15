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
int l[1011][1011];
int a[1011][1011];
int dist[1011][1011];
int n,m;
void bfs(int i, int j, int d){

	if(i <= 0 || i > n) return;
	if(j <= 0 || j > m) return;
	if(a[i][j] == -1) return;
	if(dist[i][j] >= 0) return;
	if(d >= 0){
		a[i][j] = 1;
	}
	if(d <= 0) return;
	dist[i][j] = max(dist[i][j],d);
	bfs(i+1,j,d-1);
	bfs(i,j+1,d-1);
	bfs(i-1,j,d-1);
	bfs(i,j-1,d-1);


}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
 	tests{
 		
 		cin >> n >> m;
 		For(i,1,n+1){
 			For(j,1,m+1){dist[i][j] = -1;
 				cin >> l[i][j];
 				if(l[i][j] == -1){
 					a[i][j] = -1;

 				}else if(l[i][j] == 0){
 					a[i][j] = 0;
 				}else{
 					a[i][j] = 1;
 				}
 			}
 		}

 		For(i,1,n+1){
 			For(j,1,m+1){
 				if(a[i][j] >= 1){
 					//we need to move out of this one
 					bfs(i,j,l[i][j]);
 				}
 			}
 		}
 		For(i,1,n+1){
 			For(j,1,m+1){
 				if(a[i][j] >= 1){
 					cout << "Y";
 				}else if(a[i][j] == 0){
 					cout << "N";
 				}else cout << "B";
 			}
 			cout << "\n";
 		}

 	}    
    return 0;
}