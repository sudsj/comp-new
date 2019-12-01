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
    	int n,m;cin >> n >> m;
    	int a[n][m];int b[n][m];
    	vector<int> r[27];
    	vector<int> c[27];
    	vector<int> pos(27,0);
    	vector<int> vv(27,0);
    	For(i,0,n){
    		string s;cin >> s;
    		// Debug(s)
    		For(j,0,m){
    			if(s[j] == '.'){
    				a[i][j] = 0;
    			}else a[i][j] = (int)(s[j] - 'a')  + 1;
    			b[i][j] = 0;
    		}
    	}
    	For(i,0,n){
    		For(j,0,m){
    			if(a[i][j] != 0){
    				int val = a[i][j];
    				r[val].push_back(i);
    				c[val].push_back(j);
    			}
    		}
    	}
    	int flag = 1;int last = 0;
    	For(i,1,27){
    		int rr = -1, cc = -1;
    		For(j,0,r[i].size()){
    			if(rr == -1){
    				rr = r[i][j];
    			}
    			if(rr != r[i][j]){
    				rr = -2;
    			}
    		}
    		For(j,0,c[i].size()){
    			if(cc == -1){
    				cc = c[i][j];
    			}
    			if(cc != c[i][j]){
    				cc = -2;
    			}
    		}
    		if(rr == -1 && cc == -1 ) continue;
    		if(rr == -2 && cc == -2){
    			flag = 0;break;
    		}
    		if(rr != -2){
    			//row wise
    			For(j,c[i][0],c[i][c[i].size()-1]+1){
    				b[rr][j] = i;
    			}
    			pos[i] = 1;
    			vv[i] = rr;
    		}else{
    			//col wise
    			For(j,r[i][0],r[i][r[i].size()-1]+1){
    				b[j][cc] = i;
    			}
    			pos[i] = 2;
    			vv[i] = cc;
    		}
    		last = i;
    	}
    	For(i,0,n){
    		For(j,0,m){
    			if(a[i][j] != b[i][j]){
    				flag = 0;
    			}
    		}
    	}
    	// For(i,0,n){
    	// 	For(j,0,m){
    	// 		cout << a[i][j] << " ";
    	// 	}
    	// 	cout << "\n";
    	// }
    	// Debug(flag)
    	// For(i,0,n){
    	// 	For(j,0,m){
    	// 		cout << b[i][j] << " ";
    	// 	}
    	// 	cout << "\n";
    	// }
    	if(flag){
    		cout << "YES\n";
    		cout << last << "\n";
    		int ex = 0;
    		For(i,1,last+1){
    			if(pos[i] == 0){
    				ex++;continue;
    			}else{
    				ex++;
    				if(pos[i] == 1){
    					//row wise
    					For(j,0,ex){
    						cout << vv[i]+1 << " " <<  c[i][0]+1 << " ";
    						cout << vv[i]+1 << " " <<  c[i][c[i].size()-1] +1<< " ";
    						cout << "\n";
    					}
    				}else{
    					For(j,0,ex){
    						cout <<  r[i][0] +1<< " " << vv[i]+1 << " " ;
    						cout <<  r[i][r[i].size()-1]+1 << " "<< vv[i]+1 << " " ;
    						cout << "\n";
    					}
    				}
    				ex = 0;
    			}
    		}
    	}else{
    		cout << "NO\n";
    	}
    }


    ///////////
    return 0;
}