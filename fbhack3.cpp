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
string s; 
int echk(string b){
    int i = 0; int j = 0;
    while(i < s.length() && j < b.length()){
        if(s[i] == b[j]){
            i += 1;
            j += 1;
        }else if(i == 0){
            j++;
        }else{
            i = 0;
        }
    }
    if(i >= s.length()){
        return 1;//match found
    }else return 0;//j >= b.len no match
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int tn = 0;
    tests{
    	tn++;
    	cin >> s;
        char f = s[0];//first letter
        string pre,rest;
        pre = pre + s[0];
        For(i,1,s.length()){
            rest = rest + s[i];

        }
        string x;
        int flag = 1;
        For(i,1,s.length()){
            pre = pre + s[i];
            if(s[i] == f){
                x = pre + rest;
                //now check
                flag = echk(x);
                if(!flag) break;
            }

        }

    	cout << "Case #" << tn << ": " ;
    	if(flag){
            cout << "Impossible";
        }else{
            cout << x;
        }
    	cout << "\n";
    }
    return 0;
}