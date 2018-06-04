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
std::vector<int> v,ans;
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);


    int n,k,ld;
    cin >> n >> k >> ld;
 	long long int total = n*k*1LL;
 	int w;
 	For(i,0,total){
 		cin >> w;
 		v.push_back(w);
 	}   		
 	sort(v.begin(), v.end());
 	long long int min = v[0];
 	long long int max = v[0]+ld;
 	int count = 1;long long int maxi = total-1;
 	v[0] *= -1;
 	long long int flak = 0;
 	ans.push_back(abs(v[0]));
 	For(i,1,total){
 		if(count  == n) break;
 		flak++;
 		if(v[i] > max){
 			maxi = i-1;
 			break;
 		}
 		if(flak == k){
 			v[i] *= -1;
 			ans.push_back(abs(v[i]));
 			count++;
 			flak = 0;
 		}
 		
 	}
 	// Debug(count)
 	if(count != n){
 		for(int j = maxi; j>=0;j--){
 			if(v[j] > 0){
 				ans.push_back(v[j]);
 				count++;
 				if(count  == n) break;
 			}
 		}
 	}
 	// Debug(max)

 	// Debug(maxi)
 	// Debug(v[maxi])
 	if(count != n){
 		cout << "0";
 	}else{
 		long long int sum = 0;
 		For(i,0,n){
 		 sum += ans[i];
 		 // Debug(ans[i])
 		}
 		cout << sum;
 	}
    return 0;
}