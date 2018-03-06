#include <bits/stdc++.h>
#include <iomanip>

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
long long int triangle[100][100];

void makeTriangle() {
    int i, j;

    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < 55; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

long long int C(int n, int r) {
    return triangle[n][r];
}

double findExp(int n, int x){
    makeTriangle();
    long long int ans = 0,twp=2,d=0;
    double res = 0;
    For(i,1,n+1){
    	if(n-i < x-1) break;
    	ans += twp*C(n-i,x-1);
    	d += C(n-i,x-1);
    	twp *= 2;
    }
    res = ans*1.0;
    res = res/d;
    return res;
        
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x,y;cin >>x >> y;
    cout << findExp(x,y);

 	   	
    return 0;
}