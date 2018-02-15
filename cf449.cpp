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
long long int p;
long long int gets(int len,int n){
	if(len == 2 && n <=9 ){
		//n <=9
		return 11*((n*(n+1))/2);
	}else if(len == 4 && n <= 90){
		int k = n;long long int ans = 0;
		int n2 = k/10; //n2 += 1;
		if(n2>0) ans += ((n2*(n2+1))/2 * (1001) * 10) + n2*10*(gets(2,9));
		int r = k%10;
		if(r > 0) ans += (1001)*(n2 + 1)*r + 10*(gets(2,r-1));//k -= 90;
		return ans%p;
	}else if(len == 6 && n <= 9*9*10){
		int k = n;long long int ans = 0;
		int n2 = k/(9*10); //n2 += 1;
		if(n2>0) ans += ((n2*(n2+1))/2 * (100001) * (9*10)) + n2*10*(gets(4,9*10));
		int r = k%(9*10);
		if(r > 0) ans += (100001)*(n2 + 1)*r + 10*(gets(4,r));k -= 9*9*10;
		return ans%p;
	}else if(len == 8 && n <= 9*9*9*10){
		int k = n;long long int ans = 0;
		long long int ten = 10000001;
		long long int a = 9*9*9*10,b=9*9*10;
		
			int n2 = k/(b); //n2 += 1;
			if(n2>0) ans += ((n2*(n2+1))/2 * (ten) * (b)) + n2*10*(gets(6,b));
			int r = k%(b);
			if(r > 0) ans += (ten)*(n2 + 1)*r + 10*(gets(6,r));k -= a;
		return ans%p;
	}else if(len == 10 && n <= 9*9*9*9*10){
		int k = n;long long int ans = 0;
		long long int ten = 1000000001;
 		long long int a = 9*9*9*9*10,b=9*9*9*10;
		
			int n2 = k/(b); //n2 += 1;
			if(n2>0) ans += ((n2*(n2+1))/2 * (ten) * (b)) + n2*10*(gets(8,b));
			int r = k%(b);
			if(r > 0) ans += (ten)*(n2 + 1)*r + 10*(gets(8,r));k -= a;
		return ans%p;
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

 	long long int k,sum=0; cin >> k >> p;
 	if(k > 9){
 		sum += 11*9*5; k -= 9;if(sum >= p) sum = sum%p;

 	}else{
 		sum = 11*((k*(k+1))/2);k -= 9;if(sum >= p) sum = sum%p;

 	}
 	if(k > 0){if(sum >= p) sum = sum%p;

 		//len 4
 		if(k >= 9*10){
 			sum += (45000 + 45)*10 + 9*10*(gets(2,9));
 			k -= 90;
 		}else{
 			int n2 = k/10; //n2 += 1;
 			if(n2>0) sum += ((n2*(n2+1))/2 * (1001) * 10) + n2*10*(gets(2,9));
 			int r = k%10;
 			if(r > 0) sum += (1001)*(n2 + 1)*r + 10*(gets(2,r-1));k -= 90;
 		}
 	}
 	if(k > 0){if(sum >= p) sum = sum%p;

 		//len 6
 		if(k >= 9*9*10){
 			sum += ((4500000)%p + 45)*(9*10) + 9*10*(gets(4,9*10));
 			k -= 9*9*10;
 		}else{
 			int n2 = k/(9*10); //n2 += 1;
 			if(n2>0) sum += ((n2*(n2+1))/2 * (100001) * (9*10)) + n2*10*(gets(4,9*10));
 			int r = k%(9*10);
 			if(r > 0) sum += (100001)*(n2 + 1)*r + 10*(gets(4,r));k -= 9*9*10;
 		}
 	}
 	//len 8
 	if(k > 0){if(sum >= p) sum = sum%p;

 		//len 8 ten has 7 0's
 		long long int ten = 10000001;ten = ten%p;
 		long long int a = 9*9*9*10,b=9*9*10;//a=a*p;b = b%p;
 		if(k >= a){
 			sum += ((450000000)%p + 45)*(b) + 9*10*(gets(6,b));
 			k -= a;
 		}else{
 			int n2 = k/(b); //n2 += 1;
 			if(n2>0) sum += ((n2*(n2+1))/2 * (ten) * (b)) + n2*10*(gets(6,b));
 			if(sum >= p) sum = sum%p;

 			int r = k%(b);
 			if(r > 0) sum += (ten)*(n2 + 1)*r + 10*(gets(6,r));k -= a;
 		}
 	}
 	//len 10
 	if(k > 0){if(sum >= p) sum = sum%p;

 		//len 10 ten has 9 0's
 		long long int ten = 1000000001;ten = ten%p;
 		long long int a = 9*9*9*9*10,b=9*9*9*10;//a=a*p;b = b%p;
 		if(k >= a){
 			sum += ((45000000000)%p + 45)*(b) + 9*10*(gets(8,b));
 			k -= a;
 		}else{
 			int n2 = k/(b); //n2 += 1;
 			if(n2>0) sum += ((n2*(n2+1))/2 * (ten) * (b)) + n2*10*(gets(8,b));
 			if(sum >= p) sum = sum%p;

 			int r = k%(b);
 			if(r > 0) sum += (ten)*(n2 + 1)*r + 10*(gets(8,r));k -= a;
 		}
 	}
 	//len 12
 	if(k > 0){if(sum >= p) sum = sum%p;

 		//len 10 ten has 9 0's
 		long long int ten = 100000000001;ten = ten%p;
 		long long int a = 9*9*9*9*9*10,b=9*9*9*9*10;//a=a*p;b = b%p;
 		if(k >= a){
 			sum += ((4500000000000)%p + 45)*(b) + 9*10*(gets(10,b));
 			k -= a;
 		}else{
 			int n2 = k/(b); //n2 += 1;
 			if(n2>0) sum += ((n2*(n2+1))/2 * (ten) * (b)) + n2*10*(gets(10,b));
 			if(sum >= p) sum = sum%p;

 			int r = k%(b);
 			if(r > 0) sum += (ten)*(n2 + 1)*r + 10*(gets(10,r));k -= a;
 		}
 	}
 	if(sum >= p) sum = sum%p;
 	cout << sum;
    return 0;
}