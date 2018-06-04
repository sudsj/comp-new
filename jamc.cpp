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
int init[3][3];

int chkinit(){
	For(i,0,3){
		For(j,0,3){
			if(init[i][j] == 0) return 1;
		}
	}
	return 0;
}
int main()
{
    // #ifndef ONLINE_JUDGE
 	  //   freopen("input.txt", "r", stdin);
 	  //   freopen("output.txt", "w", stdout);
    // #endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);


    tests{
    	int a,x,y;
    	cin >> a;
    	int ca = 0;
    	int flag = 0;
    	
    	For(i,0,3) For(j,0,3) init[i][j] = 0;
    	while(chkinit()){
    		cout << "2 2"<<endl;
    		cin >> x >> y;
    		//error checking
    		if(x == -1 && y == -1){
    			flag = 1;break;
    		}else if(x == 0 && y == 0){
    			//success
    			flag = 1;break;
    		}
    		init[x-1][y-1] = 1;

    	}
    	if(flag) continue;
    	//form rectangle
    	int py = 3;
    	int ch[4] = {0};
    	while(x != 0 && y != 0){
    		cout << "2 " << py<<endl;
    		cin >> x >> y;
    		//error checking
    		if(x == -1 && y == -1){
    			flag = 1;break;
    		}else if(x == 0 && y == 0){
    			//success
    			flag = 1;break;
    		}
    		if(y == py+1){
    			ch[x] = 1;
    		}
    		if(ch[1] + ch[2] + ch[3] == 3){
    			py++;
    			ch[1] = 0;
    			ch[2] = 0;
    			ch[3] = 0;
    		}
    	}
    	if(flag) continue;
    }





 	   	
    return 0;
}