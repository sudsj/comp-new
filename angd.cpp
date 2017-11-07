#include <bits/stdc++.h>
using namespace std;
#if DEBUG && !ONLINE_JUDGE
	#include "debug.h"
#else
	#define debug(args...)
	#define DBG(x...)
#endif
typedef vector<int> vi;typedef vector<vi> vvi;typedef pair<int,int> ii;
typedef pair<int,ii> iii;typedef vector<ii> vii;
typedef vector<vii> vvii;typedef vector< iii > viii;
typedef long long ll;typedef vector<ll> vll;
typedef vector<vll> vvll;typedef vector<bool> vb;
typedef long double LD;
#define PQ priority_queue
#define UM unordered_map
#define pb push_back
#define eps 10e-6
#define PI 3.14159265359
#define MOD 1000000007
#define INF 2LL*MOD
#define fi first
#define se second
#define REP(i,n) for(auto i=0;i<n;i++)
#define FOR(i,a,n) for(auto i=a;i<=n;i++)
#define scani(n) scanf("%d",&n)
#define set1(a) memset(a,63,sizeof(a))
#define set0(a) memset(a,0,sizeof(a))
#define init(n_,n) n_.clear();n_.resize(n)
#define initi(n_,n,i) n_.clear();n_.resize(n,i)
#define N 1000005
//global variables
 
void prepro(){
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.precision(17);
 
	int ct;cin>>ct;
	while(ct--){
		int n,q;cin>>n>>q;
		vvii graph(n+1);
		bool ok = 1;
		vii ed;
		REP(i,q){
			int a,b,v;cin>>a>>b>>v;
			if(a>b)
				swap(a,b);
			graph[a].pb({b,v});
		}
		vi a(n+1,-1);
		FOR(v,1,n){
			if(!ok)
				break;
			if(a[v]==-1)
				for(auto i:graph[v])
					if(a[i.fi]!=-1)
						a[v] = a[i.fi]^i.se;
			if(a[v]==-1)
				a[v] = 0;
			for(auto i:graph[v]){
				if(a[i.fi]==-1 || a[i.fi]==(a[v]^i.se))
					a[i.fi]= a[v]^i.se;
				else{
					ok = 0;
					break;
				}
			}
		}
		cout<<(ok? "yes":"no")<<"\n";
	}
 
	return 0;
} 