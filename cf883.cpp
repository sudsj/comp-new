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
    int n,m,a;long long int d;
    cin >> n >> m >> a >> d;
    long long int c[n];
    For(i,0,m){
        cin >> c[i];
    }
    long long int ans = 0,t=0,lc=0;lo=0;
    int j=0;
        //last employee enters after last client
    For(i,0,m){
        t = c[i]/a;
        //emp upto time t has to be done

    }
        For(i,1,n+1){
            while(c[j] <= a*i && j<m){
                if(j != 0) lc -= c[j]-c[j-1];
                if(lc < 0){
                    //lift has to open
                    lc = d;//lift now closes after d seconds
                    ans++;
                    j++;
                }else {
                    //lift yet to close
                }
            }
            //enter employee
            if(j != 0){
              if(c[j-1] < a*i){
                  lc -= a*i - c[j-1];
                  if(lc < 0){
                      //lift has to open
                      lc = d;//lift now closes after d seconds
                      ans++;
                      
                  }else {
                      //lift yet to close
                  }
              }  
            }
            

        }
        //now all clients with time <= n*a is over
        //jth employee yet to enter
        if(j != m){
            lc -= c[j] - a*n;
            while(j < m){
                if(lc < 0){
                    //lift has to open
                    lc = d;//lift now closes after d seconds
                    ans++;
                    j++;
                }else {
                    //lift yet to close
                }
            }
        }
    
    return 0;
}

