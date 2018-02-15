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
int leng[100001];
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

 	string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";    
 	string s1 = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
 	Debug(s1.length())
 	int ex = s1.length() - 2*(s0.length());
 	leng[0] = s0.length();
 	Debug(ex)
 	For(i,1,100001){
 		leng[i] = ex + 2*leng[i-1];
 	}
 	
    return 0;
}