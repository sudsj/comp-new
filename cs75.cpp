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
// #define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
/////////////////////////////////////////////////////////////////////

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);


    int n,x,y; cin >> n >> x >> y;
    std::vector<int> v(n);
    std::vector<int> d(n);
    std::vector<double> t(n);
    std::vector<double> tinc(n);
    std::vector<double> tred(n);
    double dist,speed,sinc,sred;
    For(i,0,n){
    	cin >> d[i] >> v[i];
    	dist = d[i]*1.0;
    	speed = v[i]*1.0;
    	t[i] = dist/speed;
    	// Debug(t[i])
    	sinc = speed + x*1.0;
    	sred = speed - y*1.0;
    	tinc[i] = dist/sinc;
    	tred[i] = dist/sred;
    }
 	std::vector< pair < double,int> > st(n);
    // std::vector<double> tinc(n);
    std::vector< pair < double,int> > stred(n);   	
    For(i,0,n){
    	st[i].first = t[i];
    	// Debug(st[i].first)
    	st[i].second = i;
    	stred[i].second = i;
    	stred[i].first = tred[i];
    }
    sort(st.begin(),st.end());
    sort(stred.begin(),stred.end());
 	vector<int> rk(n);
 	// Debug(st[0].first)
        // Debug(st[3].first)
 	For(i,0,n){
 		//with incresed speed;
 		std::vector< pair < double,int> >::iterator it,its;
 		it = std::lower_bound(st.begin(), st.end(), tinc[i], [](std::pair < double,int> const & x, double d)
          { return x.first < d; });
        int pos = it - st.begin();
        int rank;
        // Debug(tinc[i])
        if(st[pos].first > tinc[i]){
            rank = pos;
        }else{
            //equal
            // Debug(pos)
            if(st[pos].second < i || pos >= n){
                rank = pos+1;//Debug(pos)
            }else rank = pos;
        }
        
        //reduce other's speed
        it = std::lower_bound(stred.begin(), stred.end(), t[i], [](std::pair < double,int> const & x, double d)
          { return x.first < d; });
        pos = it - stred.begin();
        int rank2;
        if(stred[pos].first > tinc[i]){
            rank2 = pos;
        }else{
            //equal
            if(stred[pos].second < i || pos >= n){
                rank2 = pos+1;
            }else rank2 = pos;
        }
        // Debug(rank)
        // Debug(rank2)
        rk[i] = min(rank,rank2);
        cout <<rk[i]+1 << "\n";
 	}
    
    return 0;
}