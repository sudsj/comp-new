#include <bits/stdc++.h>
#include <time.h>
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
vector<int> prm; 

void findprimes() {
    vector<bool> prime(100000,true);
    for(int i  =2; i*i < 100000;i++) {
        if(prime[i]) {
            for(int j = 2*i;j < 100000;j+=i)
                prime[j] = false;
        }
    }
    for(int i = 2;i < 100000;i++)
        if(prime[i])
            prm.push_back(i);
}

int main() {
    int t,n,a,b,c,sz;
    long long int actualn;
    cin >> t;

    findprimes();

    tests{
        cin >> n >> a >> b >> c;
        long long ans = 0;
        vector<int> facsofprime;
        map<int,int> countsp;
        actualn = n;
        for(auto prime: prm) {
            if(n%prime == 0) {
                facsofprime.push_back(prime);
                countsp[prime]++;
                n /= prime;
                while(n%prime == 0) {
                    countsp[prime]++;
                    n /= prime;
                }
            }
        }
        vector<int> fcts;
        set<int> facutil;
        fcts.push_back(1);

        for(auto fac: facsofprime) {
             while(countsp[fac] > 0) {
                sz = fcts.size();
                for(int i = 0;i < sz;i++) {
                    if(facutil.find(fcts[i]*fac) == facutil.end()) {
                        fcts.push_back(fcts[i]*fac);
                        facutil.insert(fcts[i]*fac);
                    }
                }
                countsp[fac]--;
             }
        }
        sort(fcts.begin(),fcts.end());
        
        for(int i = 0; i < fcts.size();i++) {
            for(int j = 0;j < fcts.size();j++) {
                long long q[] = {fcts[i],fcts[j], -1};
                if(actualn%(q[0]*q[1]) == 0) {
                    q[2] = actualn/(q[0]*q[1]);
                    if(q[0] <= a && q[1] <= b && q[2] <= c)
                        ans++;
                }
            }        
        }

        cout << ans << endl;
        

    }

    return 0;
}
