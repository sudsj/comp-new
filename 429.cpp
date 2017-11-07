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
    int n; cin >> n;
    int a[n],b[n];//int in[n];
    std::vector<int> x(n);
    std::vector<int> in(n);
    For(i,0,n){
        cin >> a[i];
        in[i] = i;
    }
    sort(a,a+n);
    For(i,0,n){
        cin >> b[i];
    }
    //std::vector<int> y;

   // std::vector<int> y(x.size());
    //std::size_t m(0);
    //std::generate(std::begin(y), std::end(y), [&]{ return m++; });

    std::sort(  std::begin(in), 
                std::end(in),
                [&](int i1, int i2) { return b[i1] < b[i2]; } );
    // for (auto v : in)
    //     std::cout << v << ' ';
    int c[n];
    //     std::sort(std::begin(in), std::end(in),
    //           [] (const auto& lhs, const auto& rhs) {
    //     return a[lhs] < a[rhs];
    // });
    // DebugArr(b,n)
    // DebugArr(in,n)
    For(i,0,n){
        c[in[i]] = a[i];
    }
    DebugArr(c,n)

    return 0;
}
