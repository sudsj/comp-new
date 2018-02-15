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
int twod(int x,int y, int z, int a, int b){
	int ax=0,ay=0,az=0,bxy=0,byz=0,bzx=0,cxyz=0;
	std::vector<int> v;
	v.push_back(x);v.push_back(y);v.push_back(z);
	sort(v.begin(), v.end());
	//x-0y-1z-2
	if(v[2] >= v[1]+v[0]){
		bzx = v[0];
		byz = v[1];
		az = v[2] - v[0] - v[1];
		return b*(bzx + byz) + a*az;
	}else{
		int dif = v[2] - v[1];
		//dif < v[0]
		v[0] -= dif;
		bzx += dif;
		v[2] -= dif;
		//now v2 and v1 equal
		int hf = v[0]/2;
		v[2] -= hf;
		v[1] -= hf;
		bxy += hf;
		bzx += hf;
		ax += v[0] - 2*hf;
		//v2 and v1 are equally left
		byz += v[2];
		return b*(bzx + bxy + byz) + a*ax;
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
 	tests{
 		int x,y,z,a,b,c;
 		cin >> x >>	y >> z >> a >> b >> c;
 		int ax=0,ay=0,az=0,bxy=0,byz=0,bzx=0,cxyz=0;
 		int ans1 = a*(x+y+z);
 		//2d + 1d
 		int ans2 = twod(x,y,z,a,b);
 		//3d include
 		int min2 = min(x,y);
 				int min1 = min(z,min1);
 		int ans3 = c*(min1) + twod(x-min1,y-min1,z-min1,a,b);
 		int ans11 = min(ans1,ans2);
 		int ans = min(ans11,ans3);
 		cout << ans << "\n";
 	}    
    return 0;
}