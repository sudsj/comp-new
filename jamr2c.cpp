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
int a[200][200];
int d[200][200];
int dmax = -1,mr,mc;

int findmx(){
	dmax = -1;
	For(i,0,n){
		For(j,0,n){
			dmax = max(dmax,d[i][j]);
			if(d[i][j] == dmax){
				mr = i;mc = j;
			}
		}
	}
	if(dmax <= 0) return 0;
	return 1;
}

void checkr(int r,int c){
	For(i,0,n){
		if(i == c) continue;
		if(a[r][i] == a[r][c]){
			// d[r][i]++;
			// mxcheck(r,i);
			d[r][c]++;
			// mxcheck(r,c);
		}
	}
}
void checkc(int r,int c){
	For(i,0,n){
		if(i == r) continue;
		if(a[i][c] == a[r][c]){
			// d[i][c]++;
			// mxcheck(i,c);
			d[r][c]++;
			// mxcheck(r,c);
		}
	}
}

void redr(int r,int c){
	For(i,0,n){
		if(i == c) continue;
		if(a[r][i] == a[r][c]){
			d[r][i]--;
			// mxcheck(r,i);
			d[r][c]--;
			// mxcheck(r,c);
		}
	}
}
void redc(int r,int c){
	For(i,0,n){
		if(i == r) continue;
		if(a[i][c] == a[r][c]){
			d[i][c]--;
			// mxcheck(i,c);
			d[r][c]--;
			// mxcheck(r,c);
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
    int tsn = 0;
    tests{
    	// int n;
    	cin >> n;
		tsn++;    	
    	For(i,0,n){
    		For(j,0,n){
    			cin >> a[i][j];
    			d[i][j] = 0;
    		}
    	}
    	For(i,0,n){
    		For(j,0,n){
    			int cc =  a[i][j];
    			checkr(i,j);
    			checkc(i,j);
    		}
    	}
    	int ans = 0;
 	   	//find max and reduce
 	   	while(findmx() && ans < 1000000){
 	   		ans++;
 	   		// Debug(dmax)
 	   		// Debug(mr)
 	   		// Debug(mc)
 	   		redr(mr,mc);
 	   		redc(mr,mc);
 	   		a[mr][mc] = 1000+ans;
 	   		d[mr][mc] = 0;
 	   	}
 	   	cout << "Case #"<<tsn<<": ";
    	cout << ans << "\n";
    }
    return 0;
}