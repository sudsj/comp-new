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
long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k%2) {
      res = (res * cur)%p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}
int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;
  while (u <= temp) {
    degree_num += temp/u;
    u *= p;
  }
  return degree_num;
}

long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n- k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * degree(ti, p-2, p))%p;
  }
  return res;
}
int main()
{//remember to do ifs and modulo p
    int array[3];
    long long int p = 998244353;
    For(i,0,3) cin >> array[i];
    sort(array,array+3);
    int a,b,c;
    a = array[0];//smallest
    b = array[1];
    c = array[2];//largest
    long long int ans=1,sum=0,tans=0;
    //a and b
    tans=0;
    For(i,0,a+1){
        sum = combinations(a,i,p);
        For(j,0,a-i){

            sum *= (b - j);
            if(sum > p) sum = sum%p;
        }
        tans += sum;
        if(tans > p) tans = tans%p;
        //Debug(sum)
    }
    ans *= tans;
    ans = ans%p;
    //now for a and c
    tans=0;
    For(i,0,a+1){
        sum = combinations(a,i,p);
        For(j,0,a-i){
            sum *= (c - j);
            if(sum > p) sum = sum%p;
        }
        tans += sum;
        if(tans > p) tans = tans%p;//Debug(sum)
    }ans *= tans;
        ans = ans%p;
    //for b and c
    tans=0;
    For(i,0,b+1){
        sum = combinations(b,i,p);
        For(j,0,b-i){
            sum *= (c - j);
            if(sum > p) sum = sum%p;
        }
        tans += sum;
        if(tans > p) tans = tans%p;//Debug(sum)
    }
    ans *= tans;
        ans = ans%p;
    cout << ans;
    return 0;
}
