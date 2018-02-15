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
long long int d[600][600];
long long int df[600][600];
std::vector<int> v;
long long int getSum(int in){
	// in gives index till which vertices in v can be used in graph
	long long int sum = 0;
	//Debug(in)
	For(i,0,in){
		For(j,0,in){
			sum += df[v[i]][v[j]];
			//Debug(v[i]) Debug(v[j])
			//Debug(df[v[i]][v[j]])
		}
	}
	return sum;
}
int main(){
    // #ifndef ONLINE_JUDGE
 	  //   freopen("input.txt", "r", stdin);
 	  //   freopen("output.txt", "w", stdout);
    // #endif
 	int n; cin >> n;
 	int ds;
 	For(i,1,n+1){
 	    For(j,1,n+1){
 	    	cin >> d[i][j];
 	    	df[i][j] = INT_MAX;//infinity
 	    }
    }
    //Debug(df[3][3])
    int z;
    For(t,0,n){
    	cin >> z;v.push_back(z);
    	//deleting that vertex first
    }
    reverse(v.begin(), v.end());

    std::vector<long long int> s;


    //run All Pairs Shortest Paths
    int k,in=0;
    //initially no index included
    s.push_back(getSum(in));
    For(K,0,n){
    	in++;
    	k = v[K];//Debug(k)
    	//Debug(df[3][3])
    	//Debug(d[3][3])
    	//now we include that vertex and update all edges for that vertex
    	For(i,0,in+1){
    		df[k][v[i]] = min(df[k][v[i]],d[k][v[i]]);
    	}
    	For(i,0,in+1){
    		df[v[i]][k] = min(df[v[i]][k],d[v[i]][k]);
    	}
    	//now that we have included that vertex in our current graph
    	//we will now consider that vertex as our intermediate vertex in our graph

    	For(i,1,n+1){
    		For(j,1,n+1){
    			df[i][j] = min(df[i][j],df[i][k]+df[k][j]);
    		}
    	}
    	s.push_back(getSum(in));
    }
    reverse(s.begin(),s.end());
    For(i,0,s.size()){
    	cout << s[i] << " ";
    }
    return 0;
 	
}