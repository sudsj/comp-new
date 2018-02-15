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
 	
 	tests{
 		int n,c;
 		cin >> n >> c;
 		char s = 'a';
 		if(c != 2){
 			int count = 0;
 			cout << "1 ";
 			while(count < n){
 				s = 'a' + count%c;
 				cout << s;
 				count++;
 			}
 		}else{
 			switch( n ){
 				case 1 : cout << "1 a"; break;
	 				case 2 : cout << "1 ab"; break;
	 				    case 3 : cout << "2 aab"; break;
	 				case 4 : cout << "2 aabb"; break;
	 				 case 5 : cout << "3 aaabb"; break;
	 				case 6 : cout << "3 aaabbb"; break;
	 				case 7 : cout << "3 aababbb"; break;
 				case 8 : cout << "3 aaababbb"; break;
 				default : 
 					//n>=9
 				string s = "aababb";
 				cout << "4 ";
 				For(i,0,n){
 					cout << s[i%6];
 				}
 			}
 		}
 		cout << "\n";
 	}
    return 0;
}