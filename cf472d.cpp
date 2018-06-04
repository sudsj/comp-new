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
    int n;cin >> n;long long int a[n];
    For(i,0,n){
    	cin >> a[i];
    }
    long long int ab = 0,bl = 0, tt = 1,dif,tmp;
    long long int sum = 0;
    For(i,1,n){
    	// Debug(i)
    	// Debug(ab)
    	// Debug(tt)
    	// Debug(a[i])
    	// Debug(sum)
    	if(a[i] == ab){
    		//no change
    		sum += bl;

    		continue;
    	}
    	if(a[i] > ab){
    		if(a[i] < tt){
    			// no need to change total
    			dif = a[i] - ab;
    			ab = a[i];
    			bl -= dif;
    			sum += bl;
    		}else{
    			//put everything above
    			ab = a[i];
    			bl = 0;
    			dif = a[i] - tt;
    			tmp = dif*dif;
    			tmp += dif;
    			tmp /= 2;
    			sum += tmp;
    			tt = a[i] + 1;

    		}
    	}else{
    		dif = ab - a[i];
    		ab = a[i];
    		bl += dif;
    		sum += bl;
    	}
    }

    cout << sum;
 	int ww;   	
    return 0;
}