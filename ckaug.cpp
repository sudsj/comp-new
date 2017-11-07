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
int binarySearch(int sortedArray[], int toFind, int len)
{
    // Returns index of toFind in sortedArray, or -1 if not found
    int low = 0;
    int high = len - 1;
    int mid;

    int l = sortedArray[low];
    int h = sortedArray[high];

    while (l <= toFind && h >= toFind) {
        mid = (low + high)/2;

        int m = sortedArray[mid];

        if (m < toFind) {
            l = sortedArray[low = mid + 1];
        } else if (m > toFind) {
            h = sortedArray[high = mid - 1];
        } else {
            return mid;
        }
    }

    if (sortedArray[low] == toFind)
        return low;
    else
        return -1; // Not found
}
int n,r,c;
long long int sum = 0;
int a[1000][1000];
long long int dps(int sx,int sy,int pos,int t[][2],int st){
    if(sx >= r ) return -1;
    if(sy >= c) return -1;
    if(sx < 0 ) return -1;
    if(sy < 0) return -1;
    long long int tsum=0;
    if(st == 0){
    tsum += a[sx][sy];}
    if(pos == n) return tsum;
    long long int tr1 = dps(sx + t[pos][0],sy + t[pos][1],pos+1,int t[][2],0);
    long long int tr2 = dps(sx + t[pos][0],sy + t[pos][1],pos+1,int t[][2],0);
    long long int tr3 = dps(sx + t[pos][0],sy - t[pos][1],pos+1,int t[][2],0);
    long long int tr4 = dps(sx - t[pos][0],sy - t[pos][1],pos+1,int t[][2],0);
    long long int tr5 = dps(sx,sy,pos+1,int t[][2],1);
    if(tr1 < tr2) tr1 = tr2;if(tr1 < tr3) tr1 = tr3;if(tr1 < tr4) tr1 = tr4;if(tr1 < tr5) tr1 = tr5;
    return tsum + tr1;
}

int main()
{
    tests{
        sum = 0;
         cin >> r >> c; 
        cin >> n;
        int sx,sy; cin >> sx,sy;
        int t[n][2];
        For(i,0,n){
            cin >> t[i][0];
        }
        For(i,0,n){
            cin >> t[i][1];
        }

        For(i,0,r){
            For(j,0,c){
                cin >> a[i][j];
            }
        }
        long long int ans = dps(sx,sy,0,t,0);
        cout << ans << "\n";
    }

    return 0;
}
