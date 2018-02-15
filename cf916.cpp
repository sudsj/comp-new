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
string convertToBitString(long long value)
{
    string str(64, '0');

    for(int i = 0; i < 64; i++)
    {
        if( (1ll << i) & value)
            str[63-i] = '1';
    }

    return str;
 }

int main(){
    long long int n,k;cin >> n >> k;
    string s =  convertToBitString(n);
    std::vector<int> v;int st = 0;
    For(i,0,64){
      if(s[i] == '1'){ st = i; break;}
    }

    For(i,st,64){
      v.push_back(s[i] - '0');
    }
    std::reverse(v.begin(), v.end());
    int l = v.size();
    // Debug(v[3])
    //now starts from 2^0 upto 2^5
    int oc = 0;
    For(i,0,l){
      if(v[i] == 1) oc++;
    }
    if(k < oc){
      cout << "No";
    }else{
      std::vector<int> a;//stores ans
      int ez = n-oc;//extra zeroes possible in binary representation
      // if(n%2 == 1) ez -= 1;
      int ezr = k - oc;
      long long int p;
      if(ezr > ez){
        int d = ezr-ez;
        if(d%2 == 1){
          d++;ezr--;
        }
      }
      if(ezr <= ez){
        //make zeroes from numbers
        For(i,0,l){
          if(v[i] == 1){
            if(ezr > 0){
              p = 1 << i;
              if(ezr > (p -1)){
                //push all as zeroes
                ezr -= (p - 1);
                For(i,0,p){
                  a.push_back(1);
                }
              }else{
                // ezr <= p
                ezr += 1;p=0.5;
                For(j,0,i){
                  p = p*2;
                  if(ezr <= 0){
                    a.push_back(j);ezr -= 1;
                  }else{
                    ezr -= p;
                    For(k,0,p){
                      a.push_back(0);
                    }
                  }
                }
              }
            }else{
              a.push_back(i);
            }
          }
        }
      }else{

      }
    }
    return 0;
}
