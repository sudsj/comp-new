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
    int n; cin >> n; int a[n+1];
    For(i,1,n+1){
      cin >> a[i];
    }
    int start[100] = {0}; int end[100] = {0};
    int pos[101] = {0};//stores positions of 0's where left and right have ones
    int alen[n+1] = {0}; int count = 0; int j = 0,k=0;
    For(i,1,n+1){
      if(a[i] == 1){
        if(alen[i-2] != 0) pos[i-1] = 1;//that 0 is surrounded by two series
        start[j] = i;j++;
        alen[i] = 1; i++;
        while(a[i] == 1 && i<n+1){
          alen[i] = alen[i-1] + 1;
          i++;
        } count++;//one more ones ka series
        end[k] = i-1;//ith positon is 0
        k++;
        if(pos[start[j-1] - 1] == 1 ) pos[start[j-1] - 1] == alen[start[j-1] - 2] + alen[i-1];
      }
      //a[i] is 0 now
    }
    int max1 = max(alen,alen+n+1); int max2 = max(pos,pos+101);
    if(count > 1){
      max1 += 1;
      if(count == 2){
        if(max1 > max2){
          cout << max1;
        }else cout << max2;
      }else{
        max2 += 1;
        if(max1 > max2){
          cout << max1;
        }else cout << max2;
      }
    }else cout << max1;
    return 0;
}
