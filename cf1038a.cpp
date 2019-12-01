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
    
    long long int sa=0,sb=0;
    int n; cin >> n;
    int a[n];int b[n];
    For(i,0,n){
    	cin >> a[i];

    }
    For(i,0,n){
    	cin >> b[i];
    	
    }
    sort(a,a+n);
    sort(b,b+n);
    int ain = n-1;
    int bin = n-1;
    For(i,0,2*n){
    	if(i%2 == 0){
    		//turn a
    		if(ain <= -1){
    			bin -= 1;//delete from b
    		}else if(bin <= -1){
    			sa += a[ain];
    			ain--;
    		}else{
    			//compare
    			if(a[ain] > b[bin]){
    				sa += a[ain];
    				ain--;
    			}else{
    				bin--;
    			}
    		}
    	}else{
    		//turn b
    		if(bin <= -1){
    			ain -= 1;//delete from a
    		}else if(ain <= -1){
    			sb += b[bin];
    			bin--;
    		}else{
    			//compare
    			if(b[bin] > a[ain]){
    				sb += b[bin];
    				bin--;
    			}else{
    				ain--;
    			}
    		}
    	}
    }
    cout << sa - sb;

    ///////////
    return 0;
}