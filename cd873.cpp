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
//#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
/////////////////////////////////////////////////////////////////////

 
int main(){
	int n,m;
	cin >> n >> m;
	int k; cin >> k;
	int a[n][m];
	For(i,0,n){
		For(j,0,m){
			cin >> a[i][j];
			//cout << i << " " << j << " " << a[i][j]<<"\n";
		}
	}
	int ans = 0;int sum = 0,msum=0,nans=0,ones=0,tsum=0;
	if(n > k){
		k--;//we include the current cell in sum by default
		For(i,0,m){
			sum = 0;nans=0;
			//for 0th
			For(p,0,k){
				sum += a[p][i];
			}
			//Debug(sum)
			ones = 0;msum=0;
			if(a[0][i] == 1) ones++,msum=sum;
			For(j,1,n-k){
				//sum = sum;
				sum -= a[j-1][i];
				sum += a[j+k][i];
				// Debug(j+k) Debug(m)
				// Debug(a[j+k][i])
				// Debug(sum)
				if(a[j][i] == 1){
					if(sum > msum) nans = ones;
					ones++;
				}
				
			}
			ans += nans;
			tsum += msum;
			// For(j,n-k,n){
			// 	sum -= a[j-1][i];
			// }
		}
	}else{
		For(i,0,n){
			For(j,0,m){
				tsum += a[i][j];
				//cout << i << " " << j << " " << a[i][j]<<"\n";
			}
		}
	}
	cout << sum<<" "<<ans;
	return 0;
}
 