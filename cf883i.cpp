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
    int n;cin >> n;
    string g;
    cin >> g;
    int m;cin >> m;int t = m;
    std::vector<string> v(m),v1;
    For(i,0,m) cin >> v[i];
    int flag[m] = {0};
    For(i,0,n){
        if(g[i] != '*'){
            For(j,0,m){
                if(v[j][i] != g[i]){
                    flag[j] = 1;    
                    t--;
                }
            }
        }
    }
    For(i,0,m){
        if(flag[i] == 0) v1.push_back(v[i]);
    }
    v.resize(0);
    //Debug(t)
    int fl[t]={0};
    For(i,0,n){
        if(g[i] == '*'){
            For(k,0,t){
                For(j,0,n){
                    if(g[j] != '*'){
                        if(v[k][i] == g[j]){
                            
                            fl[k] = 1;//tpp--;
                        }
                    }
                }
            }
        }
    }
    For(i,0,t){
        if(fl[i] == 0) v.push_back(v1[i]);
    }
   // Debug(v.size())
    t = v.size();
   // Debug(t)
    int c[t][26];
    For(i,0,t){
        For(j,0,26) c[i][j] = 0;
    }
    //For(i,0,26) Debug(c[0][i])
    int ans = 0;
    //Debug(t)
    For(i,0,n){
        if(g[i] == '*'){
            For(j,0,t){
                c[j][v[j][i]-'a'] = 1;
            }
        }
    }
     //For(i,0,26) Debug(c[0][i])
     int ct = 0;
    For(i,0,26){
        ct = 0;
        For(j,0,t) ct += c[j][i];
        if(ct == t) ans++;
    }
     cout << ans;
    return 0;
}

