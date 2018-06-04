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
    	int n,m;
    	cin >> n >> m;
    	long long int a[n][m];
    	long long int hrs[n][m];//stores max sum towards right horizontal 
    	long long int hls[n][m];
    	long long int vus[n][m];
    	long long int vds[n][m];//vertical down sum
    	For(i,0,n){
    		For(j,0,m){
    			cin >> a[i][j];
    		}
    	}
    	//hrs
    	long long int cumh[m]={0};//horizontal cum sum
    	int maxi[m]={0};
    	For(i,1,n-1){
    		//for each row
    		cumh[0] = a[i][0];
    		For(j,1,m){
    			cumh[j] = cumh[j-1] + a[i][j];
    		}
    		long long int cmax = cumh[m-1];
    		int maxind = m-1;
    		for(int j = m-1; j>= 0; j--){
    			if(cumh[j] >= cmax){
    				maxind = j;
    				maxi[j] = maxind;
    			}else maxi[j] = maxind;
    		}
    		For(j,1,m-1){
    			hrs[i][j] = cumh[maxi[j+1]] - cumh[j-1];
    			// Debug(hrs[i][j])
    		}
    	}
    	//hls
    	For(i,1,n-1){
    		//for each row
    		cumh[m-1] = a[i][m-1];
    		for(int j = m-2; j >= 0; j--){
    			cumh[j] = cumh[j+1] + a[i][j];
    		}
    		long long int cmax = cumh[0];
    		int maxind = 0;
    		For(j,0,m){
    			if(cumh[j] >= cmax){
    				maxind = j;
    				maxi[j] = maxind;
    			}else maxi[j] = maxind;
    		}
    		for(int j = m-2; j >= 1;j--){
    			hls[i][j] = cumh[maxi[j-1]] - cumh[j+1];
    			// Debug(hls[i][j])
    		}
    	}
    	//vus
    	long long int cumv[n]={0};//horizontal cum sum
    	int maxiv[n]={0};
    	For(i,1,m-1){
    		//for each column
    		cumv[n-1] = a[n-1][i];
    		for(int j = n-2; j >= 0; j--){
    			cumv[j] = cumv[j+1] + a[j][i];
    		}
    		long long int cmax = cumv[0];
    		int maxind = 0;
    		For(j,0,n){
    			if(cumv[j] >= cmax){
    				maxind = j;
    				maxiv[j] = maxind;
    			}else maxiv[j] = maxind;
    		}
    		for(int j = n-2; j >= 1;j--){
    			vus[j][i] = cumv[maxiv[j-1]] - cumv[j+1];
    			// Debug(vus[j][i])
    		}
    	}
    	//vds
    	For(i,1,m-1){
    		//for each column
    		cumv[0] = a[0][i];
    		For(j,1,n){
    			cumv[j] = cumv[j-1] + a[j][i];
    		}
    		long long int cmax = cumv[n-1];
    		int maxind = n-1;
    		for(int j = n-1; j>= 0;j--){
    			if(cumv[j] >= cmax){
    				maxind = j;
    				maxiv[j] = maxind;
    			}else maxiv[j] = maxind;
    		}
    		For(j,1,n-1){
    			vds[j][i] = cumv[maxiv[j+1]] - cumv[j-1];
    			// Debug(vds[j][i])
    		}
    	}
    	//final
    	long long int maxs;
    	long long int summ;
    	summ = hrs[1][1] + hls[1][1] + vds[1][1] + vus[1][1];
    	summ -= 3*a[1][1];
    	maxs = summ;
    	For(i,1,n-1){
    		For(j,1,m-1){
    			summ = hrs[i][j] + hls[i][j] + vds[i][j] + vus[i][j];
    			summ -= 3*a[i][j];
    			// Debug(summ)

    			maxs = max(maxs,summ);
    			// if(summ == -12){ Debug(i) Debug(j)}
    		}
    	}
    	cout << maxs << "\n";
    }

 	//   	
    return 0;
}