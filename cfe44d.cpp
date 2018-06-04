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
long long int n,hmax;
long long int x,summ,sumh,ans,dif,add,sum,y;

long long int csum(long long int y){
	//custom sum
	long long int sums = 0,sumd=0;
	sums = y*(y-1);
	// sums /= 2;
	sums += y;
	sumd = hmax*(hmax-1);
	sumd /= 2;
	sums -= sumd;
	return sums;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> hmax;
    //n sand packets
    long long int start = 1;long long int endlimit = 5000000000;
    x = (start + endlimit)/2;
    // Debug(x)

    int count = 0;
    while(x >= start && x <= endlimit && count < 10000){
    	count++;
    	x = (start + endlimit )/2;
    	// Debug(x)
    	summ = x*(x+1)*1LL;
    	// Debug(summ)
    	summ /= 2;
    	sumh = summ + x + 1;
    	if(summ == n){
    		ans = x;dif = 0;
    		break;
    	} 
    	if(summ > n){//go smaller
    		endlimit = x;continue;
    	}else{
    		if(sumh > n){
    			// Debug(summ)

    			// Debug(sumh)
    			dif = n - summ;
    			ans = x+1;break;
    		}else{
    			start = x;continue;
    		}
    	}

    }
    if(x <= hmax){
    	cout << ans;
    
    }else{
    	//compensate for boundary
    	//hmax,hmax+1,...y,y-1,y-2...1
    	//replace hmax+1,hmax+2,....x + dif
    	ans = hmax;//1,...,hmax
    	start = hmax;endlimit = 5000000000;
    	int count = 0;
    	x = (start+endlimit)/2;
    	while(x >= start && x <= endlimit && count < 10000){
    		count++;
    		x = (start+endlimit )/2;
    		y = csum(x);
    		if(y == n){
    			// Debug(x)
    			// Debug(y)
    			ans = x + (x-hmax);break;
    			break;
    		}else if(y > n){
    			endlimit = x;
    		}else{
    			//y < n;
    			if(n >= csum(x+1)){
    				start = x;
    			}else{
    				//csum(x) < n < csum(x+1)
    				if(n <= y + x){
    					// Debug(x)
    					ans = x + (x-hmax)  + 1;break;
    				}else{
    					ans = x + (x-hmax)  + 2;break;
    				}
    			}
    		}
    	}
    	// Debug(ans)
    	// sumh = x*(x+1)*1LL;
    	// sumh /= 2;
    	// summ = hmax*(hmax+1)*1LL;
    	// summ /= 2;
    	// sum = n - summ;
    	// // sum += dif;
    	// //now cover this sum;
    	// add = sum/hmax;
    	// if(hmax*add < sum) add++;
    	// ans += add;
    	cout << ans;
    }
    
    return 0;
}