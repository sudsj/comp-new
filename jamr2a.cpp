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

    int tsn=0;
    tests{
    	tsn++;

    	int c;cin >> c;
    	int b[c];
    	For(i,0,c) cin >> b[i];
    	cout << "Case #"<<tsn<<": ";
    	int flag = 0;
    	std::vector<int> r[1000];
    	std::vector<int> tgt(c);
    	int rsize = 0;
    	For(j,0,1000){
    		For(i,0,c){
    			r[j].push_back(0);
    		}
    	}
    	int cc = 0,sum = 0,rn=0,mrn=-1;
    	if(b[0] < 1 || b[c-1] < 1){
    		flag = 1;goto skips;
    	}

    	For(i,0,c){
    		sum += b[i];
    		For(j,cc,sum){
    			tgt[j] = i;
    		}
    		cc = sum;
    	}
    	cc = 0;
 	   	For(i,0,c){
 	   		// cout<<"\n";
 	   		// For(ii,0,2){
 	   		// 	For(j,0,c){
 	   		// 		if(r[ii][j] == 0){
 	   		// 			cout << ".";
 	   		// 		}else if(r[ii][j] == 1){
 	   		// 			cout << "/";
 	   		// 		}else cout << "\\";
 	   		// 	}
 	   		// 	cout << "\n";
 	   		// }
 	   		//reach tgt[i]
 	   		// Debug(tgt[i])
 	   		if(tgt[i] == i) continue;
 	   		if(tgt[i] < i){
 	   			//go to left
 	   			rn = abs(tgt[i]-i);
 	   			rsize = max(rsize,rn);
 	   			rn--;
 	   			For(j,tgt[i]+1,i+1){
 	   				//j is column no.
 	   				r[rn][j] = 1;//left
 	   				rn--;
 	   			}
 	   		}else{
 	   			//got to right
 	   			rn = 0;
 	   			rsize = max(rsize,abs(tgt[i]-i));
 	   			For(j,i,tgt[i]){
 	   				//j is column no.
 	   				r[rn][j] = 2;//left
 	   				rn++;
 	   			}
 	   		}
 	   		



 	   	}


 	   	skips:;
 	   	if(flag){
 	   		cout << "IMPOSSIBLE\n";
 	   	}else{
 	   		cout << rsize+1<<"\n";
 	   		// print rows
 	   		For(i,0,rsize+1){
 	   			For(j,0,c){
 	   				if(r[i][j] == 0){
 	   					cout << ".";
 	   				}else if(r[i][j] == 1){
 	   					cout << "/";
 	   				}else cout << "\\";
 	   			}
 	   			cout << "\n";
 	   		}
 	   	}

    
    }
    return 0;
}