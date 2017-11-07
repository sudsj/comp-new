#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
using namespace std;

long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}


int T;
int n,k;
int p2index[1300300];
bool vis[50];
int main(){
	for(int i=0;i<(1<<20);i++){
		p2index[i]=-1;
	}
	for(int i=0;i<20;i++){
		p2index[1<<i]=i;
	}
	T=readIntLn(1,10);
	int sm_n=0;
	while(T--){
		n=readIntSp(1,100000);
		sm_n+=n;
		assert(sm_n<=100000);
		k=readIntLn(1,20);
		for(int i=0;i<k;i++){
			vis[i]=false;
		}
		for(int i=0;i<n;i++){
			int x;
			if(i==n-1){
				x=readIntLn(0,(1<<k)-1);
			} else {
				x=readIntSp(0,(1<<k)-1);
			}
			if(p2index[x]!=-1){
				vis[p2index[x]]=true;
			}
		}
		int sol=0;
		for(int i=0;i<k;i++){
			if(!vis[i])sol++;
		}
		cout<<sol<<endl;
	}
	assert(getchar()==-1);
}