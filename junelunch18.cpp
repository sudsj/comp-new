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
std::vector<int> v[101000];
std::vector<int> b(101000);

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    tests{
        int n,m,xx=0;
        cin >> n >> m;
        
        For(i,1,n+1){
            v[i].clear();
            v[i].push_back(0);
            For(j,0,m){
                cin >> xx;
                v[i].push_back(xx);
            }
        }
        int q;cin >> q;int l,r;
        For(i,0,q){
            cin >> l >> r;
            For(j,1,m+1){
                b[j] = v[l][j];
            }
            For(j,l+1,r+1){
                For(k,1,m+1){
                    b[k] = v[j][b[k]];
                }
            }
            long long int ans = 0;
            For(j,1,m+1){
                ans += j*b[j];
            }
            cout << ans << "\n";
        }
    }
    



    return 0;
}