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
long long int a[600000] = {0};
long long int psum[600000] = {0};
int main()
{	//remove this before submit
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int csn = 0;
    tests{
    	csn++;
    	long long int n,oddlim,d;
    	cin >> n >> oddlim >> d;
    	long long int x0,x1,A,b,c,m,l;
    	cin >> x0 >> x1 >> A >> b >> c >> m >> l;
    	a[0] = x0;a[1] = x1;
    	For(i,2,n){
    		a[i] = A*a[i-1];
    		a[i] = a[i]%m;
    		a[i] += (b*a[i-2])%m;
    		a[i] = a[i]%m;
    		a[i] += c;
    		a[i] = a[i]%m;
    	}
    	For(i,0,n){
    		a[i] += l;
    	}
    	psum[0] = a[0];
    	For(i,1,n){
    		// Debug(a[i])
    		psum[i] = psum[i-1] + a[i];
    	}
    	cout << "Case #" << csn << ": ";
    	long long int csum = 0,gmax = -1e18;
    	int flag = 0;//impossible
    	long long int odds = 0;
    	int start = 0;

    	multiset <long long int> pset;
    	pset.insert(0);
    	multiset <long long int>::iterator it;
    	For(i,0,n){
    		if(a[i]%2 != 0){
    			odds++;
    		}
    		if(odds > oddlim){
    			while(odds > oddlim){
    				if(start >= i) break;
    				if(a[start]%2 != 0) odds--;
    				//search for p[start] and delete
    				if(start > 0){
    					it = pset.find(psum[start-1]);
    					
    				}else it = pset.find(0);
    				pset.erase(it);
    				start++;
    			}
    		}
    		
    		//lower_bound returns the first element that returns
    		//false for the comparison type
    		//here the default(if not specified) is < so this finds 
    		//lowest number that is just bigger than p[i]-d
    		it = pset.lower_bound(psum[i]-d);
    		// Debug(psum[i]-d)
    		if(it != pset.end()){
    			// Debug(a[i]) Debug(a[start])

    			flag = 1;
    			csum = psum[i] - *it;
    			// Debug(csum)
    			gmax = max(csum,gmax);
    		}
    		pset.insert(psum[i]);

    	}
    	if(flag){
    		cout << gmax << "\n";
    	}else{
    		cout << "IMPOSSIBLE\n";
    	}
    }


 	   	
    return 0;
}