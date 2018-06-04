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

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    int a[n],ar[n]; 
    For(i,0,n){
    	cin >> a[i];
    	ar[i] = a[i];
    }
    int m,x,y;cin >> m;
    std::vector<int> v[n];
    int count[n]={0};//friends r supporters
    int tfriends[n] = {0};
    For(i,0,m){
    	cin >> x >> y;
    	x-=1;y-=1;
    	tfriends[x] += 1;tfriends[y] += 1;

    	if(a[x] == 0){
    		//x is r supporter
    		if(a[y] == 1){
    			count[y] +=1;

    		}
    	}else if(a[y] == 0){
    		if(a[x] == 1){
    			count[x] += 1;
    		}
    	}else{
    		v[x].push_back(y);
    		v[y].push_back(x);    	
    	}
    }
    queue<int> q;
    For(i,0,n){
    	if(a[i] == 1){
    		// Debug(i)
    		// Debug(count[i])
    		// Debug(tfriends[i])
    		//b supporter
    		if(count[i]*2 - 1 >= tfriends[i]){
    			//convert
    			q.push(i);
    		}
    	}
    }
    while(!q.empty()){
    	int cur = q.front();q.pop();
    	// Debug(cur)
    	if(a[cur] == 0) continue;
    	//cur is b supporter
    	if(count[cur]*2 - 1 < tfriends[cur]) continue;
    	//convert to r supporter
    	a[cur] = 0;
    	For(i,0,v[cur].size()){
    		int fr = v[cur][i];
    		if(a[fr] == 1){
    			count[fr] += 1;
    			if(count[fr]*2 - 1 >= tfriends[fr]) continue;
    		}
    	}
    }
    int ans = 0;
    For(i,0,n) ans += a[i];
    int rsp = n-ans;int bsp = ans;
   	if(rsp > bsp){
   		cout <<"R";
   	}else if(bsp > rsp){
   		cout << "B";
   	}else{
   		cout <<"Draw";
   	}
   	// For(i,0,n) Debug(a[i])


 	   	
    return 0;
}