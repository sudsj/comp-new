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
int d[2000] = {0};
int a[2000];
int pos[2000][2];
int wrong[2000];
int tw;
void dasgn(int i){
    int x = a[i];
    int othr;
    if(pos[x][0] == i){
        othr = pos[x][1];
    }else othr = pos[x][0];
    if(abs(othr-i) == 1){
        d[othr] = 0;
        d[i] = 0;
        if(wrong[i] == 1) tw--;
        wrong[i] = 0;
    }else{
        if(wrong[i] == 0) tw++;
        wrong[i] = 1;
        if(othr > i){
            d[othr] = -1;
            d[i] = 1;
        }else{
            //othr ...........i
            d[othr] = 1;
            d[i] = -1;
        }
    }
    // Debug(x)
    // Debug(d[i])
    // Debug(d[othr])
}
void pupd(int x, int opos, int npos){
    if(pos[x][0] == opos){
        pos[x][0] = npos;
    }else pos[x][1] = npos;
}
int main()
{
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;cin >> n;
    tw = n;
    // int a[2*n];
    For(i,0,2*n) cin >> a[i];
    // int pos[n][2];
    For(i,0,n+1){
        pos[i][0] = -1;
        pos[i][1] = -1;
    }
    
    For(i,0,2*n){
        if(pos[a[i]][0] == -1){
            pos[a[i]][0] = i;
        }else pos[a[i]][1] = i;
    }

    For(i,0,2*n){
        dasgn(i);
    }
    // Debug(d[0])
    // Debug(d[1])
    int chk = 0;int y,z;
    long long int ans = 0;
    while(chk < 10000 && tw != 0){
        chk++;
        For(i,0,2*n-1){
            y = a[i];
            if(d[i] == 0) continue;
            if(d[i] == 1 && (d[i+1] == -1 || d[i+1] == 0)){
                z = a[i+1];
                //  Debug(y) Debug(z)
                // Debug(d[i]) Debug(d[i+1])
                pupd(y,i,i+1);
                pupd(z,i+1,i);
                swap(a[i],a[i+1]);
                ans++;
                dasgn(i);
                dasgn(i+1);
            

        }
        for(int i = 2*n-1;i>=1;i--){
            y = a[i];
            if(d[i] == 0) continue;
            if(d[i] == -1 && (d[i-1] == 1 || d[i-1] == 0)){
                
                z = a[i-1];
                //   Debug(y) Debug(z)
                // Debug(d[i]) Debug(d[i-1])
                pupd(y,i,i-1);
                pupd(z,i-1,i);
                swap(a[i],a[i-1]);
                ans++;
                dasgn(i);
                dasgn(i-1);
                // Debug(y) Debug(z)
                
        }
        
    }
    cout << ans;
    return 0;
}
