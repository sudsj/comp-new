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
int a[110000] = {0};
int cs[110000] = {0};

int ur[110000] = {0};//update array

int bsright(int l, int r, int x, int i){
	//inclusive bounds l and r
	// x is the a[i] being searched
	//org is cs[i] for comparison
	int org = cs[i];
	if(l < 0) return 0;
	if(r >= n) return 0;
	int mid = l+r;
	mid = mid/2;
	//if l == r == n-1 -> doesnt matter
	//update from i+1 to n-1 inclusive
	ur[i+1] += 1;
	ur[n] -= 1;
	//we want to find the leftmost inconsitency

	if(cs[mid] - org > x){
		//inconsistent
		if(mid == l){
			//update from i+1 to l inclusive
			ur[i+1] += 1;
			ur[l+1] -= 1;
		}else{
			//check left
				
		}
		

	}else{
		//go right
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

 	tests{
 		 cin >> n;
 		// int a[n];
 		For(i,0,n){
 			cin >> a[i];
 		}
 		// int cs[n];
 		cs[0] = a[0];
 		For(i,1,n){
 			cs[i] = cs[i-1] + a[i];
 		}

 		cout << ans << "\n";
 	}   	
    return 0;
}