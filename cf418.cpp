#include <bits/stdc++.h>
using namespace std;
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
      long long int  p,q,r;
      cin>>p >> q >> r;
      set<long long int > ps,qs,rs;
      long long int  num;
      For(i,0,p){
        cin >> num;
        ps.insert(num);
      }
      For(i,0,q){
        cin >> num;
        qs.insert(num);
      }
      For(i,0,r){
        cin >> num;
        rs.insert(num);
      }
      set<long long int >::iterator it,at,bt;long long int  psum=0;long long int  qsum = 0;long long int  sum = 0,left=0,right=0;
      for (it = qs.begin(); it != qs.end(); ++it)
      {
          long long int  f = *it; // Note the "*" here
          if(f < *ps.begin() || f < *rs.begin()) continue;
          set<long long int >::iterator pt = ps.lower_bound(f);
          set<long long int >::iterator rt = rs.lower_bound(f);
          left = *ps.begin() + f; right = *rs.begin() + f;
          for (at = pt; at != ps.begin(); --at)
          {
              left += *at + f;

          }
          for (bt = rt; bt != rs.begin(); --bt)
          {
              right += *bt + f;
          }
          sum += left*right;
          sum = sum%mod;
      }
      cout << sum << "\n";
    }
    return 0;
}
