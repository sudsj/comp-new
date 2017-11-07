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
    char a,b,f,c,d;
    cin >> a >> b >> f >> c >> d;
    int rh = (a-'0') + 10*(b-'0');
    int m = 10*(c-'0') + (d-'0');
    int ans = 0;
    if(rh <=60){
      if(rh >= m){
        ans = rh - m;
      }else{
        if(rh == 32){
          ans = 60 - m;
        }else{
          rh = (a-'0') + 10*((b+1)-'0');
          ans = rh + (60 - m);}
      }
      if((rh == 60) && (m > 50)){
        ans = ((90 - rh) * 6) + (60 - m) + 1+60;
      }
      if((rh == 61) && (m > 51)){
        ans = ((91 - rh) * 6) + (60 - m) + 2+60;
      }
    }else{
      if( rh == 60 || rh == 70 || rh == 80 || rh == 90){
        ans = ((90 - rh) * 6) + (60 - m) + 1;
      }else{
        ans = ((91 - rh) * 6) + (60 - m) + 2;
      }
    }
    cout << ans;
//    Debug(rh) Debug(m)
    return 0;
}
