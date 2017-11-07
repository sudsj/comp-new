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
std::vector<int> c[100009],p(100009),v[100009];//from 1 to n child and parent
std::vector<int> s(100009),cs(100009);
std::vector<int> visited(100009,0);
int n,m;
void mktree(int root){
	visited[root] = 1;
	For(i,0,v[root].size()){
		if(visited[v[root][i]] == 1) continue;
		c[root].push_back(v[root][i]);
		p[v[root][i]] = root;
	}
	For(i,0,v[root].size()){
		mktree(v[root][i]);
	}
}
std::vector<int> dv(100009,0);
std::vector<int> d;
void dfs(int root){
	//dv[root] = 1;
	d.push_back(root);
	For(i,0,c[root].size()){
		dfs(c[root][i]);
	}
	d.push_back(root);
}

int main()
{
	
	cin >> n>>m;
	
	For(i,0,n){
		cin >> s[i+1];
	}
	int u,v1;
	For(i,0,n-1){
		cin >> u >> v1;
		v[u].push_back(v1);
		v[v1].push_back(u);
	}
	//1 is root
	mktree(1);
	For(i,0,n){
		cout << i << "'s parent is "<<p[i+1]<<"\n";
	}
    return 0;
}
