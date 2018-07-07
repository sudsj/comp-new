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
std::vector<pii> v;
queue<int> q;
std::vector<int> deg(500000,0);
std::vector<int> dia(500000,0);

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

 	int n,d,k;
 	cin >> n >> d >> k;
 	if(n > 2 && k <= 1){
 		cout << "NO";return 0;
 	}
 	if(d+1 > n){
 		cout << "NO";return 0;	
 	}
 	// int cn = 0;
 	For(i,1,d+1){
 		v.push_back({i,i+1});
 	}
 	int cn = d+1;
 	deg[1] = deg[d+1] = 1;
 	For(i,2,d+1){
 	 deg[i] = 2;
 	 q.push(i);
 	}
 	For(i,1,d+2){
 		dia[i] = max(i,d+2-i) - 1;
 	}
 	while(cn < n && !q.empty()){
 		int z = q.front();q.pop();
 		// Debug(z)
 		// Debug(dia[z])
 		while(deg[z] < k && dia[z] < d){
 			int y = cn+1;
 			v.push_back({z,y});
 			deg[z] += 1;
 			deg[y] += 1;
 			dia[y] = dia[z] + 1;
 			q.push(y);
 			cn++;
 			if(cn == n) break;
 		}
 	}
 	if(cn < n){
 		// Debug(cn)
 		cout << "NO";return 0;
 	}
 	cout << "YES\n";
 	For(i,0,v.size()){
 		
 		cout << v[i].first << " " << v[i].second << "\n";
 	}
    return 0;
}