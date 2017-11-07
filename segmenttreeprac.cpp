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
int tree[1000];

void build(int A[], int start, int end, int node){
	//assume an integer array A[] of size n 
	//we start building from node 
	//tree[node] = sum of elements from Array from start to end
	if(start == end){
		tree[node] = A[start];
	}else{
		int mid = (start + end)/2;
		build(A,start,mid,2*node);//left child
		build(A,mid+1,end,2*node+1);
		tree[node] = tree[2*node] + tree[2*node+1];
	}

}

void update(int start, int end, int node, int *A, int index, int val){
	//update elements of tree from start to end starting from node, also update A[index] += val
	if(start == end){
		tree[node] += val;
		A[index] += val;
	}else{
		
		//int tree[node] += val;
		//check which tree to update
		int mid = (start+end)/2;
		if(index >= start && index <= mid){
			update(start,mid,2*node,A,index,val);//update the left subtree
		}else{
			update(mid+1,end,2*node+1,A,index,val);
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int getsum(int node, int start, int end, int l, int r){
	if(r < start || l > end){
		//totally outside the range
		return 0;
	}else if(l <= start && r >= end){
		 return tree[node];//gets sum of all vars of that node
	}else{
		//r < end
			int mid = (start+end)/2;
			//search left and nright node for appropriate sum
			
			//Debug(getsum(2*node, start, mid, l,r))
			
			// Debug(getsum(2*node, mid+1,end,l,r))
			return getsum(2*node, start, mid, l,r) + getsum(2*node+1, mid+1,end,l,r);
	}
}

int main()
{
	int n;
	cin >> n;
	int A[n];
	For(i,0,n) cin >> A[i];
	build(A,0,n-1,1);//start from node 1 to store sum from 0 to n-1 	   
	
	int l,r;cin >> l >> r;
	cout << getsum(1,0,n-1,l-1,r-1);
	Debug(l) Debug(r)
	int index,val;
	cin >> index >> val;
	update(0,n-1,1,A,index-1,val);
	cout << getsum(1,0,n-1,l-1,r-1);//sum from 3 to 6
	//Debug(getsum(10,3,3,3,3))
	//Debug(tree[10])
    return 0;
}