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
int a[100];
int coin(int s,int n){
    if(s == n) return a[n];
    else if(s == n-1) return max(a[n-1],a[n]);
    else return max(a[s],)
}

int main()
{
    int n; cin >> n;
    
    For(i,0,n){
        cin >> a[i];
    }
    int b=0,aa=0;
    int pien = 0; int turn = 1;
    //1 for bob
    while(pien < n){
        if(turn == 1){
            int sum = 0,max=0,ind,sumst; 
            if(pien >= n-2){
                For(i,pien,n) aa += a[i];
                pien = n;
            }else{
            For(i,pien,n){
                if(i > pien) sum += a[i-1];
                if(a[i] > sum){
                    if(a[i] > max){
                        sumst = sum;
                        max = a[i];
                        ind = i;
                    }
                }               
            }
            b += sumst;
            aa += max;
            pien = ind + 1;
            turn = 0;}
        }else{
            int sum = 0,max=0,ind,sumst; 
            if(pien >= n-2){
                For(i,pien,n) b += a[i];
                pien = n;
            }else{
            For(i,pien,n){
                if(i > pien) sum += a[i-1];
                if(a[i] > sum){
                    if(a[i] > max){
                        sumst = sum;
                        max = a[i];
                        ind = i;
                    }
                }               
            }
            aa += sumst;
            b += max;
            pien = ind + 1;
            turn = 1;}
        }
    }
    cout << aa << "\n" << b;
    return 0;
}
