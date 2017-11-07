#include <bits/stdc++.h>
using namespace std;

std::pair<int,std::set<int>> a[2501];
int n,k;
long long int ans = 0;


int kbig(int m,int n,int k) {
    // if(index == n)return ksmall(n,k);
    ans = 0;
    for(int i = n-1;i >=m;i--) {
        for(int j = i-1;j >= 0;j--) {
            int flag = 1;
            if((a[i].first+a[j].first) < k)continue;
            for(int f = 1;f <= k;f++) {
                if((a[i].second.find(f) !=a[i].second.end())||(a[j].second.find(f) !=a[j].second.end()))
                    continue;
                else {flag = 0;break;}
            }
            if(flag == 1)ans++;
        }
    }
    return ans;

}

int ksmall(int n,int k) {
    // cout<<"in ksmall "<<n<<endl;
    ans = 0;
    for(int i = 0;i < n;i++) {
        // cout<<"i is "<<i<<endl;
        for(int j = i+1;j < n;j++) {
            int flag = 1;
            if((a[i].first+a[j].first) < k)continue;
            for(int f = 1;f <= k;f++) {
                if((a[i].second.find(f) !=a[i].second.end())||(a[j].second.find(f) !=a[j].second.end()))
                    continue;
                else {flag = 0;break;}
            }
            if(flag == 1)ans++;
        }
    }
    return ans;
}

int main() {
	int t,n,k;
	int x;
	cin>>t;
	while(t--) {
	   // cout<<"t is"<<t<<endl;
	    ans = 0;
	    cin>>n>>k;
	   // cout<<"n is "<<n<<" k is "<<k<<endl;
	    for(int i = 0;i < n;i++) {
	        cin>>a[i].first;
	        a[i].second.clear();
	        for(int j = 0;j < a[i].first;j++) {
	            cin>>x;
	            a[i].second.insert(x);
	        }
	    }

	    sort(a,a+n);

	    if(k>100){
	        int index = n;
	        for(int i = 0; i < n;i++) {
	            if(a[i].first >= 50) {
	                index = i;
	                break;
	            }
	        }
	        cout<<kbig(index,n,k)<<endl;
	    }
	    else cout<<ksmall(n,k)<<endl;


	}
	return 0;
}
