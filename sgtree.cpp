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
int tr[2000],a[1000];
int lazy[2000] = {0};
void build(int node, int start, int end){
  if(start == end){
    tr[node] = a[start];
  }else{
    build(2*node,start,(start+end)/2);
    build(2*node + 1,(start+end)/2 + 1, end);
    tr[node] = tr[2*node] + tr[2*node+1];//sum of left and right childs

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
      tr[node] = tr[2*node] + tr[2*node+1];
    }

}
int query(int node, int start, int end, int l, int r){
    //start to end sum is stored in node we want sum from l to r
    if(start > r || end < l) return 0;
    if(l <= start && end <= r){
      //we have to completely sum from start to end
      return tr[node];//it stores the coresp sum
    }else{
      // some overlap
      int mid = (start + end )/ 2;
      return query(2*node,start,mid,l,r) + query(2*node+1,mid+1,end,l,r);

    }
}
void updateRange(int node, int start, int end, int l, int r, int val){
  if(start > r || end < l) return;
  if(start == end){
    //we have reached a leaf node
    tr[node] += val;
    return;
  }else{
    //some overlap
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tr[node] = tr[2*node] + tr[2*node+1];
  }
}

void lzr(int node, int start, int end, int l, int r, int val){//lazy update range
  if(lazy[node] != 0){
    //update this node
    tr[node] += (end-start+1)*lazy[node];//update it because we store the sum of the range in the nodes
    if(start != end){
      //we have to update the child nodes
      lazy[2*node] = lazy[node];
      lazy[2*node+1] = lazy[node];
    }
    lazy[node] = 0;//reset
  }
  if(start > r || end < l || start > end) return;
  if(start >= l && end <= r){
    //fully inside upddate range
    tr[node] += val*(end-start+1);
    if(start != end){
      lazy[2*node] += val;
      lazy[2*node+1] += val;
    }
  }else{
    //some overlap (partial)
    // int mid = (start+end)/2;
    int mid = (start + end) / 2;
   updateRange(node*2, start, mid, l, r, val);        // Updating left child
   updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
   tr[node] = tr[node*2] + tr[node*2+1];
  }

}

int lquery(int node, int start, int end, int l, int r){
  if(start > r || end < l || start > end) return 0;
  if(lazy[node] != 0){
    //update this node
    tr[node] += (end-start+1)*lazy[node];//update it because we store the sum of the range in the nodes
    if(start != end){
      //we have to update the child nodes
      lazy[2*node] = lazy[node];
      lazy[2*node+1] = lazy[node];
    }
    lazy[node] = 0;//reset
  }
  if(l <= start && end <= r){
    //we have to completely sum from start to end
    return tr[node];//it stores the coresp sum
  }else{
    // some overlap
    int mid = (start + end )/ 2;
    return lquery(2*node,start,mid,l,r) + lquery(2*node+1,mid+1,end,l,r);

  }
}

int main()
{//FINALLY DONE WITH SEGMENT TREE WITH LAZY UPDATES
  int n;cin >> n;int l,r,val;
  For(i,0,n) cin >> a[i];build(1,0,n-1);
   cin >> l >> r >> val;
   lzr(1,0,n-1,l,r,val);
  cin >> l >> r;
  cout << lquery(1,0,n-1,l,r)<<"\n";

    return 0;
}
