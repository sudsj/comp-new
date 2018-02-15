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
 	// tests{
 		long long int k,a,b;long long int sumpre = 0,sum = 0;

 		// cin >> a >> b;
 		k = 25;
 		For(i,1,10){
 			For(j,0,10){
 				a = i;b=j;
 				// Debug(a) Debug(b)
 				sumpre = 0;
 				std::vector<int> v;
 				v.push_back(a);
 				v.push_back(b);
 				sumpre = a+b;
 				// v.push_back
 				For(i,0,k-2){
 					v.push_back(sumpre%10);
 					sumpre += v[2+i]; 
 				}
 				// For(i,0,20){
 				// 	cout << v[i] << " ";
 				// }
 				// if(sumpre%3 == 0){
 				// 	cout << "YES\n";
 				// }else cout << "NO\n";
 				// cout << "\n";

 				sum = 0;
 				long long int m1 = (k-3)/4;
 				long long int m2 = (k-3)%4;
 				int d[5];d[0] = a+b;d[1] = d[0]%10;

 				d[2] = (d[0] + d[1])%10;
 				d[3] = (d[0] + d[1] + d[2])%10;
 				d[4] = (d[0] + d[1] + d[2] + d[3])%10;
 				d[5] = (d[0] + d[1] + d[2] + d[3] + d[4])%10;
 				// For(i,0,4){
 					// d[i] = d[i-1] + d[i-2];
 				// }
 				// cout << "\n";
 				// Debug(a)
 				// Debug(b)
 				// Debug(d[1])
 				For(i,2,6) sum += d[i];
 				// For(i,2,6) cout << d[i] << " ";
 				// Debug(sum)
 				// Debug(m1)
 				// Debug(m2)
 				sum = sum%3;
 				m1 = m1%3;
 				// Debug(m1)
 				sum *= m1;
 				sum += d[0] + d[1];
 				// Debug(sum)
 				For(i,2,m2+2){ sum += d[i];
 					// Debug(d[i])
 				}
 				// cout << "\n";
 				
 				if( (sum%3) != (sumpre%3)){
 					Debug(a) Debug(b)
 					Debug(sum) Debug(sumpre)
 				}
 			}
 		}

 		
 		

 	// }    
    return 0;
}