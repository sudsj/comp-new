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
    std::vector<int> s;
    s.push_back(0);
    For(i,1,100000) s.push_back(s[i-1] + i*2 - 1);
    tests{
        long long int y;
        long long int a,b;
        // int b;
        cin >> y;
        long long int x = y - 700;if(x < 1) x = 1;
        long long int z = y-1;
        if(y == 1){
            cout << 0<<"\n";
        }else{
            
            a = (long long int) (std::floor(sqrt(x)));Debug(a)
            b = a-1;
            if(b >= 1 && b*b + 700 < y){
                ans += 700*b;
            }
            while(a*a + 1 <= y){
                ans += y - a*a;
            }
        }
        
    }
    return 0;
}