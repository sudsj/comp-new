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
long long int gcd(long long int a, long long int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}
 

long long int lcm(int arr[], int n)
{
    
    long long int ans = arr[0];
 
    long long int g;
    for (int i=1; i<n; i++){
        g = gcd(arr[i], ans);
        ans *= arr[i];
        
        if(ans >= mod) ans = ans%mod;
        ans = ans/g;
        
    }
 
    return ans;
}

int main()
{
    int n,q;cin >> n >> q;long long int a[n+1];
    For(i,0,n) cin >> a[i+1];
    long long int b,c,t,d;int l,r;long long int cry=0;
    int E[n+1] = {0};
    int O[n+1]={0};
    For(i,1,n+1){
        if(a[i]%2 == 0){
            E[i] = E[i-1] + a[i];           
        }else O[i] = O[i-1] + a[i];
    }
    int ue[n+2] = {0};
    int uo[n+2] = {0};int z = 1;
    For(i,0,q){
        cin >> t;
        if(t == 1){
            cin >> b; cin >> c;z=0;
            //a[b] += c;
            if(a[b]%2 == 0){
               a[b] += c;
               if(a[b]%2 == 0){
                //still even
                ue[b] += c;
                ue[n+1] -= c;
               }else{
                //becomes odd
                ue[b] -= a[b]-c;
                ue[n+1] += a[b]-c;
                uo[b] += a[b];
                uo[n+1] -= a[b];
               }
            }else{
                a[b] += c;
               if(a[b]%2 == 1){
                //still o
                uo[b] += c;
                uo[n+1] -= c;
               }else{
                //becomes e
                ue[b] += a[b];
                ue[n+1] -= a[b];
                uo[b] -= a[b]-c;
                uo[n+1] += a[b]-c;
               }
            }
        }else{
            cin >> d;cin >> l >> r;
            if(z == 0){
                //update
                For(i,1,n+1){
                    cry = ue[i];
                    ue[i] = 0;
                    E[i] += cry;
                }
                For(i,1,n+1){
                    cry = uo[i];
                    uo[i] = 0;
                    O[i] += cry;
                }
            }
            z = 1;
            if(d == 0){
                //even
                cout << E[r] - E[l-1]<<"\n";
            }else cout << O[r] - O[l-1]<<"\n";
        }
    }
    return 0;
}
