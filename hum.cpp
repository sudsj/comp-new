#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
 
using namespace std;
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
// #include <unordered_map>
// #include <unordered_set>
#include <list>
#include <bitset>
#include <iomanip>


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
std::vector<int> ch[1100];
std::vector<int> wt(1100,0);
vector<bool> v(1100,false);
int bfs(int u)
{
    queue<int> q;
 
    q.push(u);
    v[u] = true;
    q.push(-1);
    int mxwt = 0,pwt=0,cwt=0;
    while (!q.empty()) {
 
        int f = q.front();
        q.pop();
        if(f == -1){
            mxwt = max(mxwt,pwt+cwt);
            pwt = cwt;
            if(!q.empty()){

                q.push(-1);
            }
        }else{
            cwt += wt[f];
            For(i,0,ch[f].size()){
                if(!v[ch[f][i]]){
                    q.push(ch[f][i]);
                    v[ch[f][i]] = true;
                }
            }
        }
        
    }
    return mxwt;
}

class StonesOnATreeDiv2 {
    public:
    // int p[55] = {}, z[55] = {}, e[55] = {};
    // int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]); }
    int minStones(vector <int> p, vector <int> w){
        For(i,0,w.size()){
            wt[i] = w[i];
        }    
        For(i,0,p.size()){
            ch[p[i]].push_back(i+1);
        }
        return bfs(0);
    }
};