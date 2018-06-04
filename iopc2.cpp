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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test,n,a,b; cin >> test;
    while(test--) {
        cin >> n >> a >> b;
        if(a >= 20 || b >= 20) {
            cout << 0 << endl;
        }
        else {
            int bits[20];
            for(int i = 0;i < 20;i++) {
                bits[i] = n%2;
                n /= 2;

                

            }
            reverse(bits,bits+20);
            long long int ans = 0;                                      
            a = 19-a; b = 19-b;
            // DebugArr(bits,20)
            // int mx = max(())
            For(i,0,20){
                if(bits[i] == 0 && i == a) break;
                if(bits[i] == 0 && i == b) break;
                // Debug(i)
                if(bits[i] == 1){
                    if(i == a) continue;
                    if(i == b) continue;
                    int right = 19-i;
                    if(i < a) right--;
                    if(i < b) right --;
                    if(a == b) right++;
                    ans += (int)pow(2,right);
                }
            }
            cout << ans<<"\n";
        }
    }
    return 0;
}