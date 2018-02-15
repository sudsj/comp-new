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
std::vector<int> a[100001],v(100001);//visited array
vector<int> path;
std::vector<int> p(100001);long long int e = 0;
void dfs(int n){//Debug(n)
  if(v[n] == 0){
    v[n] = 1;
    // cout << n << "\n";e += 1;
    path.push_back(n);
    if(a[n].size() > 1){
      For(i,0,a[n].size()){
        if(v[a[n][i]] == 0){
          dfs(a[n][i]);
          path.push_back(n);
        }
      }
      // cout << n << "\n";e += 1;

    }
  }
}
void sdfs(int n){
  // if(v[n] == 0){
    v[n] = 1;
    v[p[n]] = 1;
    // cout << n << "\n";e += 1;
    path.push_back(n);
    if(a[n].size() > 2){
      For(i,0,a[n].size()){
        if(v[a[n][i]] == 0){
          dfs(a[n][i]);
          path.push_back(n);
        }
      }
      // cout << n << "\n";e += 1;

    }
  // }
}

int bfs(int n){
  v[n] = 1;int len;int x;
  queue<pii>q;
  q.push(make_pair(n,0));
  len = 0;
  pii pp;
  while(!q.empty()){
    pp = q.front();
    q.pop();
    n = pp.first;
    len = max(pp.second,len);
    if(len == pp.second) x = n;
    For(i,0,a[n].size()){
      if(v[a[n][i]] == 0) {
        q.push(make_pair(a[n][i],pp.second + 1));
        p[a[n][i]] = n;
      }
    }
    v[n] = 1;
  }
  return x;

}

int main()
{
    int n,x,y;cin >>n;
    For(i,1,n){
      cin >> x >> y;
      a[x].push_back(y);a[y].push_back(x);
    }
    int f =  bfs(1);
    For(i,1,n+1) v[i] = 0;
    int l = bfs(f);
    For(i,1,n+1) v[i] = 0;
    p[f] = -1;
    int prev = p[l];
    e += 1;
    while (prev != -1) {
      sdfs(prev);
       prev = p[prev];
    }
    //
    cout << path.size()<< "\n";
    cout << l << " ";
    For(i,0,path.size()){
      cout << path[i] << " ";
    }
    // Debug(e)
    // cout << f << "\n";
    return 0;
}
