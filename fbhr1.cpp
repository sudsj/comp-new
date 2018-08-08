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
long long int ans = 0;
int l[5000] = {0};
int r[5000] = {0};
int pa[5000] = {0};
int pb[5000] = {0};
int n,k,totlb=0;
std::vector<int> pretv,postv;

void pre(int x){//NLR
	pretv.push_back(x);
	if(l[x] != 0) pre(l[x]);
	if(r[x] != 0) pre(r[x]);
}
void post(int x){//LRN
	
	if(l[x] != 0) post(l[x]);
	if(r[x] != 0) post(r[x]);
	postv.push_back(x);
}
int vis[5000] = {0};

void col(int x){
	if(vis[x] != 0) return;
	vis[x] = totlb;
	col(pa[x]);
	col(pb[x]);
}

void lpc(){
	totlb = 0;
	For(i,1,n+1) vis[i] = 0;
	For(i,1,n+1){
		if(vis[i] == 0){
			totlb++;
			col(i);
		}else continue;
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
    int csn = 0;
 	tests{
 		csn += 1;
 		cout << "Case #" << csn << ": ";
 		// cout << n << k;
 		pretv.clear();
 		postv.clear();
 		cin >> n >> k; 
 		// cout << n << k;
 		int lc,rc;
 		For(i,1,n+1){
 			cin >> lc >> rc;
 			l[i] = lc;r[i] = rc; 
 		}
 		pre(1);post(1);
 		// cout << "\n";
 		// For(i,0,n) cout << pretv[i] << " ";
 		// cout << "\n";
 		// For(i,0,n) cout << postv[i] << " ";
 		// cout << "\n";
 		int labels[n+1] = {0};
 		
 		
 		For(i,0,n){
 			pa[pretv[i]] = postv[i];
 			pb[postv[i]] = pretv[i];

 		}
 		lpc();
 		if(totlb < k){
 			cout << "Impossible\n";
 		}else{
 			For(i,1,n+1){
 				if(vis[i] <= k){
 					cout << vis[i]<<" ";
 				}else cout << k <<" ";

 			}
 			cout << "\n";
 		}
 	}


    return 0;
}