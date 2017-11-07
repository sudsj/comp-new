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
        string s;
        cin >> s;
        int ans = 0,k,flag,nxt;
        For(j,0,26){
            For(i,0,s.length()-1){
                if(s[i] == 'a' + j){
                    k = i+1;flag = 1;
                    nxt = s[k+1];
                    while(s[k] == s[i] && k<s.length()) k++;
                    if(k == i+1){

                        //this is singelton
                        while(s[k] != s[i] && k < s.length()){
                            k++;
                            if(s[k] != nxt){ flag = 0; break;}
                        }
                        if(k == s.length()) flag = 0;
                        if(flag == 0){
                            //leave
                            i = k;

                        }else{
                            //s[k] is same
                            ans++;
                            i = k-1;//cont from new s[k]
                        }
                    }else{
                        ans += 2*(k-i)-3;
                        i = k;
                        i--;//loop will increment
                        // if(k < s.length()){
                        //     //can continue 
                        // }
                    }
                    
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}