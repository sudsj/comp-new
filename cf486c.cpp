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
    int a[n+100];int pos[n+100];

    For(i,1,n+1){
    	cin >> a[i];
    	pos[a[i]] = i;
    }
    string e = "Petr";
    string o = "Um_nik";
    if(n%2 == 1){
    	o = "Petr";
    	e = "Um_nik";
    }
    int count = 0;
    For(i,1,n+1){
    	// cin >> a[i];
    	if(pos[i] != i){
    		count++;
    	}
    }
    Debug(count)
    // Debug(n)
    int swaps = 0;
    For(i,1,n+1){
    	Debug(i)
    	Debug(n)
    	// Debug(count)
    	// if(count <= 0) break;
    	// Debug(i)
    	// Debug(pos[i])

    	if(pos[i] == i){
    	 Debug(i)
    	 continue;
    	 
    	}
    	pos[a[i]] = pos[i];
    	pos[i] = i;

    	swap(a[i],i);
    	swaps++;

    }
    // Debug(count)
    Debug(swaps	)
    if(swaps%2 == 0){
    	cout << e;
    }else{
    	cout << o;
    }

 	//   	
    return 0;
}