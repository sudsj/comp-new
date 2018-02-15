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
int da[20] = {0};
int f[20] = {0};
int db[20] = {0};
int la=0,lb=0;

void dg(long long int n){
	int i = 0;
	while(n != 0){
		da[i] = n%10;
		n = n/10;
		i++;
		la++;
	}
}
void dgb(long long int n){
	int i = 0;
	while(n != 0){
		db[i] = n%10;
		n = n/10;
		i++;
		lb++;
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif
 	    
 	long long int a,b;
 	cin >> a >> b;
 	dg(a);dgb(b);
 	sort(da,da+la);
 	//Debug(da[2])
 	//Debug(lb)
 	//Debug(la)
 	int lena = la;
 	if(lb > la){//Debug(lena)
 		int i = 0,j;
 		for( j = lena-1;j>=0;j--){
 			f[i] = da[j];i++;
 		}
 	}else{
 		int iflag = 0,gm=0;
 		int ib = lb-1;
 		For(i,0,lena){
 			if(gm == 1){
 				//get min for this
 				iflag = 0;
 				for( int j = la-1;j>=0;j--){
 					if(da[j] >= db[ib]){
 						continue;
 					}else{
 						f[i] = da[j];
 						iflag = 1;gm=0;
 						
 						ib--;
 						da[j] = 100;
 						sort(da,da+la);
 						la--; 
 						break;
 					}
 				}
 				if(iflag == 0){
 					i -= 2;//go back and get min
 				}

 			}
 			int j,flag=0;iflag=0;gm=1;//gm means get min 

 			for( j = la-1;j>=0;j--){
 				if(da[j] > db[ib]){
 					continue;
 				}else{//Debug(da[j]) Debug(j)
 					f[i] = da[j];iflag = 1;gm=0;
 					if(da[j] < db[ib])flag = 1;
 					ib--;
 					da[j] = 100;
 					sort(da,da+la);
 					la--; 
 					break;
 				}
 			}
 			//if iflag == 0 then go back
 			if(iflag == 0){Debug(i)
 				i -= 2;
 			}
 			if(flag == 1){
 				//just put it 
 				j = la-1;
 				For(m,i+1,lena){
 					f[m] = da[j];
 					j--;
 				}
 				break;
 			}
 		}
 	}
 	
 	// if(lena == lb){
 	// 	For(i,0,lb){
 	// 		if(f[i] != db[lb-1-i]) iflag = 1;
 	// 	}
 	// 	if(iflag == 0){
 	// 		//both are same
 	// 		for(int i = lena - 2; i >= 0; i--){
 	// 			int mins = -100,indj;
 	// 			For(j,i+1,lena){
 	// 				if(f[j] < f[i]) {mins = max(mins,f[j]); if(mins == f[j]) indj = j;}
 	// 			}

 	// 			if(mins > 0){
 	// 				swap(f[i],f[indj]);
 	// 				// swap()
 	// 			 break;}
 	// 		}
 	// 	}
 	// }
 	
 	For(i,0,lena){
 		cout << f[i];
 	}
 	
 	return 0;
}