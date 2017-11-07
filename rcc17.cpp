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
int d[20000]= {0};
int num[1000001] = {0};
int main()
{
    tests{
        memset(d,0,sizeof(d));
        memset(num,1,sizeof(num));
        int n; cin >> n;
        int a[n];
        For(i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        int in = 0;
        For(i,0,n){
            For(j,i+1,n){
                d[in] = a[j] - a[i];
                in++;
            }
        }
        std::vector<int> v;
        v.push_back(1);
        int m = 1,done = 1,flag = 0;
        while(m <= 1000000 && done <= n){
            For(i,0,in){
                num[m+d[i]] = 0;
            }
            flag = m;
            For(i,m+1,1000001){
                if(num[i] == 1){
                    m = i;
                    break;
                }
            }
            if(flag == m){break;}else{
                v.push_back(m);
                done ++;
            }
        }
        if(done < n){ cout << "NO";}else{
            cout << "YES\n";
            For(i,0,n){
                cout << v[i] << " ";
            }

        }
        cout << "\n";
    }

    return 0;
}
