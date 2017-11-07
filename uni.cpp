#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
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
int p[2501]; set<int> ps[2501];

int binarySearch(int toFind, int len)
{
    // Returns index of toFind in sortedArray, or -1 if not found
    int low = 0;
    int high = len - 1;
    int mid;

    int l = p[low];
    int h = p[high];

    while (l <= toFind && h > toFind) {
        mid = (low + high)/2;

        int m = p[mid];

        if (m <= toFind) {
            l = p[low = mid + 1];
        } else if (m > toFind) {
          //if bigger then ok as we want just bigger
            h = p[high = mid];
        }
    }
    if(h <= toFind)
        return len;
    else if (p[low] >= toFind)
        return low;
    else
        return len; // whole array is smaller
}

int main()
{
    tests{
      int n,k; cin >> n >> k;
      lli ans = 0; int num;
      For(i,0,n){
        scanf("%d",&p[i]);
        ps[i].clear();
        for(int j = 0;j < p[i];j++) {
            scanf("%d",&num);
            ps[i].insert(num);
        }
      }//all taken in
      sort(p,p+n);
      For(i,0,n){
        //for each of n sets
        int begin;
        if(p[i] < k/2){
        begin = binarySearch(k - p[i] - 1,n);
        //Debug(begin)
        if(begin <= i) begin = i+1;}else begin = i+1;
        For(j,begin,n){
          if((p[i]+p[j]) < k)continue;
          For(m,1,k+1){
              if((ps[i].find(m) !=ps[i].end())||(ps[j].find(m) !=ps[j].end()))
                  continue;
              else {ans--;break;}
          }
          ans++;//Debug(ans)
        }
      }
      cout << ans << "\n";
    }
    return 0;
}
