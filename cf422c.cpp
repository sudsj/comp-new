#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#if DEBUG && !ONLINE_JUDGE
    #include "/home/raghukul/Competetive/Templetes/debug.h"  
#else
    #define debug(args...) 
    #define DBG(x...)
#endif
 
int main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.precision(17);
    int n,x;
    cin >> n >> x;
    int a,b,cost;

    vector<pair<int,pair <int,int> > > m[200005];
    vector<pair<pair<int,int>,pair<int,int> > > G;

    for(int i = 0;i < n;i++) {
    	cin >> a >> b >> cost ;
       	m[b-a+1].push_back(make_pair(a,make_pair(cost,b)));
       	G.push_back(make_pair(make_pair(b-a+1,cost),make_pair(a,b)));
    }
    for(int i = 0;i < 200005;i++)
    	sort(m[i].begin(),m[i].end());
    sort(G.begin(),G.end());

    int ans = 2*1e9 + 2;
    int duration=-1;
    for(int i = 0;i < n;i++) {
    	if(G[i].first.first > x)
    		break;
    	int sec = x - G[i].first.first,mcost=INT_MAX;
    // 	cout << G[i].second.first <<" is start date\n";
    	if(duration != G[i].first.first){
    		duration = G[i].first.first;
    // 		cout << duration << " is duration\n";
    		for( auto j = m[sec].rbegin(); j != m[sec].rend(); ++j) {
    			mcost = min(j->second.first,mcost);
    			j->second.second = mcost;
    // 			cout << mcost<<"is mcost\n";
    		}
    	}
    	
    	//now find index
    	int minstart = G[i].second.second;
    	auto it2 = upper_bound(m[sec].begin(), m[sec].end(), minstart,[](int second, const std::pair<int,pair <int,int> >& p) {
      return p.first < second;
    });
    	if(it2 == m[sec].end()) continue;
    	while(it2->first == minstart){
    	  it2++;
    	  if(it2 == m[sec].end()) break;
    	} 
    	if(it2 == m[sec].end()) continue;
    	ans = min(ans, it2->second.second + G[i].first.second);
    // 	cout << "ans is " << ans<<"\n";
    // 	cout << it2->second.second << " is second trip's cost\n";
    // 	cout << G[i].first.second << " first trip cost\n";
    	
    	// for(auto j = m[sec].rbegin(); j != m[sec].rend(); ++j) {
    	// 	if(j.second.first > G[i].second.second || 
    	// 			G[i].second.first > j.second.second) {
    	// 		ans = min(ans,G[i].first.second + j.first);
    	// 		break;
    	// 	}
    	// }

    }


    if(ans == 2*1e9 + 2)
    	cout << -1 << endl;
    else
    	cout << ans;
    return 0;
}