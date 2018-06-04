#include <bits/stdc++.h>
#include <time.h> 
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
long long int ar[20000],p[20000],a[20000],ans[20000];
int n,m,k;
long long int summ(){
	long long int b=0,bs=0;
	For(i,0,m){
		b = 1;
		For(j,0,n){
			if(a[j] >= p[i]){
				b *= a[j]%p[i];
			}else{
				b *= a[j];
			}
			
			if(b >= p[i]){
				b %= p[i];
			}
		}
		if(b >= p[i]){
			b %= p[i];
		}
		bs += b;
	}
	return bs;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    srand(time(NULL));
    cin >> n >> m >> k;
    
    For(i,0,n) cin >> ar[i];
    For(i,0,m) cin >> p[i];
    
    long long int bmax,bx;
    For(i,0,n){
    	a[i] = ar[i];
    }
    bmax = summ();
    // Debug(bmax)
    For(i,0,n){
    	// Debug(a[i])
    	ans[i] = a[i];

    }
    For(j,0,10000){
    	For(i,0,n){
    		a[i] = ar[i] + rand()%k;
    		// Debug(a[i])
    	}
    	bx = summ();
    	// Debug(bx)
    	bmax = max(bx,bmax);
    	if(bmax == bx){
    		For(i,0,n){
    			ans[i] = a[i];

    		}
    	}
    	if(clock() > 2.9 * CLOCKS_PER_SEC) break;
    }
    long long int tt;
    For(i,0,n){
    	tt = ar[i]%p[m-1];
    	// dif = p[m-1]-1-tt;
    	tt = min(p[m-1]-1,tt+k);
    	for(int j = m-2;j>=0;j--){
    		if(tt%p[j] == 0){
    			tt--;//Debug(tt)
    		}
    	}
    	a[i] = tt;
    	//Debug(tt)
    }
    bx = summ();
    // Debug(bx)
    bmax = max(bx,bmax);
    if(bmax == bx){
    	For(i,0,n){
    		// Debug(a[i])
    		ans[i] = a[i];

    	}
    }

    For(i,0,n){
    	cout << ans[i]<<" ";
    }
    // Debug(bmax/n)




    

 	   	
    return 0;
}