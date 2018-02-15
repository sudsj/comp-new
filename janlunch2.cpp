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
int tr[200100],a[200100];
// int lazy[2000] = {0};
void build(int node, int start, int end){
  if(start == end){
    tr[node] = a[start];
  }else{
    build(2*node,start,(start+end)/2);
    build(2*node + 1,(start+end)/2 + 1, end);
    tr[node] = min(tr[2*node], tr[2*node+1]);//sum of left and right childs

  }
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
      a[idx] += val;
      tr[node] += val;
    }else{
      int mid = (start+end)/2;
      if(idx >= start && idx <= mid){
        update(2*node,start,mid,idx,val);

      }else{
        update(2*node+1,mid+1,end,idx,val);

      }
      tr[node] = min(tr[2*node], tr[2*node+1]);
    }

}
int query(int node, int start, int end, int l, int r){
    //start to end sum is stored in node we want sum from l to r
    if(start > r || end < l) return INT_MAX;
    if(l <= start && end <= r){
      //we have to completely sum from start to end
      return tr[node];//it stores the coresp sum
    }else{
      // some overlap
      int mid = (start + end )/ 2;
      return min(query(2*node,start,mid,l,r), query(2*node+1,mid+1,end,l,r));

    }
}



int main()
{
	#ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
    For(i,0,200000) tr[i] = INT_MAX;
  int n;cin >> n;int l,r,val;int k;cin >> k;
  For(i,0,n) cin >> a[i];//build(1,0,n-1);
//   cin >> l >> r >> val;
//   lzr(1,0,n-1,l,r,val);
  // cin >> l >> r;
  // cout << query(1,0,n-1,l,r)<<"\n";
  int xl[n+1],xr[n+1];
  xl[0] = a[0];
  xr[n-1] = a[n-1];

  For(i,1,n){
  	xl[i] = (xl[i-1])^(a[i]);
  }
  for(int i = n-2;i>=0;i--){
  	xr[i] = (xr[i+1])^(a[i]);
  }
  std::vector<int> v;int x;int m;
  int cnt[12801] = {0};
  For(i,0,n){
  	m = a[i];
  	For(j,i,n){
  		m = min(m,a[j]);
  		x = (a[i])^((xl[j])^(xl[i]));
  		// Debug(x)
  		x = (x)*(m);
  		cnt[x]++;
  		// v.push_back(x);
  	}
  }
  // sort(v.begin(), v.end());
  For(i,0,12801){
  	k -= cnt[i];
  	if(k <= 0){
  		cout << i;break;
  	}
  }
  // cout << v[k-1];
    return 0;
}
