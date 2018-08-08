#include <iostream>
#include <vector>
using namespace std;
class hashmap{
	private:
		vector < vector < pair <string,int> > > h;
		int size = 1000;
	public:
		hashmap(int hsize = 1000){
			h.resize(hsize);
			cout << "hsize is " << hsize<<"\n";
			size = hsize;
		};
		int hashf(string s){
			long long int x = 123;
			for(int i =0; i < s.length(); i++){
				x = x*5 + s[i];                             
			}
		};
		void insert(string s, int val){
			int x = hashf(s)%size;
			h[x].push_back(make_pair(s,val));
			if(h[x].size() > 1) cout << "There was a collison\n";
		};
		int find(string s){
			int x = hashf(s)%size;
			for(int i = 0; i < h[x].size(); i++){
				if(h[x][i].first == s) return h[x][i].second;
			}
			return -1;
		};
		void remove(string s){
			int x = hashf(s)%size;
			for(int i = 0; i < h[x].size(); i++){
				if(h[x][i].first == s){
					h[x].erase(h[x].begin() + i);
					break;
				}
			}
		};

};


int main(){

	#ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif


	hashmap hm(1);
	int x;
	string s;
	cin >> s >> x;
	hm.insert(s,x);
	cin >> s >> x;hm.insert(s,x);
	cin >> s >> x;hm.insert(s,x);
	cout << s << "\n";
	cout << hm.find(s);
	hm.remove(s);
	cout << hm.find("abc");
	return 0;
}