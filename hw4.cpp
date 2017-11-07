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
#define X first
#define Y second
/////////////////////////////////////////////////////////////////////

//NOW CHANGE VECTOR V INTO A VECTOR OF PAIRS WITH VALUES AND NODE NUMBERS STORED 

struct PriorityQ//minimum priority Queue
{
private:
	std::vector< pair <int,int> > v;//so that we start indexing from 1
public:	
	void starter(){v.push_back(make_pair(-1,-1));}
	int parent(int i){ return (i)/2;}//don't call on root(index 1)
	int leftchild(int i) {return 2*i;}
	int rightchild(int i) {return 2*i + 1;}

	void minheapify(int i){
		 int l = leftchild(i);
		 int r = rightchild(i);
		 int min;
		 if(l < v.size() && v[l].X < v[i].X){
		 	min = l;
		 }else min  = i;
		 if(r < v.size() && v[r].X < v[i].X) min = r;
		 if(min != i){
		 	//swap v[min] and v[i]
		 	swap(v[i].X,v[min].X);
		 	swap(v[i].Y,v[min].Y);
		 	int temp = v[min].X;
		 	v[min].X = v[i].X;
		 	v[i].X = temp;
		 	minheapify(min);
		 }
	}


	void heapifyUp(int i){
		if(i >= 1 && v[i].X < v[parent(i)].X){
			swap(v[i].X,v[parent(i)].X);
			swap(v[i].Y,v[parent(i)].Y);
			heapifyUp(parent(i));
		}
	}

	void insert(int val, int node){
		v.push_back(make_pair(val,node));
		heapifyUp(v.size()-1);
	}

	bool empty(){
		return v.size()==1;
	}
	int top(){
		if(!empty()){
			return v[1].Y;
		}else{
			cout<<"empty!!";
			return -1;
		}
	}
	void pop(){
		if(!empty()){
			//bring last to first
			v[0].X = v[v.size()-1].X;
			v[0].Y = v[v.size()-1].Y;
			v.resize(v.size()-1);
			//now min heapify from root
			minheapify(1);
		}
	}


};

int main()
{
	PriorityQ pq;pq.starter();
	pq.insert(5,1);pq.insert(10,2);pq.insert(8,3);pq.insert(15,4);pq.insert(3,5);pq.insert(1,2);
	//now implement dijkstras
	int n;
	cin >> n;
	std::vector< pair <int,int> > a[n];//for n nodes
	For(i,0,n){
		int t,v;cin >> t;
		while(t != -1){
			cin >> v;
			a[i].push_back(make_pair(t,v));
			cin >> t;
		}
	}
	Debug(pq.top())
    return 0;
}