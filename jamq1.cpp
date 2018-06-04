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

    int testn = 0;
    tests{
    	testn++;
    	int r,c,h,v;
    	cin >> r >> c >> h >> v;
    	string ss;
    	int a[r][c];
    	For(i,0,r) For(j,0,c) a[i][j] = 0;
    	int chipc = 0;
    	For(i,0,r){
    		cin >> ss;
    		// Debug(ss)
    		For(j,0,c){
    			if(ss[j] == '@'){
    			 a[i][j]=1;
    			 chipc++;
    			}
    		}
    	}
    	int pcs = (h+1)*(v+1);
    	if(chipc%pcs == 0){

    		int flag = 0;

    		int per = chipc/pcs;
    		std::vector<int> rc,cc;
    		int chc = 0;
    		int ri=0,ci=0;
    		std::vector<int> ckk(c+1);
    		if(chipc == 0){
    			flag = 0;
    			goto skips;
    		}
    		if(h == 1 && v == 1){
    			flag = 1;
    			For(il,0,r-1){
    				For(jl,0,c-1){
    					//cut below i and to right of j
    					int c1 = 0,c2=0,c3=0,c4=0;
    					For(i,0,il+1){
    						For(j,0,jl+1){
    							if(a[i][j] == 1) c1++;
    						}
    					}
    					For(i,0,il+1){
    						For(j,0,c){
    							if(a[i][j] == 1) c2++;
    						}
    					}
    					c2 -= c1;
    					For(i,il+1,r){
    						For(j,jl+1,c){
    							if(a[i][j] == 1) c3++;
    						}
    					}
    					For(i,il+1,r){
    						For(j,0,c){
    							if(a[i][j] == 1) c4++;
    						}
    					}
    					c4 -= c3;
    					// int tt = 
    					if(c1 == per && c2 == per && c3 == per && c4 == per){
    						flag = 0;
    					}
    				}
    			}
    			goto skips;
    		}
    		For(i,0,r){
    			For(j,0,c){
    				if(a[i][j] == 1){
    					chc++;
    				}
    			}
    			if(chc == per*(v+1)){
    				rc.push_back(i);
    				// Debug(i)
    				chc = 0;
    			}
    			if(chc > per*(v+1)){
    				flag = 2;
    				goto skips;
    				break;
    			}
    		}
    		if(rc.size() == h+1){

    		}else{
    			flag = 3;goto skips;
    		}
    		if(rc[h] == r-1){

    		}else{
    			flag = 3;goto skips;
    		}
    		chc = 0;
    		For(j,0,c){
    			For(i,0,r){
    				if(a[i][j] == 1){
    					chc++;
    				}
    			}
    			if(chc == per*(h+1)){
    				// Debug(j)
    				cc.push_back(j);
    				chc = 0;
    			}
    			if(chc > per*(h+1)){
    				flag = 4;
    				goto skips;
    				break;
    			}
    		
}    		if(cc.size() == v+1){

    		}else{
    			flag = 5;goto skips;
    		}
    		if(cc[v] == c-1){

    		}else{
    			flag = 5;goto skips;
    		}
    		For(i,0,v+1) ckk[i]=0;
    		ri=0;ci=0;
    		For(i,0,r){
    			if(i > rc[ri]){
    				//check	
    				// Debug(i)
    				// Debug(rc[ri])
    				For(k,0,v+1){
    					// Debug(k)
    						// Debug(ckk[k])
    					if(ckk[k] == per){

    					}else{

    						flag = 6;goto skips;
    					}
    				}
    				//
    				ri++;
    				For(i,0,v+1) ckk[i]=0;
    			}
    			For(j,0,c){
    				if(j > cc[ci]){
    					// Debug(j)
    					ci++;
    				}
    				if(a[i][j] == 1){
    					ckk[ci]++;
    				}
    			}
    			ci=0;
    		}
    		For(k,0,v+1){
    			if(ckk[k] == per){

    			}else{
    				flag = 7;goto skips;
    			}
    		}

    		skips:
    		if(flag != 0){
    			// Debug(flag)
    			cout << "Case #"<< testn<< ": IMPOSSIBLE\n";
    		}else{
    			cout << "Case #"<< testn <<": POSSIBLE\n";
    		}
    	}else{
    		cout << "Case #"<< testn<< ": IMPOSSIBLE\n";
    	}
    }



 	

    return 0;
}