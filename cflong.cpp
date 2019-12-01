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
std::vector<int> v[100010];
std::map<int, int> mp;
std::vector<string> av;
string sgen(int n){
	//fully conncects
	if(n <= 0) return "";
	if(n == 1) return "1";
	//else print
	string s;
	int hf = n/2;
	For(i,0,hf){
		s += "0";
	}
	For(i,hf,n){
		s+= "1";
	}
	return s;
}

long long connect(long long n){
	long long x =1;
    For(i,0,100){
    	if(x >= n){
    		break;
    	}
    	x = x*2;
    }
    long long ans = 0;
	long long nn = n;int rep = 1;n=x;
	while(n > 1){
		string s = sgen(n);
		string x;
		For(i,0,rep){
			x += s;
		}
		x.resize(nn);
		av.push_back(x);
		// cout << x;
		// cout << "\n";
		n = n/2;
		rep *= 2;
		ans++;
	}
	return ans;
}

void output(int n){
	For(i,0,av.size()){
		string s = av[i];
		string a;
		For(i,1,n+1){
			a += s[mp[i]-1];
		}
		cout << a << "\n";
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
    
    int n,m; cin >> n >> m;
    For(i,0,m){
    	int x,y;cin >> x >> y;
    	int minn = min(x,y); int maxx = max(x,y);
    	v[minn].push_back(maxx);
    }
    //now put into groups
    //put all into 1st group
    For(i,1,n+1){
    	mp[i] = 1;
    }
    //seperate
    For(i,1,n+1){
    	if(mp[i] != i) continue;
    	For(j,0,v[i].size()){
    		int x = v[i][j];
    		if(mp[i] == mp[x]){
    			mp[x] = i+1;
    		}
    	}
    }
    // For(i,1,n+1){
    // 	Debug(mp[i])
    // }
    //find group size
    int sz[n+1] = {0};
    int ngroups = 0;
    For(i,1,n+1){
    	sz[mp[i]] += 1;
    	ngroups = max(ngroups,mp[i]);
    }
    //check if possible
    int flag = 1;
    For(i,1,n+1){
    	For(j,0,v[i].size()){
    		int x = v[i][j];
    		v[x].push_back(i);
    		if(mp[i] == mp[x]){
    			flag = 0;
    		}
    	}
    	// Debug(flag)
    	//also check if it has enough connections
    	if(v[i].size() + sz[mp[i]] != n){
    		flag = 0;
    	}
    	// Debug(i)
    	// Debug(v[i].size())
    	// Debug(sz[mp[i]])
    	// Debug(flag)
    }
    // Debug(flag)
    int on = n;n = ngroups;
    //only for full 
    long long x =1;
    For(i,0,100){
    	if(x >= n){
    		break;
    	}
    	x = x*2;
    }
    long long ans = 0;
    while(x > 1){
    	x = x/2;ans++;
    }
    //check if power exceeds
    long long pw = ans*on*1LL;
    if(pw > 1000000) flag = 0;
    if(flag == 0){
    	ans = -1;
    }
    cout << ans << "\n";
    if(flag){
    	connect(n);
    	output(on);
    }
    
    ///////////
    return 0;
}