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
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
 
 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 
 
151, 157, 163};

long long int dp[20][10][200];
//dp[x][y][s] x digit starts with y and ends with s

long long int num,count=0;

long long int nsum(int s, long long int m){
	//nums <= m with sum of digits = s;
	long long int t = m,c=0;
	int a[20]={0};
	int digits = 1;
	while(t >= 10){
		t /= 10;
		digits++;	
	} 
	t = m;
	For(i,1,digits+1){
		a[i] = t%10;
		t = t/10;
	}
	For(i,0,a[1]+1){
		c += dp[digits][i][s];
	}
	s -= a[1];//fix 1st num
	if(s >= 0){
		For(i,2,digits+1){
			For(j,a[i],9){
				c -= dp[digits][a[i]][s];
			}
			s -= a[i];
			if(s < 0) break;
		}
	}
	return c;
}

int main()
{
	For(i,0,20){
		For(j,0,10){
			For(k,0,200){
				dp[i][j][k] = 0;
			}
		}
	}
	For(i,0,10){
		dp[1][i][i] = 1;
	}
	int tp = 0;
	For(s,0,165){
		For(d,2,20){
			For(k,0,10){
				For(i,0,10){ 
					if( s-k >= 0) tp = dp[d-1][i][s-k]; else tp = 0; 
					dp[d][k][s] += tp;
				}
			}
			
		}
	}
	
	tests{
		long long int a,b;
		cin >> a >> b;
		long long int ans = 0,tm=0;
		For(i,0,primes.size()){
			ans += nsum(primes[i], b-1) - nsum(primes[i], a);
			if(ans >= mod) ans %= mod;
		}
		cout << ans << "\n";

	}
    
    return 0;
}
