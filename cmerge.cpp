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
int n; 
int getind(int i, int p){
    if(i <= n-p){
        return i + p;
    }else{
        return 2*(i-(n-p)) - 1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    tests{
        cin >> n;
        long long int d = 0;
        std::vector<int> a(n+1,0);
        long long int f;
        For(i,0,n-1) cin >> a[i+2];
        cin >> f;
        int curattack = 0;int total = n;int round = 0;
        int flag = 1;
        For(p,1,n+1){
            curattack = n-1;
            round = 1;d = 0;
            Debug(p)
            if(p < n){
                swap(a[p-1],a[p]);
            }
            For(i,1,n+1) cout << a[i]<< " "; cout << "\n";
            if(a[getind(1,p)] > f){
                continue;
            }else flag = 0;
            Debug(p)
            while(curattack > 1){
                Debug(round)
                Debug(curattack)
                Debug(getind(curattack,p))
                
                Debug(a[getind(curattack,p)])
                if(total%2 == 0){
                    //even means he gets hit
                    Debug(getind(curattack,p))
                    Debug(a[getind(curattack,p)])
                    d += a[getind(curattack,p)];
                }else{
                    //cur attacker dies
                    int x = 1 << round;
                    Debug(x)
                    curattack -= (x) - 1;
                }
                Debug(total)
                total -= (total-1)/2;
                round += 1;
                if(round > 100) break;
            }
            Debug(d)
        }
    }
    ///////
    return 0;
}