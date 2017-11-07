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

int main()
{
    tests{
	long long int n,k;
	cin >> n >> k;
	if(k < ((n)*(n-1)*(n-1))/4 || k > (n*(n-1)*(2*n+1))/6){
		cout << "-1\n";
	}else{
		int a[n][n];int j;
		std::vector<int> v[n];
		For(i,0,n){
			For(j,0,n) a[i][j] = 0;
		}
		int s = (n-1)/2,t=0;
		For(i,0,n){
			t = 0,j=0;
			while(t < s){
				if(j < n && a[j][i] == 0 && i != j){
					a[i][j] = 1;
					//Debug(i) Debug(j) 
					v[i].push_back(j);
					t++;
				}
				j++;
			}
		}
		if(n%2 == 0){
			//need to fill n/2 wins more
			t = 0; s = n/2;
			For(i,0,n){
				j=0;
				if(t == s) break;
				while(t < s){
					if(j < n && a[i][j] == 0 && a[j][i] == 0 && i != j ){
						a[i][j] = 1;
						//Debug(i) Debug(j)
						v[i].push_back(j);
						t++;
					}
					j++;
					if(j >= n) break;
				}
			}
			
		}
		long long int sa = 0;
		int sz[n] = {0};
		For(i,0,n){
			sz[i] = v[i].size(); 
			sa += (v[i].size() * v[i].size());
		}
// 		/
		int f = 0,l = n-1,cl;
		while(sa < k){
			if(v[l].size() == 0) l--;
			if(v[f].size() == n-1-f) f++;
			if(f >= l) break;
			cl = l;
			while(cl>=0 && sa < k){
				t = sz[cl];
				t--;
				while(t > 0 && v[cl][t] > cl) t--;
				if(v[cl][t] < cl){
					v[v[cl][t]].push_back(cl);
					sz[v[cl][t]] ++;
					v[cl].erase(v[cl].begin()+t);
					sa += 2*sz[v[cl][t]] - 1;
					sa -= 2*sz[cl] - 1;
					sz[cl]--;
					a[v[cl][t]][cl] = 1;
					a[cl][v[cl][t]] = 0;	
				}
				cl--; 
			}

		}
		if(sa == k){
		   For(i,0,n){
			For(j,0,n){
				cout << a[i][j];
			}
			cout << "\n";
		} 
		}else cout << "-1\n";
		
	}	

    }
    return 0;
}