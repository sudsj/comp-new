#include<bits/stdc++.h>
#define LL long long int
#define REP(i,n) for(int i=0;i<n;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define VPII vector<pair<int,int >
using namespace std;
bool a[100000000];//add 0
LL primes[100000000],in=0;//add 0
void Sieve(long long int n)
{
    memset(a,true,sizeof(a));
    a[1]=false;
    for(long long int i=2;i*i<=n;i++)
    {
        if(a[i])
        {
            for(long long int j=2*i;j<n;j+=i)
                a[j]=false;
        }
    }
    for(long long int i=2;i<=n;i++)
    {
        if(a[i])
            primes[in++]=i;
    }
}
LL calc(LL idx,LL cur,LL k)
{
    LL square=primes[idx]*primes[idx];
    LL newCur=square*cur;
    LL res=0;

    if(newCur<0||newCur>k)
            return 0;
    res+=k/(newCur);
    res+=calc(idx+1,cur,k);
    if(newCur>0&&newCur<k)
      res-=calc(idx+1,newCur,k);
    return res;
}
LL sqfree(LL n)
{
    LL lo=1; LL hi=2000000000000l;
    while(lo<hi)
    {
      LL mid=lo+(hi-lo)/2;
      LL cnt=mid-calc(0,1,mid);
      if(cnt<n)
      {
        lo=mid+1;
      }
      else
      {
        hi=mid;
      }
    }
    return lo;
}
int main()
{
    Sieve(10000000);
    LL n,m,y,mp,ap,ans; int up = 1;

        cin >> n;
        m = 1.55054649 * n;//number of sqfree no.s upto n+m numbers
        ap = sqfree(m);
        ans = ap - m;//approx val of ans
        if(ans > n){
            if(ans - n > 3){
                m -= ans - n - 3;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 3){
                m += n - ans - 3;
                ap = sqfree(m);
            }
        }
        if(ans > n){
            if(ans - n > 3){
                m -= ans - n - 3;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 3){
                m += n - ans - 3;
                ap = sqfree(m);
            }
        }
        if(ans > n){
            if(ans - n > 3){
                m -= ans - n - 3;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 3){
                m += n - ans - 3;
                ap = sqfree(m);
            }
        }
        if(ans > n){
            if(ans - n > 3){
                m -= ans - n - 3;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 3){
                m += n - ans - 3;
                ap = sqfree(m);
            }
        }
        if(ans > n){
            if(ans - n > 3){
                m -= ans - n - 3;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 3){
                m += n - ans - 3;
                ap = sqfree(m);
            }
        }
        if(ans > n){
            if(ans - n > 3){
                m -= (ans - n)*1.5;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 3){
                m += (n - ans)*1.5;
                ap = sqfree(m);
            }
        }
        if(ans > n){
            if(ans - n > 10){
                m -= ans - n - 10;
                ap = sqfree(m);
            }
        }
        if(ans < n){
            if(n - ans > 10){
                m += n - ans - 10;
                ap = sqfree(m);
            }
        }
        if(ans >= n){

            up = -1;//more than n sq numbers before ap
            while(ans >= n){
              m += up;
              ans = sqfree(m) - m;
            }
            //now ans < n;
            // y = sqfree(m) + (n - ans);
            y = n+m;
        }else if(ans < n){
          mp = m;
          while(ans < n){
            mp = m;
            m += 1;
            ans = sqfree(m) - m;
          }
          //sqfree(mp) < ans < sqfree(m)
          y = sqfree(mp) + (n - (sqfree(mp) - mp));
        }

        // ans =
        cout << y<<"\n";

    return 0;
}
