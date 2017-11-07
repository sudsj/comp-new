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
        int n;
        cin >> n;
        int a[n];
        int p[21];
        int zero = 0;
        int ex = 0;
        int num[1048577] = {0};
        int one[20] = {0};
        int zero[20] = {0};
        For(i,0,n){
            cin >> a[i];
            if(num[a[i]] != 0) continue;
            if(a[i] == 0) zero[0] = 1;
            ex = 0;
            t = a[i];
            while(t != 0){
                t /= 2;
                ex++;
            }
            For(i,0,ex){
                if( N & (1 << i) ){
                    one[i] = 1;
                }else{
                    zero[i] = 1;
                } 
            }
            
        }
        long long int size = 1;
        For(i,0,21){
            size *= one[i] + zero[i];
        }

    }
    return 0;
}
