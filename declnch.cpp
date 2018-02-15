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


/////////////////////////////////////
int t1,t2,n,b1,b2,s1,s2;

long long int dpsum(int cs,int fs,int ci,int fi,int lim){
	if(ci > fi ) return 0;
	if(ci == fi){
		For(i,0,lim+1){
			if(cs + i == fs){
				return 1;
			}
		}
		return 0;
	}
	if(cs > fs) return 0;
	if(cs == fs) return 1;
	//cs < fs
	long long int ans = 0;
	For(i,0,lim+1){
		ans += dpsum(cs+i,fs,ci+1,fi,lim);

	}
	return ans;
}

long long int wy(int c1, int c2){
	//all atleast one
	if(c1*s1 + c2*s2 < n) return 0;
	long long int ans = 0;
	// int l1,l2;
	int left = n - c1 - c2;
	int one = t1 - c1;//sweets left in 1
	int two = t2 - c2;
	if(left < 0) return 0;
	if(left == 0) return 1;
	int p1=0,p2=0;//extra sweets used of box 1 and 2
	For(i,0,left+1){
		p1 = i;p2 = left - p1;
		if(p1 > one || p2 > two) continue;
		//use c1 numbers to add upto p1
		//c2 .. p2
		ans += (dpsum(0,p1,1,c1,s1-1)*dpsum(0,p2,1,c2,s2-1))%mod;

	}
	return ans%mod;
}
int call = 0;
long long int combs(int c1, int c2, int next){
	//ways for c1 and c2
	
	//check if valid arrangement
	// cout << "Comb with c1 = " << c1 << " and c2 = " << c2 << "\n";
	if(c1 > b1 || c2 > b2) return 0;
	if(c1 > t1 || c2 > t2) return 0;
	// call++;
	// call = max(c2+c1,call);
	// if(c1 == 10 ) call += 10;
	// cout << "Comb with c1 = " << c1 << " and c2 = " << c2 << "\n";
	//checked
	long long int ans = 0;
	ans = wy(c1,c2)%mod;//Debug(ans)
	if(next == 1){
		c1++;next = 0;
	}else{ c2++; next = 1;}
	ans += combs(c1,c2,next)%mod;

	return ans%mod;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

 		

 	tests{
 		
 		cin >> t1 >> t2 >> n >>b1 >> b2 >> s1 >> s2;
 		// For(p1,0,3) Debug(dpsum(0,p1,1,1,2))
 		//make all possible arrangements
 		long long int ans = combs(1,1,0) + combs(1,1,1);
 		if(s1 >= n && t1 >= n && b1 >= 1) ans++;
 		if(s2 >= n && t2 >= n && b2 >= 1) ans++;
 		cout << ans%mod << "\n";

 		// Debug(call)
 	}    
    return 0;
}