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
    tests{
      int n; int m;
      scanf("%d",&n); scanf("%d",&m);
      int ans = 0;
      if(n == 1){
        printf("%d\n",m);
      }else if(n == 2){
        ans = m/6;
        int var = m - 6*ans;
        ans *= 4;
        if(var == 1){
          ans += 2;
        }else if(var >= 2){
          ans += 4;
        }
        printf("%d\n",ans);
      }else{
        if(m>=2){
          ans = m/6;
          int var = m - 6*ans;
          ans += 1;
          ans *= 4;
          if(var == 0){
            ans -= 4;//for 6 ke multiples
          }else if(var == 1){
            ans -= 2;//subtract 4 and add 3
          }
          printf("%d\n",ans);
        }else{
          //m is 1
          printf("3\n");
        }
      }
    }
    return 0;
}
