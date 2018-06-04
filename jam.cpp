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
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int cn = 0;
    tests{
    	long long int d,cp=0,td=0;
    	cin >> d;
    	string s;cin >> s;
    	cn++;
    	cout << "Case #"<<cn<<": ";
    	// Debug(s)
    	cp = 1;
    	For(i,0,s.length()){
    		if(s[i] == 'C'){
    			cp *= 2;

    		}else td += cp;
    	}
    	if(td <= d){
    		cout << "0\n";
    	}else{
    		int len = s.length();
    		long long int sp[len] = {0};
    		cp = 1;
    		For(i,0,len){
    			if(s[i] == 'C'){
    				cp *= 2;
    			}else{
    				sp[i] = cp;
    			}
    		}
    		int ans = 0,flag=0;
    		for(int i = len-1; i>=0;i--){
    			if(s[i] == 'C'){
    				For(j,i+1,len){
    					if(s[j] == 'S'){
    						td -= sp[j]/2;
    						sp[j-1] = sp[j]/2;
    						sp[j] = 0;
    						ans++;
    						s[j-1] = 'S';
    						s[j] = 'C';
    					}else break;
    					if(td <= d){
    						cout << ans <<"\n";
    						flag = 1;break;
    					}
    				}
    			}
    			if(flag){
    				break;
    			}
    		}
    		if(flag){
    			continue;
    		}else{
    			// Debug(td) Debug(d)
    			if(td <= d){
    				cout << ans <<"\n";
    				
    			}else cout << "IMPOSSIBLE\n";
    		}
    	}
    	
    }

 	


    return 0;
}