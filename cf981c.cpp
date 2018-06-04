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
int visited[200000] = {0};
std::vector<int> v[200000];
int root;
int cnnn = 0;int ans=-2;int pans = -1;
void dfs(int x){
	// cnnn++;
	// if(cnnn >= 150) return;
	// Debug(x)
	// Debug(v[x].size())
	if(visited[x] == 1) return;
	visited[x] = 1;
	if(v[x].size() == 1 && x != root){
		cout << root << " " << x << "\n";
	}
	
	// Debug(x)
	// Debug(v[x].size())
	For(i,0,v[x].size()){
		if(!visited[v[x][i]]){
			dfs(v[x][i]);
			// Debug(v[x][i])
		}
	}
	return ;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    
    int a,b;
    int count[n+1] = {0};

    For(i,0,n-1){
    	cin >> a >> b;
    	v[a].push_back(b);
    	v[b].push_back(a);
    	count[a] += 1;
    	count[b] += 1;
    }
    int nn = 0;

    For(i,1,n+1){
    	if(count[i] >= 3){
    		nn++;
    		// Debug(i)

    		root = i;
    	}
    }
    if(nn <= 1){
    	// Debug(nn)

    	cout << "Yes\n";

    	if(nn == 0){
    		cout << 1 << "\n";
    		// Debug(root)
    		For(i,1,n+1){
    			if(count[i] == 1){
    				// nn++;
    				// Debug(i)

    				root = i;break;
    			}
    		}
    		
    	}else{
    		cout << count[root]  << "\n";
    	}
    	// Debug(root)
    	dfs(root);
    	// Debug(ans)
    	// int cn = 0;
    	// while(ans != pans && cn <= 150){
    	// 	cn++;
    		
    	// 	pans = ans;
    	// 	visited[root] = 0;
    	// 	dfs(root);
    	// }
    }else{
    	cout << "No";
    }
 	//   	
    return 0;
}