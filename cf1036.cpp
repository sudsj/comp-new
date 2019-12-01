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
std::vector<long long int> v;
std::map<long long int , int> mapp;
void gen(){
	long long int base,num;
	int flag = 0;
	For(dd,1,19){
		//num of digits
		base = pow(10,dd-1);
		For(ff,1,10){
			//first digit
			//only one digit
			num = base*ff;
			v.push_back(num);
			//second digit  more
			For(ss,0,dd-1){
				For(i,1,10){
					num = base*ff + i*pow(10,ss);
					v.push_back(num);
				}
				//third digit
				For(tt,0,dd-1){
					if(tt == ss) continue;
					For(i,1,10){
						For(j,i,10){
							num = base*ff + i*pow(10,ss) + j*pow(10,tt);
							if(i == j){
								if(mapp.count(num) > 0) continue;
								mapp[num] = 1;
							}
							v.push_back(num);
						}
						
					}
				}

			}
		}
	}
	v.push_back(1000000000000000000);
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    long long int l,r;
    long long int minm,dg,sd,left,ans;

    gen();
    sort(v.begin(), v.end());
    long long int sz = v.size();
    Debug(sz)
    // For(i,0,607420) Debug(v[i])
    tests{
    	cin >> l >> r;
    	ans = 0;
    	vector<long long int>::iterator lower,lowerr; 
    	lower = lower_bound (v.begin(), v.end(), l);
    	lowerr = lower_bound (v.begin(), v.end(), r);
    	int lind = lower - v.begin();
    	int rind = lowerr - v.begin();
    	// Debug(lind)
    	// Debug(rind)
    	// Debug(v[rind])
    	if(v[rind] > r) rind--;
    	ans = rind - lind + 1;
    	if(ans < 0) ans = 0;

    	cout << ans<<"\n";
    	int i = 6;
    	int j = 4;
    	int ff = 1;
    	dg = pow(10,18);
    	ans = ff*dg + i*pow(10,17) + j*pow(10,13);
    	Debug(ans)
    	// Debug(ans)
    }


    ///////////
    return 0;
}