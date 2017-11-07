#include <bits/stdc++.h>
using namespace std;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      For(i, m, n)      for(int i = m; i < (n); ++i)
#define      fill(a,k)         For(i,0,sizeof(a)/sizeof(a[0])) a[i] = k;
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
#define      in(n)             scanf("%d",&n)
#define      out(n)            printf("%d\n",n)
#define      llin(n)           scanf("%lld",&n)
#define      llout(n)          printf("%lld\n",n)
#define      Debug(x)          cout<<"> "<<#x<<" : "<<x<<endl
#define      DebugArr(a,n)     For(i,0,n) cout<<i<<" : "<<a[i]<<endl
 
typedef long long ll;
ll mod = 1000000007;
 
int main() {
    set<string> corrected;
    int n;
    
    cin >> n;
    For(i,0,n) {
        string s,g;
        cin >> s;
        For(i,0,s.length()) {
            if(i < s.length() - 1) {
                if(s[i] == 'o' && s[i+1] == 'o') {g.pb('u');i++;continue;}
            }
            
            if(s[i] == 'k') {
                For(j,i,s.length()) {
                    if(s[j] == 'k' && j == s.length()-1) {g.pb('k');break;}
                    if(s[j] == 'k') continue;
                    else if(s[j] == 'h') {g.pb('h'); i = j;break;}
                    else {g.pb('k');break;}
                }
                
            }
            else g.pb(s[i]);
        }
        For(i,0,g.length()-1) {
            if(g[i] == 'o' && g[i+1] == 'u') swap(g[i],g[i+1]);
        }
        
        corrected.insert(g);
    }
    // each(it,corrected) cout<<(*it) << endl;
    cout << corrected.size();
    return 0;
}