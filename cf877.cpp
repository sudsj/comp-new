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
int ax,ay,bx,by;
int n,m,k;
char a[1001][1001];
int adp[1001][1001];
int vis[1001][1001];
int dp(int i,int j){
    
    if(i < 1 || i > n || j < 1 || j > m) return 9000000; 
    if(a[i][j] == '#') return 9000000;
    if(i == bx && j == by) return 0;
    if(adp[i][j] == 8000000){
        if(vis[i][j] == 1) return 8000000;
        vis[i][j] = 1;
        //Debug(i) Debug(j)
        int min = adp[i][j];
        //Debug(min)
        For(t,i+1,i+k+1){
            if(t > n) continue;if(t < 1) continue;
            if(a[t][j] == '#') break;
            if(dp(t,j) < min) min = dp(t,j) + 1;
        }
        For(t,i-k,i){
            if(t > n) continue;if(t < 1) continue;
            if(a[t][j] == '#') break;
            if(dp(t,j) < min) min = dp(t,j) + 1;
        }
        For(t,j+1,j+k+1){
            if(t < 1) continue;if(t > m) continue;
            if(a[i][t] == '#') break;
            if(dp(i,t) < min) min = dp(i,t) + 1;
        }
        For(t,j-k,j){
            if(t < 1) continue;if(t > m) continue;
            if(a[i][t] == '#') break;
            if(dp(i,t) < min) min = dp(i,t) + 1;
        }
        adp[i][j] = min;
    }else return adp[i][j];
}
int main()
{
    
    cin >> n >> m >> k;
   // char car; cin >> car;
    
    For(i,1,n+1){
        For(j,1,m+1){
            cin >> a[i][j];
            //cout << a[i][j];
        }
        //cin >> car;//newline
    }
    
    cin >> ax >> ay >> bx >> by;
    
    For(i,1,n+1){
        For(j,1,m+1){
            adp[i][j] = 8000000;
            vis[i][j] = 0;
        }
    }
    adp[bx][by] = 0;
    int ans = dp(1,1);
    if(ans == 8000000 || ans == 9000000) ans = -1;
    cout << ans;
    return 0;
}