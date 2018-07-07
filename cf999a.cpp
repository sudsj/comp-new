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
    long long int incr = 0;
    long long int n,m;cin >> n >> m;
    long long int tgt = n/m;
    // Debug(tgt)
    long long int c[m] = {0};long long int a[n];
    long long int xc = 0;
    For(i,0,n) cin >> a[i];
    For(i,0,n){
    	xc = a[i]%m;
    	c[xc] += 1;
    }
    deque<long long int> rem;
    deque<long long int> count;
    std::vector<long long int> v[m];
    long long int upd[m] = {0};
    long long int sizes[m] = {0};
    For(i,0,m){
    	// Debug(c[i])
    	if(c[i] == tgt) continue;
    	if(c[i] > tgt){
    		//donor
    		rem.push_back(i);
    		count.push_back(c[i]-tgt);
    	}else{
    		//taker
    		if(!rem.empty()){
    			while(!rem.empty() && c[i] < tgt){
    				//use pop backs
    				long long int req = tgt - c[i];
    				long long int avb = count.back();
    				long long int donor = rem.back();
    				if(req < avb){
    					//make array changes
    					For(j,0,req){
    						if(donor < i){
    							incr = i - donor;
    						}else{
    							incr = i - donor + m;
    						}
    						v[donor].push_back(incr);
    					}
    					//
    					c[i] = tgt;
    					count.pop_back();
    					avb -= req;
    					count.push_back(avb);
    				}else{
    					//make array changes
    					For(j,0,avb){
    						if(donor < i){
    							incr = i - donor;
    						}else{
    							incr = i - donor + m;
    						}
    						v[donor].push_back(incr);
    					}
    					//
    					c[i] += avb;
    					count.pop_back();
    					rem.pop_back();
    				}
    			}
    		}
    	}
    }
    For(i,0,m){
    	if(c[i] == tgt) continue;
    	if(c[i] > tgt){
    		//donor
    		rem.push_back(i);
    		count.push_back(c[i]-tgt);
    	}else{
    		//taker
    		if(!rem.empty()){
    			while(!rem.empty() && c[i] < tgt){
    				//use pop backs
    				long long int req = tgt - c[i];
    				long long int avb = count.back();
    				long long int donor = rem.back();
    				if(req < avb){
    					//make array changes
    					For(j,0,req){
    						if(donor < i){
    							incr = i - donor;
    						}else{
    							incr = i - donor + m;
    						}
    						v[donor].push_back(incr);
    					}
    					//
    					c[i] = tgt;
    					count.pop_back();
    					avb -= req;
    					count.push_back(avb);
    				}else{
    					//make array changes
    					For(j,0,avb){
    						if(donor < i){
    							incr = i - donor;
    						}else{
    							incr = i - donor + m;
    						}
    						v[donor].push_back(incr);
    					}
    					//
    					c[i] += avb;
    					count.pop_back();
    					rem.pop_back();
    				}
    			}
    		}
    	}
    }
    long long int ans = 0;
    For(i,0,m){
    	sizes[i] = v[i].size();
    }
    For(i,0,n){
    	long long int remss = a[i]%m;
    	if(upd[remss] < sizes[remss]){
    		a[i] += v[remss][upd[remss]];
    		ans += v[remss][upd[remss]];
    		upd[remss] += 1;
    		// ans++;
    	}
    }
    cout << ans << "\n";
    For(i,0,n){
    	cout << a[i] << " ";
    }
 	//	   	
    return 0;
}