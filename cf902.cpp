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

    int h; cin >> h;
    int a[h+1];
    For(i,0,h+1){
    	cin >> a[i];
    }
    flag = 0;
    For(i,1,h){
    	if(a[i] >= 2){ flag = i; break;}
    }
    if(flag != 0){
    	int sum = 0;
    	For(i,0,h+1){
    		sum += a[i];
    	}
    	int f[sum+1],s[sum+1];
    	f[1] = 0;
    	s[1] = 0;
    	std::vector<int> v;//store parents
    	For(i,1,flag){
    		//right upto flag-1 height a[i] = 1
    		f[i+1] = i;
    		s[i+1] = i;
    	}
    	int index = flag;//already filled
    	//now we are at flag - 1 height 
    	v.push_back(flag);//is the last parent

    	For(i,0,a[flag]){
    		f[flag + 1 + i] = v[0];
    		s[flag + 1 + i] = v[0];
    		index = flag + 1 + i;

    	}
    	int one = index;
    	int two = index - 1;
    	//now at flag ht going to flag + 1 ht
    	For(i,0,a[flag+1]){
    		index++;
    		f[index] = one;
    		s[index] = two;
    	}
    	//last filled at height == flag+1 is new parent
    	int parent = index;
    	//tlll index filled
    	For(ht,flag+2,h+1){
    		For(i,0,a[ht]){
    			index++;
    			f[index] = parent;
    			s[index] = parent;
    		}
    		parent = index;
    	}
    	For(i,1,sum+1){
    		cout << f[i] << " ";
    	}
    	cout << "\n";
    	For(i,1,sum+1){
    		cout << s[i] << " ";
    	}
    }else{
    	cout << "perfect";
    }

    return 0;
}