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
int n;
std::vector<int> v[200100];
int ht[200100];
int vis[200100] = {0};
int p[200100] = {0};
int ord[200100] = {0};
void bfs(){
	vis[1] = 1;
	queue< pair<int,int> > q;
	q.push({1,0});
	// int height= 0;
	ht[1] = 0;
	int node,hgt;
	while(!q.empty()){
		pair <int,int> pp = q.front();
		q.pop();
		node = pp.first;
		hgt = pp.second;
		vis[node] = 1;
		ht[node] = hgt;
		For(i,0,v[node].size()){
			if(!vis[v[node][i]]){
				q.push({v[node][i], hgt + 1});
				p[v[node][i]] = node;
			}
		}
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
    
    cin >> n;
    int x,y;
    For(i,0,n-1){
    	cin >> x >> y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    int a[n];
    For(i,0,n) cin >> a[i];
    if(a[0] != 1){
    	cout << "No";
    	return 0;
    }
    int curht = 0;int nht;//node height
    int flag = 0;
    bfs();
    int order = 1;
    int porder = 1,lastPorder=1;
    ord[1] = 1;//comes first 
    For(i,1,n){
    	order++;
    	// Debug(a[i])
    	// Debug(ht[a[i]])
    	ord[a[i]] = order;
    	nht = ht[a[i]];
    	if(nht < curht){
    		flag = 1;
    		goto brk;
    	}
    	porder = ord[p[a[i]]];
    	if(porder < lastPorder){
    		flag = 1;goto brk;
    	}
    	if(porder > lastPorder) lastPorder = porder;
    	if(nht > curht) curht = nht;

    }

    brk:
    if(flag){
    	cout << "No";
    }else cout << "Yes";


    ///////////
    return 0;
}