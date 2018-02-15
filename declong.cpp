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
int mint(int x,int y,int z){
	int min1 = min(x,y);
	return min(min1,z);
}
int a,b,c;
int f1(int bxy,int byz, int bzx,int ax){
	int ay=0,az=0,cxyz=0;int flag = 0;
	//123 order
	if(3*b > 2*c){flag = 1;
		cxyz = mint(bzx,byz,bxy);
		bxy -= cxyz;byz -= cxyz;
	 	bzx -= cxyz;
	 }
 	//now 2b to a+C
	 if(2*b > a+c){
	 	if(flag){
	 		//one of b's is 0
	 		std::vector<int> v;
	 		int check = a+b-c;
	 		if(check > 0 && byz != 0 && ax != 0){
	 			ax = 0;
	 			byz -= 1;
	 			cxyz += 1;
	 		}
 			v.push_back(bzx);v.push_back(byz);v.push_back(bxy);
 			sort(v.begin(), v.end());
 			if(bxy == 0){
 				int minn = min(byz,bzx);
 				cxyz += minn;
 				az += minn;
 				byz -= minn;
 				bzx -= minn;
 			}else if(bzx == 0){
 				int minn = min(byz,bxy);
 				cxyz += minn;
 				ay += minn;
 				byz -= minn;
 				bxy -= minn;
 			}else{//byz = 0
 				int minn = min(bzx,bxy);
 				cxyz += minn;
 				ax += minn;
 				bzx -= minn;
 				bxy -= minn;
 			}

	 	}else{
	 		//a+b to c is not possible
	 		//DOING 2B TO A+C
	 		//all 3 are filled to some extent
	 		std::vector<int> v;
	 		v.push_back(bzx);v.push_back(byz);v.push_back(bxy);
	 		sort(v.begin(), v.end());
	 		if(v[2] >= v[1]+v[0]){
	 			//doesnt matter what cordinates you put
	 			// as they are not used anywhere else
	 			bzx = 0;
	 			byz = 0;
	 			cxyz += v[0] + v[1];
	 			az += v[0] + v[1];
	 			bxy = v[2] - v[0] - v[1];
	 		}else{
	 			int dif = v[2] - v[1];
	 			//dif < v[0]
	 			v[0] -= dif;
	 			// bzx += dif;
	 			v[2] -= dif;
	 			az += dif;
	 			cxyz += dif;
	 			//now v2 and v1 equal
	 			int hf = v[0]/2;
	 			v[2] -= hf;
	 			v[1] -= hf;
	 			az += 2*hf;
	 			cxyz += 2*hf;
	 			// bxy += hf;
	 			// bzx += hf;
	 			bxy = v[0] - 2*hf;//either 0 or 1
	 			//v2 and v1 are equally left

	 			cxyz += v[2];
	 			az += v[2];
	 			bzx = 0;byz=0;
	 		}
	 	}
	 }else{
	 	if(a+b > c){
	 		int check = a+b-c;
	 		if(check > 0 && byz != 0 && ax != 0){
	 			ax = 0;
	 			byz -= 1;
	 			cxyz += 1;
	 		}
	 	}else{
	 		//no 3d substitution is needed NOTHING to do
	 	}

	 }
	 return b*(bzx + bxy + byz) + a*(ax+ay+az)+c*cxyz;
}
int main()
{
    // #ifndef ONLINE_JUDGE
 	  //   freopen("input.txt", "r", stdin);
 	  //   freopen("output.txt", "w", stdout);
    // #endif

 	tests{
 		int x,y,z;
 		cin >> x >>	y>>z>>a>>b>>c;
 		int ax=0,ay=0,az=0,bxy=0,byz=0,bzx=0,cxyz=0;
 		if(b >= 2*a){
 			//2-d motion is useless
 			if(c >= 3*a){
 				//3d is useless
 				cout << a*(x+y+z)<<"\n";
 			}else{
 				//use 3d wherever possible
 				int min1 = min(x,y);
 				int min2 = min(z,min1);
 				cout << a*(x+y+z - 3*min2) + c*min2 <<"\n";
 			}
 		}else{
 			//2d useful
 			//calc in terms of 2d and 1d 
 			std::vector<int> v;int flag = 0;
 			v.push_back(x);v.push_back(y);v.push_back(z);
 			sort(v.begin(), v.end());
 			//x-0y-1z-2
 			if(v[2] >= v[1]+v[0]){flag = 1;
 				bzx = v[0];
 				byz = v[1];
 				az = v[2] - v[0] - v[1];
 			}else{
 				int dif = v[2] - v[1];
 				//dif < v[0]
 				v[0] -= dif;
 				bzx += dif;
 				v[2] -= dif;
 				//now v2 and v1 equal
 				int hf = v[0]/2;
 				v[2] -= hf;
 				v[1] -= hf;
 				bxy += hf;
 				bzx += hf;
 				ax += v[0] - 2*hf;//either 0 or 1
 				//v2 and v1 are equally left
 				byz += v[2];
 			}
 			//now one-d and two-d done
 			//so try to insert 3-d things
 			//ay is 0
 			if(flag){
 				//only bzx,byz,az
 				//now we consider 3d as well
 				//replace bzx+byz <=> cxyz + z
 				if(a+c < 2*b){
 					int min3 = min(bzx,byz);
 					bzx -= min3;
 					byz -= min3;
 					cxyz += min3;
 					az += min3;
 					int ans = a*az + b*(bzx + byz) + c*cxyz;
 					cout << ans << "\n";
 				}else{
 					int ans = a*az + b*(bzx + byz) ;
 					cout << ans << "\n";
 				}
 			}else{
 				if(c >= 3*a){
 					int anss = b*(bzx + bxy + byz) + a*ax;
 					cout << anss << "\n";
 				}else{
 					int ansss = f1(bxy,byz,bzx,ax);
 					cout << ansss << "\n";
 				}
 			}
 			
 		}
 	}    
    return 0;
}