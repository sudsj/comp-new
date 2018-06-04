#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define int unsigned long long
#define ll unsigned long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>
 
#define vi vector<int> 
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<int,int> >   
#define vpl vector< pair<ll,ll> >   
#define viii vector< vector<vector<int> > >
typedef pair<pair<int, int>,int> P;
#define mod %1000000007
#define pi 3.14159265358979323846//20 decimals
#define ld long double
bool less_vectors(const vector<int>& a,const vector<int>& b) 
{
  return a.size() < b.size();
}

int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    vl v;
    map<ll,int> m;
    int cnt=0;
    for(int i=2;i<=1000000;i++)
    {
        ll f=i*i;
        ll prev=f;
        int j=3;
        for( j=3;f*i<=1000000000000000000 && f*i>=prev;j++)
        {
            f=f*i;
            /*if(m[f]==0)
                {v.pb(f);m[f]=1;}*/
            v.pb(f);
            cnt++;
            prev=f;
            if (i > 0 && f > (unsigned long long)(18446744073709551615) / i)
                 break;
            //trace3(i,cnt,f);
        }
        /*if(i==1000000)
            trace3(f,j,f*i);*/
       // trace2(i,j);
    }
    //trace1(v.size());
    sort(v.begin(),v.end());
    vl a;
    vl g;
    for(int i=0;i<v.size();i++)
    {
        int j=i;
        for(;j<v.size() && v[j]==v[i];j++)
            ;
        a.pb(v[i]);
        int x=(int)sqrt(v[i]);
        if(x*x==v[i])
            g.pb(x);
        i=j-1;
    }
   // v=a;
    //trace2(g.size(),a.size());
    int q;
    cin>>q;
    sort(v.begin(),v.end());
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        int ans=upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
        int h1=(int)sqrt(l);
        if(h1*h1<l)
            h1++;
        int h2=(int)sqrt(r);
        if(h1>h2)
            ;
        else
            ans+=h2-h1+1;
        int diff=upper_bound(g.begin(),g.end(),h2)-lower_bound(g.begin(),g.end(),h1);
        //trace1(h2-h1+1-diff);
        cout<<ans-diff<<endl;
    }
    

    return 0;
}