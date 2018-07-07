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
int vx[4];int vy[4];
    int sx[4];int sy[4];
int cx,cy;
int cp;
int chk(int x,int y){
	int flag =1;
	int p1 = x + y - sx[0] - sy[1];
	int cp1 = cx + cy - sx[0] - sy[1];

	if(p1*cp1 < 0) flag = 0;

	p1 = x + y - sx[3] - sy[1];
	cp1 = cx + cy - sx[3] - sy[1];

	if(p1*cp1 < 0) flag = 0;
	p1 = x - y - sx[1] + sy[0];
	cp1 = cx - cy - sx[1] + sy[0];
	if(p1*cp1 < 0) flag = 0;
	p1 = x - y - sx[1] + sy[3];
	cp1 = cx - cy - sx[1] + sy[3];
	if(p1*cp1 < 0) flag = 0;
	return flag;
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    For(i,0,4){
    	cin >>vx[i] >> vy[i];
    }
    For(i,0,4){
    	cin >> sx[i] >> sy[i];
    }
    sort(vx,vx+4);sort(vy,vy+4);
    sort(sx,sx+4);sort(sy,sy+4);

    cx = sx[1];cy = sy[1];

    int flag = 0;
    For(i,vx[0],vx[3]+1){
    	For(j,vy[0],vy[3]+1){
    		flag = max(flag,chk(i,j));
    	}
    }


    if(flag){
    	cout <<"YES";
    }else cout << "NO";
 	//   	
    return 0;
}