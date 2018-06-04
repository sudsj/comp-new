#include <bits/stdc++.h>
#include <cstdlib>
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
int n;
long long int a[110000] = {0};
long long int cs[110000] = {0};
long long int lcs[110000] = {0};
long long int vote[110000] = {0};//votes
long long int ur[110000] = {0};//update array

void bsright(int l, int r, long long int x, int i){
	//inclusive bounds l and r
	// x is the a[i] being searched
	//org is cs[i] for comparison
	long long int org = cs[i];
	if(l > r) return;
	if(l < 0) return ;
	if(r >= n) return ;
	int mid = l+r;
	mid = mid/2;
	//if l == r == n-1 -> doesnt matter
	if(l == r && l == n-1){
		ur[i+1] += 1;
		ur[n] -= 1;
		return;
	}
	//update from i+1 to n-1 inclusive
	//we want to find the leftmost inconsitency
	if(cs[mid] - org > x){
		//inconsistent
		if(mid == l){
			//update from i+1 to l inclusive
			ur[i+1] += 1;
			ur[l+1] -= 1;
		}else{
			//check left
			if(cs[mid-1] - org > x){
				//go left
				bsright(l,mid-1,x,i);
			}else{
				//this is it from i+1 to mid inclusive
				ur[i+1] += 1;
				ur[mid+1] -= 1;
			}	
		}		
	}else{
		//go right
		bsright(mid+1,r,x,i);
	}
}
void bsleft(int l, int r, long long int x, int i){
	//inclusive bounds l and r
	// x is the a[i] being searched
	//org is cs[i] for comparison
	// if(i == 3) cout << "8 is here with l: " << l << " r: " << r<<"\n";
	long long int org = lcs[i];
	if(l > r) return;
	if(l < 0) return ;
	if(r >= n) return ;
	int mid = l+r;
	mid = mid/2;
	// if(i == 3) cout << "8 is here with l: " << l << " r: " << r<<"\n";
	//if l == r == 0 -> doesnt matter
	if(l == r && l == 0){
		// Debug(x)
		ur[0] += 1;
		ur[i] -= 1;
		return;
		// Debug(x)
	}
	//update from i+1 to n-1 inclusive
	//we want to find the rightmost inconsitency
	if(lcs[mid] - org > x){
		//inconsistent
		if(mid == r){
			// Debug(x)
			//update from r to i-1 inclusive
			ur[r] += 1;
			ur[i] -= 1;
		}else{
			//check right
			if(lcs[mid+1] - org > x){
				//go right
				bsleft(mid+1,r,x,i);
			}else{
				// Debug(x) Debug(a[mid])
				// Debug(l) Debug(r)
				//this is it from mid to i-1 inclusive
				ur[mid] += 1;
				ur[i] -= 1;
			}	
		}		
	}else{
		//go left
		if(l == mid && mid == 0){
			ur[0] += 1;
			ur[i] -= 1;
			return;
		}
		bsleft(l,mid-1,x,i);
	}
	// if(i == 3) cout << "8 is here with l: " << l << " r: " << r<<"\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

 	tests{
 		 n = 10;
 		 if(n == 1){
 		 	cin >> n;
 		 	cout << "0\n";
 		 	continue;
 		 }
 		// int a[n];
 		For(i,0,n){
 			cin >> a[i];
 		}
 		// int cs[n];
 		cs[0] = a[0];
 		For(i,1,n){
 			cs[i] = cs[i-1] + a[i];
 		}
 		lcs[n-1] = a[n-1];
 		for(int i = n-2; i>=0;i--){
 			lcs[i] = lcs[i+1] + a[i];
 		}
 		//cleanup
 		For(i,0,n+1){
 			ur[i] = 0;
 			vote[i] = 0;
 		}
 		For(i,0,n-1){
 			bsright(i,n-1,a[i],i);
 			// cout << a[i] <<" votes for : \n";
 			// For(i,0,n){
 			// 	cout << ur[i] << " ";
 			// }
 			// cout<<"\n";
 		}
 		For(i,1,n){
 			bsleft(0,i-1,a[i],i);
 			// cout << a[i] <<" votes for : \n";
 			// For(i,0,n){
 			// 	cout << ur[i] << " ";
 			// }
 			// cout<<"\n";
 		}
 		cout << "\nVotes:\n";
 		long long int add = 0;
 		For(i,0,n){
 			add += ur[i];
 			vote[i] += add;
 			cout << vote[i] << " ";
 		}
 		cout << "\n";
 		//checker
 		long long int ans[n] = {0};
 		For(i,0,n-1){
 			ans[i+1] += 1;
 			long long int sum = a[i+1];
 			For(j,i+2,n){
 				if(sum <= a[i]){
 					ans[j] += 1;
 					sum += a[j];
 				}else{
 					break;
 				}
 			}
 		}
 		For(i,1,n){
 			ans[i-1] += 1;
 			long long int sum = a[i-1];
 			for(int j = i-2; j >= 0;j--){
 				if(sum <= a[i]){
 					ans[j] += 1;
 					sum += a[j];
 				}else{
 					break;
 				}
 			}
 		}
 		int flag = 0;
 		cout <<"Answers:\n";
 		For(i,0,n){
 			cout << ans[i] << " ";
 			// Debug(vote[i])
 			// Debug(ans[i])
 			if(vote[i] != ans[i]){
 				// Debug(i);
 				flag = 1;
 			}
 		}
 		if(flag) cout << "\nMISTAKE on "<< t <<" \n";
 		// cout << RAND_MAX;
 	}   	
    return 0;
}