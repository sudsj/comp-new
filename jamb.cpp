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
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int cn = 0;
    tests{
    	int n;cin>>n;
    	long long int a[n+10],b[n],c[n],s[n];
    	int bi = 0,ci=0;
    	cn++;
    	cout << "Case #"<<cn<<": ";
    	For(i,0,n){
    		cin >> a[i];
    		if(i%2==0){
    			b[bi] = a[i];
    			bi++;
    		}else{
    			c[ci] = a[i];
    			ci++;
    		}
    	}
    	sort(b,b+bi);sort(c,c+ci);
    	bi = 0;ci=0;
    	For(i,0,n){
    		if(i%2==0){
    			s[i] = b[bi];
    			bi++;
    		}else{
    			s[i] = c[ci];
    			ci++;
    		}
    	}
    	long long int min = -1;int flag = 0;
    	For(i,0,n){
    		if(s[i] >= min){
    			min = s[i];
    		}else{
    			cout << i-1 <<"\n"; 
    			flag = 1;break;
    		}
    	}
    	if(flag){
    		continue;
    	}else cout << "OK\n";
    }


 	   	
    return 0;
}