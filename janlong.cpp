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
long long int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
std::vector<long long int> v,vb;

void rec(long long int n, int i){
	if(i == 15){
		v.push_back(n);
	}else{
		rec(n*p[i],i+1);
		rec(n,i+1);
	}

}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

 	    
 	long long int mul = 1;
 	rec(mul,0);
 	// Debug(v.size());
 	sort(v.begin(), v.end());
 	int size = v.size();
 	// Debug(v[size-4]*p[15]) - From here you can start pushing these numbers too
 	For(i,0,size-4){
 		v.push_back(v[i]*p[15]);
 	}
 	// Debug(v.size());
 	sort(v.begin(), v.end());
 	size = v.size();

 	long long int n,m; cin >> n;
 	// Debug(v[0])
 	int i = 0,in=0;
 	while(v[i] <= n+i){
 		i++;
 	}
 	//v[i] > n now

 	in = i;
 	m = n + i;
 	cout << m;
 	// Debug(i)
 	// Debug(m)
 	For(s,1,30){
 		i = 0;
 		while(v[i] <= s+i){
 			i++;
 		}
 		Debug(s+i)
 	}
 	// while(n + in >= v[i]){
 	// 	i++;
 	// }
 	//For(i,0,15){ mul *= p[i];}//Debug(p[i]) Debug(mul)}
 	//now if you multiply by 53 you will exceed but if you remove a factor of any number >= 5 then that will be enough and it will not overload
 	// mul /= 5;
 	//  Debug(mul)
 	//  mul *= p[15];
 	//  Debug(mul)
 	//  Debug(mul)  
    return 0;
}