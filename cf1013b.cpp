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

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);
    //cout << "21321";
    // return 0;
    int n,x;
     cin >> n >> x;
     int a[n],b[n];
     For(i,0,n) cin >> a[i];
     std::map<int, int> m,mb;
    For(i,0,n){
        m[a[i]] += 1;
    }
    For(i,0,n){
        if(m[a[i]] > 1){
            cout << "0";
            return 0;
        }
    }
    For(i,0,n){
        b[i] = a[i] & x;
        mb[b[i]] += 1;
        //Debug(b[i])
    }
    For(i,0,n){
        // Debug(a[i])
        // Debug(b[i])
        // Debug(m[b[i]])
        if(m[b[i]] >= 1 && b[i] != a[i]){
            cout << "1";
            return 0;
        }
    }
    For(i,0,n){
        if(mb[b[i]] > 1){
            cout << "2";
            return 0;
        }
    }
    cout << "-1";
 	//	   	
    return 0;
}