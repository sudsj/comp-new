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
long long int a[200000];
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
 	tests{
 		int n;
 		cin >> n;
 		For(i,1,n+1) cin >> a[i];
 		long long int l,r,ln,rn,ans=0,ans1=0,ansf=0;int lm = 0,rm=1,flag=0;
 		if(n%2 == 0){
 			//even splits
 			
 			l = a[(n/2)];r = a[(n/2)+1];

 			//type 1 seq
 			lm = 0,rm=1;
 			ans = 0;
 			// > l < r > 
 			//0 == > 1 == <
 			flag = 0;
 			if(l >= r){
 				flag = 1;goto skip;
 			}

 			for(int i = (n/2)-1;i>=1;i--){//Debug(l) Debug(r)
 				ln = a[i];
 				rn = a[n+1-i];
 				if(lm == 0){
 					if(ln > l && r > rn){

 					}else{
 						swap(ln,rn);
 						ans++;
 						if(ln > l && r > rn){

 						}else{
 							//Debug(ln)
 							flag = 1;
 							break;
 						}
 					}
 					lm = 1-lm;
 				}else{
 					if(ln < l && r < rn){

 					}else{
 						swap(ln,rn);
 						ans++;
 						if(ln < l && r < rn){

 						}else{
 							flag = 1;
 							break;
 						}
 					}
 					lm = 1-lm;
 				}
 				l = ln;
 				r = rn;
 			}
 			skip: ;
 			if(flag == 1){
 				ans = INT_MAX;//not possible
 			}
 			l = a[(n/2)];r = a[(n/2)+1];
 			//type 1 seq

 			lm = 1;
 			ans1 = 0;
 			// > l < r > 
 			//0 == > 1 == <
 			flag = 0;
 			if(l <= r){
 				flag = 1;goto skips;
 			}
 			for(int i = (n/2)-1;i>=1;i--){
 				ln = a[i];
 				rn = a[n+1-i];
 				if(lm == 0){
 					if(ln > l && r > rn){

 					}else{
 						swap(ln,rn);
 						ans1++;
 						if(ln > l && r > rn){

 						}else{
 							flag = 1;
 							break;
 						}
 					}
 					lm = 1-lm;
 				}else{
 					if(ln < l && r < rn){

 					}else{
 						swap(ln,rn);
 						ans1++;
 						if(ln < l && r < rn){

 						}else{
 							flag = 1;
 							break;
 						}
 					}
 					lm = 1-lm;
 				}
 				l = ln;
 				r = rn;
 			}
 			skips: ;
 			if(flag == 1){
 				ans1 = INT_MAX;//not possible
 			}
 			ansf = min(ans1,ans);
 			if(ansf == INT_MAX){
 				cout <<"-1\n";
 			}else cout << ansf << "\n";
 		}else{
 			//n is odd
 			l = a[((n+1)/2)];r = l;//Debug(l)
 			//type 1 seq
 			lm = 0,rm=1;
 			ans = 0;
 			// > l < r > 
 			//0 == > 1 == <
 			flag = 0;
 			for(int i = (n/2);i>=1;i--){//Debug(i)
 				// Debug(l)
 				// Debug(r)

 				ln = a[i];
 				rn = a[n+1-i];
 				// Debug(ln)
 				// Debug(rn)
 				if(lm == 0){
 					if(ln > l && r < rn){

 					}else{
 						swap(ln,rn);
 						ans++;
 						if(ln > l && r < rn){

 						}else{
 							flag = 1;
 							break;
 						}
 					}
 					lm = 1-lm;
 				}else{
 					if(ln < l && r > rn){

 					}else{
 						swap(ln,rn);
 						ans++;
 						if(ln < l && r > rn){

 						}else{
 							flag = 1;
 							break;
 						}
 					}
 					lm = 1-lm;
 				}
 				l = ln;
 				r = rn;
 			}
 			if(flag == 1){
 				ans = INT_MAX;//not possible
 			}
 			l = a[((n+1)/2)];r = l;r =l;
 			//type 1 seq
 			lm = 1;
 			ans1 = 0;
 			// > l < r > 
 			//0 == > 1 == <
 			flag = 0;
 			for(int i = (n/2);i>=1;i--){
 				// Debug(l)
 				// Debug(r)

 				ln = a[i];
 				rn = a[n+1-i];
 				// Debug(ln)
 				// Debug(rn)
 				if(lm == 0){
 					if(ln > l && r < rn){

 					}else{
 						swap(ln,rn);
 						ans1++;
 						if(ln > l && r < rn){

 						}else{
 							flag = 1;//Debug(i)
 							break;
 						}
 					}
 					lm = 1-lm;
 				}else{
 					if(ln < l && r > rn){

 					}else{
 						swap(ln,rn);
 						ans1++;
 						if(ln < l && r > rn){

 						}else{
 							flag = 1;//Debug(i)
 							break;
 						}
 					}
 					lm = 1-lm;
 				}
 				l = ln;
 				r = rn;
 			}
 			if(flag == 1){
 				ans1 = INT_MAX;//not possible
 			}
 			ansf = min(ans1,ans);
 			if(ansf == INT_MAX){
 				cout <<"-1\n";
 			}else cout << ansf << "\n";
 		}

 	}
    return 0;
}