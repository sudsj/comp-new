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
//#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
/////////////////////////////////////////////////////////////////////
int dfsv[2000]={0};//for dfs
int visited[2000]={0};//for topological
stack<int> topv;//topologically ordered vertices
std::vector<int> r[2000];
std::vector<int> v[2000];
std::vector<int> lab[2000];//initial labels to the scc to group them

void dfs(int source){
	dfsv[source] = 1;
	For(i,0,v[source].size()){
		if(dfsv[v[source][i]] == 0){
			//unvisited
			dfs(v[source][i]);
		}
	}
	//once dfs is completed
	//push into stack
	topv.push(source);
}

void stdfs(int source, int label){//strong dfs
	visited[source] = 1;
	For(i,0,r[source].size()){
		if(visited[r[source][i]] == 0){
			//unvisited
			stdfs(r[source][i],label);
		}
	}
	//once dfs is completed
	//start labelling 
	lab[label].push_back(source);
	
}

int main()
{
    int n; cin >> n;
    
    int t;
    For(i,0,n){
    	cin >> t;
    	while(t != -1){
    		v[i].push_back(t);
    		cin >>t;
    	}
    }
    //find all strongly connected components
    //first get topological order of components
    For(i,0,n){
    	if(dfsv[i] == 0) dfs(i);
    }
    //now we have generated a topological list
    //reversed graph's adjacency list
    For(i,0,n){
    	For(j,0,v[i].size()){
    		r[v[i][j]].push_back(i);
    	}
    }
    int labstart = 0;//initial labels to group the scc
    int stop;//stack top
    //now start popping from stack which has the sinks of the reversed graph at the top
    while(!topv.empty()){
    	stop = topv.top();
    	topv.pop();	
    	if(visited[stop] == 0){
    		//if not visited then its a new scc 
    		labstart++;
    		stdfs(stop,labstart);//do a dfs from that node and label all nodes in the scc
    	}
    }
    //now time to give new labels according to minimums
    std::vector<pair<int,int> > minindex; //stores the minimum vertex index for each scc
    For(i,1,labstart+1){
    	int min = n+1000;//some random high number
    	For(j,0,lab[i].size()){
    		if(lab[i][j] < min) min = lab[i][j];
    	} //cout << lab[i][j] << " ";
    	//cout << "\n";
    	minindex.push_back(make_pair(min,i));
    }
    sort(minindex.begin(),minindex.end());
    std::vector<int> minlab[2000];//labels according to minimum index of vertex in each scc
    int minlabs[n];//stores new labels
    For(i,0,minindex.size()){
    	int old = minindex[i].second;//old label
    	For(j,0,lab[old].size()){
    		minlabs[lab[old][j]] = i;
    		//minlab[i].push_back(lab[old][j]);//push all elements of old with new label as i
    	}
    }
    int marked[n]={0};
    //now all vertices are labelled so then start pushing stuff
    set<int> con[minindex.size()];//stores connections for each labelled vertex
    For(i,0,n){
    	For(j,0,v[i].size()){
    		if(minlabs[v[i][j]] != minlabs[i]){
    			//edge between 2 diff scc
    			con[minlabs[i]].insert(minlabs[v[i][j]]);
    		}
    	}
    }
    std::set<int>::iterator it;
    For(i,0,minindex.size()){
    	for(it = con[i].begin(); it != con[i].end(); ++it ){
    		cout << *it << " ";
    	}
    	cout << "-1\n";
    } 	

    return 0;
}