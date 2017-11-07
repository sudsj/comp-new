6.
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
long long int binarySearch(long long int sortedArray[], long long int toFind, long long int len)
{
    // Returns index of toFind in sortedArray, or -1 if not found
    long long int l = 0;
    long long int h = len - 1;
    long long int mid;

    while(l < h){
      mid = l + (h-l+1)/2;
      if(sortedArray[mid] > toFind){
        h = mid-1;
      }else{
        l = mid;
      }
    }
    if(sortedArray[l] > toFind) return -1;
    return l;
}

int main()
{
    tests{
      lli p,q,r;
      cin>>p >> q >> r;
      lli pa[p],qa[q],ra[r];
      lli sump[p],sumq[q],sumr[r];
      For(i,0,p){
        scanf("%lld",&pa[i]);
      }
      For(i,0,q){
        scanf("%lld",&qa[i]);
      }
      For(i,0,r){
        scanf("%lld",&ra[i]);
      }
      sort(pa,pa+p);
      //sort(qa,qa+q);
      sort(ra,ra+r);
      sump[0] = pa[0];
      For(i,1,p){
        sump[i] = pa[i] + sump[i-1];
      }
      sumr[0] = ra[0];
      For(i,1,r){
        sumr[i] = ra[i] + sumr[i-1];
      }
      lli  sum = 0,lefti,righti; lli left = 0; lli right = 0;
      For(i,0,q){
        //for p
        //Debug(binarySearch(pa,qa[i],p))
         lefti = binarySearch(pa,qa[i],p) ;if(lefti < 0) continue;
        // Debug(lefti)
         left = sump[lefti] + (lefti+1)*qa[i];
         righti = binarySearch(ra,qa[i],r) ;if(righti < 0) continue;
         right = sumr[righti] + (righti+1)*qa[i];
         sum += (left * right)%mod;
         sum = sum%mod;
         /*cout<<"added to sum : "<<sumr[righti]<<" \n";
         cout<<"added to sum : "<<righti+1<<" \n";
         cout<<"added to sum : "<<ra[i]<<" \n";*/
      }
      cout << sum << "\n";
    }
    return 0;
}
