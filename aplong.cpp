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
std::vector<long long int> mint(400000),maxt(400000);
std::vector<long long int> hi(400000),hf(400000);

void buildmin(long long int left, long long int right, long long int node) {
    if(left == right){
        mint[node] = hi[left];
    } else {
        long long int mid = left + right;
        mid /= 2;
        buildmin(left,mid,2*node);
        buildmin(mid+1,right,2*node+1);
        mint[node] = min( mint[2*node], mint[2*node+1] );
    }
}

void buildmax(long long int left, long long int right, long long int node) {
    if(left == right){
        maxt[node] = hf[left];
    } else {
        long long int mid = left + right;
        mid /= 2;
        buildmax(left,mid,2*node);
        buildmax(mid+1,right,2*node+1);
        maxt[node] = min( maxt[2*node] , maxt[2*node+1] );
    }
}

long long int findmax(long long int node, long long int left, long long int right, long long int l, long long int r) {
    if(l > r) return -100;
    if (r == right) {
        if(l == left) return maxt[node];
    }
    long long int mid = (left + right);
    mid = mid/2;
    int lefl = min(mid, r);
    int refl = max(l,mid+1);
    return max(findmax(node*2, left, mid, l, lefl), findmax(node*2+1, mid+1, right, refl, r));
}
long long int findmin(long long int node, long long int left, long long int right, long long int l, long long int r) {
    if(l > r) return 100000000000;
    if(r == right) {
        if(l == left) return mint[node];
    }
    long long int mid = (left + right) / 2;
    int lefl = min(mid, r);
    int refl = max(l,mid+1);
    return min(findmin(node*2, left, mid, l, lefl), findmin(node*2+1, mid+1, right, refl, r));
}


int main() {

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // Debug(4)
    tests{
        int n;cin >> n;
        
        For(i,0,n){
            cin >> hi[i];
        }
        For(i,0,n){
            cin >> hf[i];

        }
        int flag =0;
        For(i,0,n){
            if(hi[i] < hf[i]){
                cout << "-1\n";
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        buildmax(0, n-1,1);
        buildmin(0, n-1,1);
        unordered_map< long long int, std::vector<long long int> > mp;
        set<long long int> finalhts; 

        For(i,0,n){
            if(hf[i] == hi[i]) continue;
            mp[hf[i]].push_back(i);
            finalhts.insert(hf[i]);
        }
        long long int ans =0;
        std::set<long long int>::iterator it;
        for (it = finalhts.begin(); it != finalhts.end(); ++it)
        {
            long long int tgt = *it;
            ans++;
            Debug(tgt)
            For(i,0,mp[tgt].size()-1){
                //if min in hi is less than tgt 
                //if max in hf is greater than tgt
                //then ans++
                int lefti = mp[tgt][i];
                int righti = mp[tgt][i+1];
                Debug(lefti)
                Debug(righti)
                Debug(findmin(1, 0 ,n-1, lefti, righti))
                Debug(findmax(1, 0, n-1, lefti, righti))
                if((findmin(1, 0 ,n-1, lefti, righti) < tgt) || ( findmax(1, 0, n-1, lefti, righti) > tgt)){
                    ans++;Debug(tgt)
                }
            }

        }
        cout << ans << "\n";
    
    }
 
    return 0;
}

