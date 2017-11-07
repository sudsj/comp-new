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
      int n; cin >> n;printf("%d\n",n);
      int a[2*n + 1];
      For(i,1,n+1){
        a[i] = i;
      }
      For(i,n+1,2*n + 1){
        a[i] = i-n;
      }
      For(i,0,n){//i runs from 1 to n
        printf("%d\n",n);
        For(j,1,n+1){
          printf("%d %d %d\n",j,a[(2*i + 2*j -1)%(2*n) + 1],a[(2*i + 2*j)%(2*n) + 1]);
        }
      }
    }
    return 0;
}
