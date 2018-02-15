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
	std::vector< pair <long long int,long long int> > v;//so that we start indexing from 1
public:	
	void starter(){v.push_back(make_pair(-1,-1));}
	long long int parent(long long int i){ return (i)/2;}//don't call on root(index 1)
	long long int leftchild(long long int i) {return 2*i;}
	long long int rightchild(long long int i) {return 2*i + 1;}

	void minheapify(long long int i){
		 long long int l = leftchild(i);
		 long long int r = rightchild(i);
		 long long int min;
		 if(l < v.size() && v[l].X < v[i].X){
		 	min = l;
		 }else min  = i;
		 if(r < v.size() && v[r].X < v[min].X) min = r;
		 if(min != i){
		 	//swap v[min] and v[i]
		 	swap(v[i].X,v[min].X);
		 	swap(v[i].Y,v[min].Y);
		 	
		 	minheapify(min);
		 }
	}


	void heapifyUp(long long int i){
		if(i > 1 && v[i].X < v[parent(i)].X){
			swap(v[i].X,v[parent(i)].X);
			swap(v[i].Y,v[parent(i)].Y);
			heapifyUp(parent(i));
		}
	}

	void insert(long long int val,long long int node){
		v.push_back(make_pair(val,node));
		heapifyUp(v.size()-1);
	}

	bool empty(){
		return v.size()==1;
	}
	long long int top(){
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
			v[1].X = v[v.size()-1].X;
			v[1].Y = v[v.size()-1].Y;
			//v.resize(v.size()-1);
			v.pop_back();
			//Debug(v.size())
			//now min heapify from root
			minheapify(1);
		}
	}

	void print(){
		For(i,1,v.size()){
			cout << v[i].Y << " " <<v[i].X <<"\n";
		}
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

	PriorityQ pq;pq.starter();//Debug(pq.empty())
	// pq.insert(111,221);pq.insert(10,32);pq.insert(8,13);
	//  pq.insert(15,42);
	//  pq.insert(3,2);
	// // pq.insert(11,12);
	// pq.print();
	// while(!pq.empty()){
	// 	Debug(pq.top())
	// 	//cout << "a";
	// 	pq.pop();
	// }
	//take input and form graph
	long long int n,source; long long int md,c1,c2,d1,d2,w1,w2,w3;
	cin >> n >> source >> md >> c1 >> c2 >> d1 >> d2 >> w1 >> w2 >> w3;
	//now generate graph
	long long int deg,tempv,tempw;
	std::vector< pair <long long int,long long int> > a[n+1];//for n nodes
	For(k,1,n+1){
		long long int i = k;
		deg = ((i*c2)%md + (((i*i)%md)*d2)%md)%md;
		For(j,1,deg+1){
			tempv = ( (i*c1)%n + (j*d1)%n )%n;
			tempv += 1;
			tempw = ( (i*w1)%w3 + (j*w2)%w3 )%w3;
			//if(i == source){ Debug(tempv) Debug(tempw)}
			//to prevent self edge
			if(tempv != i) a[i].push_back(make_pair(tempv,tempw));
		}
	}

	//now implement dijkstras
	//distances are +inf
	long long int d[n+1];
	long long int visited[n+1]={0};
	For(i,1,n+1) visited[i]=0;
	For(i,0,n+1) d[i] = LLONG_MAX;

	//source distance = 0;
	d[source] = 0;
	//push source into pq(val,node)
	pq.insert(0,source);
	long long int node,adjsize,adj;long long int dist;

	while(!pq.empty()){
		node = pq.top();
		pq.pop();
		//Debug(node)
		//Debug(visited[node])
		if(visited[node] == 1) continue;

		visited[node] = 1;
		adjsize = a[node].size();
		For(i,0,adjsize){
			//update distances
			adj = a[node][i].X;
			dist = a[node][i].Y;
			if(d[adj] > (d[node] + dist)){
				d[adj] = d[node] + dist;
				//push into q
				pq.insert(d[adj],adj);
			}
		}
	}
	For(i,1,n+1){
		cout << i<< " ";
		if(d[i] != LLONG_MAX){
			cout << d[i];
		}else cout << -1;
		cout << "\n";
	}
	//Debug(pq.top())
    return 0;
}