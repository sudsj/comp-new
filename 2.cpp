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
int t,n,a,b,c,sz;
long long int ninput;
void getprimes() {
    vector<bool> prime(101000,true);

    for(int i  =2; i*i < 101000;i++) {
        if(prime[i]) {
            for(int j = 2*i;j < 101000;j+=i)
                prime[j] = false;
        }
    }
    for(int i = 2;i < 101000;i++)
        if(prime[i])
            prm.push_back(i);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    getprimes();

    tests{

        cin >> n >> a >> b >> c;
        long long ans = 0;
        vector<int> factorprime;
        map<int,int> countprime;

        vector<int> fcts;
        set<int> factstill;
        fcts.push_back(1);

        ninput = n;
        int psize = prm.size(),prime;
        For(i,0,psize){
            prime = prm[i];
            if(n%prime == 0) {
                n /= prime;
                factorprime.push_back(prime);
                countprime[prime]++;
                
                while(n%prime == 0) {
                    countprime[prime]++;
                    n /= prime;
                }
            }
        }
        
        int psfacs = factorprime.size(),fctor;
        For(i,0,psfacs){
            fctor = factorprime[i];

             while(countprime[fctor] > 0) {
                sz = fcts.size();
                For(i,0,sz){
                    if(factstill.find(fcts[i]*fctor) == factstill.end()) {
                        factstill.insert(fcts[i]*fctor);
                        fcts.push_back(fcts[i]*fctor);
                        
                    }
                }
                countprime[fctor]--;
             }
        }
        sort(fcts.begin(),fcts.end());
        
        int szf = fcts.size();

        For(i,0,szf){
            For(j,0,szf){
                long long int pp = -1;
                if(ninput%(fcts[i]*fcts[j]) == 0) {
                    pp = ninput/(fcts[i]*fcts[j]);
                    if(fcts[i] <= a && fcts[j] <= b && pp <= c)
                        ans++;
                }
            }        
        }

        cout << ans << "\n";
        

    }

    return 0;
}
