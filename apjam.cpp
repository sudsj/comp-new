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
int g[1001],a[1001],b[1001],vis[1001];
void search(int x){
	if(vis[x] == 1) return;
	vis[x]=1;
	if(a[x] == x || b[x] == x) return;
	if(a[x] == 0){
		search(a[x]);
		if(a[x] != 0){
			vis[x]=0;search(x);
		}
	}else if( b[x] = 0){
		search(b[x]);
		if(b[x] != 0){
			vis[x]=0;search(x);
		}
	}else{
		int mm = min(a[x],b[x]);
   		a[x]-=mm;b[x]-=mm;
   		g[x] += mm;
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int tcccn = 0;
   	
   	tests{
   		int m;cin >> m;
   		
   		For(i,1,m+1){
   			cin >> a[i] >> b[i];
   		}
   		For(i,1,m+1){
   			cin >> g[i];
   		}
   		cout << "Case #"<< tcccn << ": ";
   		int flag = 1;
   		if(a[1] == 1 || b[1] == 1){
   			cout << g[1]<<"\n";continue;
   		}
   		int mm = min(a[1],b[1]);
   		a[1]-=mm;b[1]-=mm;
   		g[1] += mm;
   		while(flag){

   			if(a[1] == 0){
   				For(i,1,m+1) vis[i]=0;search(1);
   			}
   		}
   		cout << g[1] << "\n";

   	}
   	
    return 0;

}