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
    int n;cin >> n;
    long long int a[n+1],minf[n+1],maxf[n+1],b[n+1];
    For(i,1,n+1){
    	cin >> a[i];
    }
    long long int mn,mx;
    For(i,5,n+1){
    	mn = INT_MAX;
    	mx = -1;
    	For(j,i-4,i+1){
    		mn = min(mn,a[j]);
    		mx = max(mx,a[j]);
    	}
    	minf[i] = mn;
    	maxf[i] = mx;
    	// Debug(mn)
    	// Debug(mx)
    }
    long long int l=0,r=0;
    string s;cin >> s;
    For(i,0,n){
    	if(s[i] == '0'){
    		b[i+1] = 0;
    	}else b[i+1] = 1;
    	// Debug(i+1)
    	// Debug(b[i+1])

    }
    int zc=4,oc=0;//zero and one count
    int pr = 0;
    int lin=0,rin=0;
    cout << "0 0 0 0 ";
    For(i,5,n+1){//Debug(s[i])
    	// Debug(b[i])
    	Debug(minf[i]) Debug(oc)
    	if(zc == 4 && maxf[i] < lin){
    		cout << "1 ";pr=1;
    	}else if(oc == 4 && minf[i] > rin){
    		cout << "0 ";pr=0;
    	}else cout << pr << " ";

    	//////////////////////////////	
    	if(b[i] == 0){
    		if(zc == 4 && maxf[i] < l){
    			l = maxf[i];
    		}
    		if(b[i-1] == 1){
    			if(oc == 4 && minf[i] <= r){
    				r = minf[i]-1;
    			}
    		}
    	}else{
    		
    		if(oc == 4 && minf[i] > r){
    			r = minf[i];
    		}
    		if(b[i-1] == 0){
    			if(zc == 4 && maxf[i] >= l){
    				l = maxf[i] + 1;
    			}
    		}
    	}
    	if(b[i-5] == 0){
    		zc--;
    	}else oc--;
    	if(b[i] == 0){
    		zc++;
    	}else oc++;
    }

    // cout << l << " "<< r;

    For(i,5,n+1){

    }
 	

    return 0;
}