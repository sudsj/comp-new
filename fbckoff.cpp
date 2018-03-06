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
std::vector<long long int> v[100001];
int in = 0;
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // Debug(in)
    tests{
    	in = 0;
    	int ar[3];
    	long long int n,al,bl,cl;
    	cin >> n ;
    	For(i,0,3) cin >> ar[i];
    	sort(ar,ar+3);
    	al = ar[0];
    	bl = ar[1];
    	cl = ar[2];
    	long long int sqr = (int) sqrt(n);
    	long long int abl = al*bl,ml,mf;
    	mf = max(abl,cl);ml = min(sqr,mf);
    	// std::vector<int> big,sm;

    	long long int b,s,ssqr,bsqr,ad,bd;
    	For(i,1,ml){
    		if(n%i == 0){
    			b = n/i;
    			s = i;
    			if(b > mf) continue;
    			//so b is bigger number,
    			//first try to factor smaller number
    			ssqr = (int) sqrt(s);
    			ssqr = min(ssqr,bl);
    			For(j,1,ssqr){
    				if(s%j == 0){
    					bd = s/j;
    					ad = j;
    					if(bd > bl) continue;
    					if(ad > al) continue;
    					//tuple is ad bd b
    					v[in].push_back(ad);
    					v[in].push_back(bd);
    					v[in].push_back(b);
    					in++;
    				}
    			}
    			if(s >= cl) continue;
    			//factor b 
    			bsqr = (int) sqrt(b);
    			// bsqr = min(bsqr,)
    			For(j,1,bsqr){
    				if(b%j == 0){
    					bd = b/j;
    					ad = j;
    					if(s > bd){
    						if(ad > al) continue;
    						if(bd > bl) continue;
    						if(s > cl) continue;
    						v[in].push_back(ad);
    						v[in].push_back(bd);
    						v[in].push_back(s);
    						in++;
    					}else if(s > ad){
    						if(ad > al) continue;
    						if(s > bl) continue;
    						if(bd > cl) continue;
    						v[in].push_back(ad);
    						v[in].push_back(s);
    						v[in].push_back(bd);
    						in++;
    					}else{
    						if(s > al) continue;
    						if(ad > bl) continue;
    						if(bd > cl) continue;
    						v[in].push_back(s);
    						v[in].push_back(ad);
    						v[in].push_back(bd);
    						
    						in++;
    					}
    				}
    			}
    		}
    	}
    	//now v[in] stores all pairs
    	long long int ans = 0;
    	For(i,0,in){
    		int ax = v[in][0];
    		int bx = v[in][1];
    		int cx = v[in][2];
    		//ax<=bx<=cx
    		if(cx <= al){
    			ans += 4;
    			if(b <= al) ans += 2;
    		}else if(cx <= bl){
    			ans += 2;
    			if(b <= al) ans += 2;
    		}else{
    			ans += 1;
    			if(b <= al) ans += 1;
    		}
    	}
    	cout << ans << "\n";
    	
 	}   	
    return 0;
    
}