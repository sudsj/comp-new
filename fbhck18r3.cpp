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
std::stack<long long int> tstack;
std::vector<long long int> topsort;
std::vector<long long int> tree;
std::vector<long long int> p,child[250000];
long long int ans = 0;
void tops(long long int x){
	tstack.push((-1)*x);
	For(i,0,child[x].size()){
		tops(child[x][i]);
	}
	tstack.push(x);
}
std::map<long long int, int> sind,eind;//start and end index

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = topsort[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2],tree[v*2+1]);
    }
    // Debug(v)
    // Debug(tree[v])
}

long long int getmax(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return max( getmax(v*2, tl, tm, l, min(r, tm))
           , getmax(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, long long int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}
std::vector<long long int> hnodes[250000];
int ht = 0;
void bfs(int x){	
	queue<int> q;
	q.push(x);
	q.push(ht);
	while(!q.empty()){
		int y = q.front();
		q.pop();
		ht = q.front();
		q.pop();
		hnodes[ht].push_back(y);
		For(i,0,child[y].size()){
			q.push(child[y][i]);
			q.push(ht+1);
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
    
   	std::vector<int> mark(250000);
    int tsn = 0;
    tests{
    	ht = 0;
    	tsn++;
    	ans = 0;
    	p.clear();
    	// candy.clear();
    	topsort.clear();
    	tree.clear();
    	sind.clear();
    	eind.clear();
    	long long int n,m,a,b;cin >> n >> m >> a >> b;
    	Debug(n) Debug(m) Debug(a) Debug(b)
    	cout << "Case #" << tsn <<": ";
    	long long int cn;
    	For(i,0,n) mark[i] = 0;
    	For(i,0,m){
    		cn = (a*i + b)%n;
    		mark[cn] += 1;//required by a child
    	}
    	p.push_back(-1);//0 is root
    	For(i,1,n){
    		cin >> cn;
    		p.push_back(cn);
    		// Debug(cn)
    		child[cn].push_back(i);
    	}
    	//do topological sort
    	tops(0);
    	long long int x,y,z,l,r;
    	int ind = 0;
    	while(!tstack.empty()){
    		x = tstack.top();
    		// Debug(x)
    		tstack.pop();
    		topsort.push_back(x);
    		if(x >= 0){
    			sind[x] = ind;
    		}else eind[x*(-1)] = ind;
    		ind++;
    	}
    	sind[0] = 0;
    	eind[0] = topsort.size() - 1;
    	


    	//form segment tree
    	tree.resize(4*topsort.size());
    	build(1,0,topsort.size()-1);
    	bfs(0);
    	for(int j = ht; j >= 0; j--){
    		For(i,0,hnodes[j].size()){
    			x = hnodes[j][i];
    			// Debug(x)
    			l = sind[x];
    			r = eind[x];
    			For(ii,0,mark[x]){
    				y = getmax(1,0,topsort.size()-1,l,r);
    				// Debug(y) Debug(l) Debug(r)
    				if(y > 0) ans += y;
    				//update
    				update(1,0,topsort.size()-1,sind[y],(-1)*y);
    			}
    		}
    	}
    	cout << ans<<"\n";
    	tree.clear();
    	//clean
    	For(i,0,n){
    		child[i].clear();
    	}
    	For(i,0,250000){
    		hnodes[i].clear();
    	}
    }	

 	//   	
    return 0;
}