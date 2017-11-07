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
    tests{
        int n;
        cin >> n;
        int q;
        cin >> q; int x,y,v;
        std::vector<int> e[n+1]; std::vector<int> d[n+1]; int ad[n+1]={0};set<int> ds[n+1];//difference set
        set<int> s[n+1]; int ae[n+1]={0};int st=0,stn=0,stf=0;//stn is set no. filled up
        //stf is final sets
        //ae[x] stores the equal set no. to which a[x] belongs
        int difn=0,//no. of 1 difference pairs
        std::vector< pii > df; pair<int,int> p;
        For(i,0,q){
            cin >> x >> y >> v;
            st = 0;
            if(v == 0){
                //equal
                if(ae[x] != 0){
                    //x already in an equal set
                    st = ae[x];
                    s[st].insert(y);
                    if(ae[y] != 0){
                        //y already in a set
                        if(st != ae[y]){
                            //merge sets ae[y] and st
                            for(auto its = s[ae[y]].begin(); its != s[ae[y]].end(); ++its){
                                ae[*its] = st;
                                //updated the set no. for the new elements after merge
                            }
                            s[st].insert(s[ae[y]].begin(), s[ae[y]].end());
                        }
                        s[ae[y]].clear();
                        ae[y] = st;
                    }
                }else{
                    //x not in any set
                    if(ae[y] != 0){
                        //y already in a set
                        st = ae[y];
                        s[st].insert(x);
                        ae[x] = st;
                    }else{
                        //none in any set
                        stn++;
                        s[stn].insert(x);
                        s[stn].inset(y);
                        ae[x] = stn;
                        ae[y] = stn;
                    }
                }
            }else{
                //for difference
                p.first = x;
                p.second = y;
                df.push_back(p);
                //ds[x].insert(y);
                difn ++;
                //ds[y].insert(x);
                //for any member of difference set x say z then set x and set z should not have any common element i.e. they should be disjoint
                
            }
        }
        //input done
        std::vector<int> ind;//stores set indices
        For(i,1,stn+1){
            if(s[i].size() > 0){
                ind.push_back(i);
                stf ++;
            }
        }
        set<int> even;set<int> odd; int flag = 0;
        For(i,0,difn){
            x = df[i].first;
            y = df[i].second;
            if(ae[x] != 0){
                //x already in an equal set
                if(ae[y] != 0){
                    if(ae[y] == ae[x]){
                        flag = 1;
                        goto brk;
                    }
                }else{
                    //y not in a set
                    stn ++;
                    ae[y] = stn;
                    ind.push_back(stn);
                }
            }else{
                //x not in a set
                stn ++;
                ae[x] = stn;
                ind.push_back(stn);
                if(ae[y] == 0){
                    stn ++;
                    ae[y] = stn;
                    ind.push_back(stn);
                }
            }
            //now x and y in some equal set
            even.insert(ae[x]);
            
        }
        brk : ;


}
    return 0;
}