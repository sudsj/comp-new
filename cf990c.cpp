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
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    long long int score[n] = {0};
    int negflag[n] = {0};
    std::map<long long int, long long int> mp;
    string s;
    For(i,0,n){
    	cin >> s;
    	int nflag = -1;//negative flag
        long long int maxneg = 0;
    	For(j,0,s.length()){
    		if(s[j] == '('){
    		 score[i] += 1;
    		}else score[i] -= 1;
            if(score[i] < 0){
                maxneg = min(score[i],maxneg);
            }
    		// if(score[i] < 0 && nflag == -1){
    		// 	nflag = 0;
    		// }
    		// if(score[i] >= 0 && nflag == 0){
    		// 	nflag = 1;
    		// }
    	}
        if(maxneg < 0){
             if(score[i] != maxneg){
                negflag[i] = 1;
                continue;
             }
        }
    	// if(nflag == 1) negflag[i] = 1;
    	// if(nflag == 1) continue;
    	long long int ttt = mp[score[i]];
    	mp[score[i]] = ttt+1;
    }
    long long int ans = 0;
    For(i,0,n){
    	if(negflag[i] == 1) continue;
    	if(score[i] == 0){
    		ans += mp[0];
            // Debug(mp[0])
    	}else{
    		if(score[i] < 0) continue;
    		int ttt = score[i]*(-1);
    		ans += mp[ttt];
            // Debug(i)
            // Debug(mp[ttt])
    	}
    }
    cout << ans<<"\n";
 	//   	
    return 0;
}