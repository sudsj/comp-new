#include <bits/stdc++.h>
#include <iomanip>
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

    std::cout << std::fixed;
    std::cout << std::setprecision(9);
    int n,in;long long int x,u;
    //long long int e[100100] = {0};
    cin >> n >> u;
    std::vector<long long int > v;
    For(i,0,n){
    	cin >> x;
    	v.push_back(x);
    }
    std::vector<long long int>::iterator low,up;
    long long int tar,val;int flag = 0;
    double maxr=-1.0,r,ek,ei,ej,num,den;
    For(i,0,n-2){
    	tar = v[i] + u;
    	low=std::lower_bound (v.begin()+i+2, v.end(), tar);
    	in = low - v.begin();
    	// Debug(in)
    	val = v[in];
    	if(val == tar){

    	}else{
    		if(in == i+2) continue;
    		val = v[in-1];
    		
    	}
    	ej = v[i+1]*1.0;
    	flag = 1;
    	ek = val*1.0;
    	ei = v[i]*1.0;
    	num = ek-ej;
    	den = ek-ei;
    	r = num/den;
    	// Debug(i+1)
    	// Debug(v[i])
    	// Debug(r)
    	maxr = max(r,maxr);

	}
	if(flag){
		cout << maxr;
	}else cout << "-1";

 	   	
 	int w;   	
    return 0;
    
    
}