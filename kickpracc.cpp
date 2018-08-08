#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Debug(x) cout << "> " << #x << " : " << x << "\n";
#define DebugArr(a,n) For(i,0,n) cout << i << " : " << a[i] << "\n";
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define ForD(i,a,b) for(int i=(a);i>(b);i--)
// #define tests int t; cin>>t; while(t--)
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

    map<string,int> count;
    map<string,string> connect;
    string src,dest,fsrc,fdest;
    std::vector<string> airlist;
    int tests,n,tsn=0;
    cin >> tests;
    while(tests--){
    	tsn++;
    	cin >> n;
    	cout << "Case #" << tsn << ": ";
    	for(int i = 0; i < n; i++){
    		cin >> src >> dest;
    		count[src] += 1;
    		count[dest] += 1;
    		if(count[src] == 1) airlist.push_back(src);
    		if(count[dest] == 1) airlist.push_back(dest);
    		connect[src] = dest;
    		// cout << dest << "\n";
    	}
    	for(int i = 0; i < airlist.size(); i++){
    		if(count[airlist[i]] == 1){
    			if(connect.count(airlist[i])){
    				//its the source
    				fsrc = airlist[i];
    			}else fdest= airlist[i];
    		}
    	}
    	int i = 2;
    	cout << fsrc << "-" << connect[fsrc] << " ";
    	// fsrc = connect[fsrc];
    	while(i < airlist.size()){
    		i++;
    		fsrc = connect[fsrc];
    		cout <<fsrc <<  "-" << connect[fsrc]<<" ";
    		
    	}
    	cout << "\n";
    	airlist.clear();
    	count.clear();
    	connect.clear();
    }
    return 0;
}