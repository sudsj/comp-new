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
    int n; cin >> n;
    std::vector<int> v;
    double a[n][5];
    For(i,0,n){
    	For(j,0,5){
    		cin >> a[i][j];
    	}
    }
    int s,flag;
    For(i,0,n){
    	flag = 0;
    	For(j,0,i){
    		For(k,j+1,i){
    			//ij.ik if > 0 then its bad so stop
    			s = 0;
    			For(m,0,5){
    				s += (a[j][m] - a[i][m])*(a[k][m] - a[i][m]); 
    			}
    			if(s > 0){
    				flag = 1;
    				goto brk;
    			}
    		}
    		For(k,i+1,n){
    			s = 0;
    			For(m,0,5){
    				s += (a[j][m] - a[i][m])*(a[k][m] - a[i][m]); 
    			}
    			if(s > 0){
    				flag = 1;
    				goto brk;
    			}

    		}
    	}
    	For(j,i+1,n){
    		For(k,j+1,n){
    			s = 0;
    			For(m,0,5){
    				s += (a[j][m] - a[i][m])*(a[k][m] - a[i][m]); 
    			}
    			if(s > 0){
    				flag = 1;
    				goto brk;
    			}

    		}
    	}
    	brk : 
    	if(flag == 0) v.push_back(i);
    }
    int size = v.size();
    cout << size << "\n";
    For(i,0,size){
    	cout << v[i] + 1<<"\n";
    }
    return 0;
}
