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
long long int minn = LLONG_MIN;

int main()
{
    int n; long long int a,b,c;cin >> n; long long int ar[n],maxl[n],maxr[n],minl[n],minr[n];
    cin >> a >> b >> c;
    long long int in,amax = minn,amin = LLONG_MAX;
    //cin >> n;
    For(i,0,n){
        cin >> ar[i]; in = ar[i];
        if(i != 0) maxl[i] = maxl[i-1];
        if(i != 0) minl[i] = minl[i-1];
        if(in > amax) amax = in, maxl[i] = i;
        if(in < amin) amin = in, minl[i] = i;

    }
    amax = minn;amin = LLONG_MAX;
    for(int i = n-1; i >= 0; i--){
        in = a[i];
        if(i != n-1) maxr[i] = maxr[i+1];
        if(i != n-1) minr[i] = minr[i+1];
        if(in > amax) amax = in, maxr[i] = i;
        if(in < amin) amin = in, minr[i] = i;

    }
    long long int sum=0,tp=0;
    if(a > 0){
        //first max 
        if( b > 0){
            if(c > 0){
                For(i,0,n){
                    tp = a[maxl[i]] + a[maxr[i]] + a[maxr[maxr[i]]];
                    if(tp > sum ) sum = tp;
                    
                }
            }
        }
        For(i,0,n){
            tp = a[maxl[i]] + a[minr[i]];
            int st = minr[i];
        }
    }
    cout << sum;
    return 0;
}
