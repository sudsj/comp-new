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
    	long long int n,k,ans;
    	cin >> n >> k;
    	if(n == 1){
    		cout << k << "\n";
    	}else if(k == 1){
    		For(i,0,n){
    			cout << 1 << " ";

    		}
    		cout << "\n";
    	}else{
    		//find largest power of k
            int p = 0;
            int kc = k;
            while(k > 0){
                // if(k%2 == 0) 
                k /= 2;
                p++;
            }
            k = kc;
            p--;
            // cout << pow(2,p)<<"\n";
            long long int a[n];
            a[0] = pow(2,p);
            a[1] = a[0]-1;
            if(n%2 == 0){
                For(i,2,n){
                    a[i] = 1;
                }
            }else{
                if(k == 2){
                    //Debug(n)
                    For(i,1,n){
                        a[i] = 1;
                    }
                }else if(k == 3){
                    For(i,0,n){
                        a[i] = 3;
                    }
                }else{
                    a[1] -= 1;

                    For(i,2,n){
                        a[i] = 1;
                    }
                }
            }
            For(i,0,n){
                cout << a[i] << " ";
            }
            cout << "\n";
            //check
            // int ch = a[0]^a[1];
            // For(i,2,n){
            //     ch = ch^a[i];
            // }
            // Debug(ch)
    	}



	 	   	
    }
    return 0;

}