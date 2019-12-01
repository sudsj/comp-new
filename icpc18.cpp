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
    

    tests{
    	int n,k;
    	cin >> n >> k;
    	std::vector<int> v,r;
    	int x;
    	int sum = 0;
    	For(i,0,n){
    		cin >> x;
    		if(x > k){
    			sum += k;
    			x = x - k;
    			v.push_back(x);
    		}else{
    			sum += x;
    		}
    		// v.push_back(x);
    	}
    	sort(v.begin(), v.end());
    	int sz = v.size();
    	priority_queue<int, vector<int>, std::greater<int> > p;
    	sum += v[sz];
    	For(i,0,sz-1){
    		p.push(v[i]);
    	}
    	int ops = 10000000;
    	int a,b,c;
    	while(p.size() > 2 && ops > 0){
    		ops--;
    		

    	}
    	x = p.top();
    	p.pop();
    	x -= p.top();
    	sum -= x;
    	cout << sum << "\n";
    }

    ///////////
    return 0;
}