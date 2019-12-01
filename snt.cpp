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
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);
    char a[16][16];
    char c;
    For(k,0,25){
        For(i,0,16){
            int n = 0;
            int pw = 1;
            For(j,0,8){
                cin >> c;
                if(c == '1'){
                    n += pw;
                }
                pw *= 2;
                // if(k){
                //     if(c != a[i][j]){
                //         cout << "X ";
                //     }else cout << "O ";
                // }else{
                //     a[i][j] = c;
                //      cout << a[i][j] << " ";
                // }
                // a[i][j] = c;
                //
            }
            c = '0' + n - 48;
            cout << (char)n << " ";
            n = 0;
            pw = 1;
            For(j,0,8){
                cin >> c;
                if(c == '1'){
                    n += pw;
                }
                 pw *= 2;
                // if(k){
                //     if(c != a[i][j]){
                //         cout << "X ";
                //     }else cout << "O ";
                // }else{
                //     a[i][j] = c;
                //      cout << a[i][j] << " ";
                // }
                // a[i][j] = c;
                //
            }
            c = '0' + n - 48;
            cout << (char)n << " ";
            n = 0;pw = 1;
            
        }
        cout << "\n\n";
    }
    
 	//	   	
    return 0;
}