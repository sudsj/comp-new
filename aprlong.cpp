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

////////////////////////////////////

int tree[400000],tree2[400000];

void build_tree(int node, int a, int b) {
    if (a == b) { // We get to a simple element
        tree[node] = hf[a]; // This node stores the only value
    }
    else {
        int leftChild, rightChild, middle;
        leftChild = 2*node;
        rightChild = 2*node+1; // Or leftChild+1
        middle = (a+b) / 2;
        build_tree(leftChild, a, middle); // Recursively build the tree in the left child
        build_tree(rightChild, middle+1, b); // Recursively build the tree in the right child

        tree[node] = max(tree[leftChild], tree[rightChild]); // The Value of the actual node, 
                                                            //is the max of both of the children.
    }
}
int query(int node, int a, int b, int p, int q) {
    if (b < p || a > q) // The actual range is outside this range
        return -100000000; // Return a negative big number. Can you figure out why?
    else if (p >= a && b >= q) // Query inside the range
        return tree[node];
    int l, r, m;
    l = 2*node;
    r = l+1;
    m = (a+b) / 2;
    return max(query(l, a, m, p, q), query(r, m+1, b, p, q)); // Return the max of querying both children.
}

void builds(int node, int left, int right)
{
    if (left == right) tree2[node] = hf[left];                    // leaf node
    else
    {
        builds(2*node, left, (left+right)/2);                    // left subtree
        builds(2*node + 1, (left+right)/2 + 1, right);           // right subtree
        tree2[node] = max(tree2[2*node], tree2[2*node + 1]);       // current node
    }
}
 
int querys(int node, int curr_l, int curr_r, int query_l, int query_r)
{
    if (curr_l > query_r || curr_r < query_l)                   // out of range
        return -100;
    if (curr_l >= query_l && curr_r <= query_r)                 // in range
        return tree2[node];
    else                                                        // min of left and right subtree
        return max( query(2*node, curr_l, (curr_l + curr_r) / 2, query_l, query_r),
                    query(2*node + 1, (curr_l + curr_r) / 2 + 1, curr_r, query_l, query_r));
}
/////////////////////////////////////////////
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

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

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

        build_tree(1,0,n-1);
        builds(1,0,n-1);
        buildmin(0, n-1,1);
        map< long long int, std::vector<long long int> > mp;
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
                Debug(query(1, 0, n-1, lefti, righti))
                Debug(querys(1, 0, n-1, lefti, righti))
                if((findmin(1, 0 ,n-1, lefti, righti) < tgt) || ( query(1, 0, n-1, lefti, righti) > tgt)){
                    ans++;//Debug(tgt)
                }
            }

        }
        // For(i,0,7) Debug(hf[i])
        For(i,0,15){

            Debug(tree[i])
        }
        cout << ans << "\n";
    
    }
 
    return 0;
}


//  MAXN = 100006;
// vi t(4*MAXN),t1(4*MAXN);
// vi a(MAXN,0),b(MAXN, 0);
 
//  void build(ll v, ll tl, ll tr) {
//     if (tl == tr) {
//         t[v] = b[tl];
//     } else {
//         ll mid = (tl + tr) / 2;
//         build( v*2, tl, mid);
//         build( v*2+1, mid+1, tr);
//         t[v] = max(t[v*2],t[v*2+1]);
//     }
// }


 
// void build1(ll v, ll tl, ll tr) {
//     if (tl == tr) {
//         t1[v] = a[tl];
//     } else {
//         ll mid = (tl + tr) / 2;
//         build1(v*2, tl, mid);
//         build1(v*2+1, mid+1, tr);
//         t1[v] = min(t1[v*2],t1[v*2+1]);
//     }
// }
 
// ll big(ll v, ll tl, ll tr, ll l, ll r) {
//     if (l > r) 
//         return -1;
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     ll mid = (tl + tr) / 2;
//     return max(big(v*2, tl, mid, l, min(r, mid))
//            , big(v*2+1, mid+1, tr, max(l, mid+1), r));
// }
// ll small(ll v, ll tl, ll tr, ll l, ll r) {
//     if (l > r) 
//         return 99999999999;
//     if (l == tl && r == tr) {
//         return t1[v];
//     }
//     ll mid = (tl + tr) / 2;
//     return min(small(v*2, tl, mid, l, min(r, mid))
//            , small(v*2+1, mid+1, tr, max(l, mid+1), r));
// }
 
 
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout.precision(20);
//     //freopen("test.txt","r",stdin);
//     ll tt;
//     cin>>tt;
//     while(tt--){
//         clock_t st = clock();
//         ll n;
//         cin>>n;
//         repA(i,0,n-1)cin>>a[i];
//         repA(i,0,n-1)cin>>b[i];
//         mii m;
//         unordered_map<ll,vi> mp;
//         ll f=1;
//         repA(i,0,n-1){
//             a[i]-=b[i];
//             if(a[i]<0){
//                 cout<<-1<<endl;
//                 f=0;
//                 break;
//             }
//         }
//         if(!f)continue;
//         build(1,0,n-1);
//         repA(i,0,n-1){
//             if(a[i]){
//                 m[b[i]]++;
//                 mp[b[i]].pb(i);    
//             }
//         }
//         repA(i,0,n-1){
//             a[i]+=b[i];
//         }
//         build1(1,0,n-1);
//         ll ans=0;
//         for(auto i:m){
//             if(i.se >1){
//                 repA(j,1,i.se-1){
//                     if(big(1,0,n-1,mp[i.fi][j-1],mp[i.fi][j])>i.fi || small(1,0,n-1,mp[i.fi][j-1],mp[i.fi][j])<i.fi)
//                         ans++;
                    
//                 }
//             }
//             ans++;
//         }
//         if(m[0])ans--;
//          cout<<ans<<endl;
//         clock_t end = clock();
//         //cout << (double)(end - st)/CLOCKS_PER_SEC << endl;
 
//     }
 
//     return 0;
// }