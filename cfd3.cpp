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
int count(vector<int> &A, int start, int end){
    if(end <= start) return 0;
    if(end - start == 1){
        if(A[end] < A[start]){
            swap(A[end],A[start]);
            return 1;
        }else return 0;
    }
    // cout << start << " is start and end = " << end << "\n";
    //
    int mid = (end+start)/2;
    // cout << "mid is " << mid << "\n";
    int ct = count(A,start,mid) + count(A,mid+1,end);
    //merge the halves
    int lsize = mid - start + 1;int rsize = end - mid;
    vector<int> v(end-start+1,0);
    for(int i = start; i <= end; i++){
        v[i-start] = A[i];
    }
    // cout << start << " is start and end = " << end << "\n";
    // Debug(lsize) Debug(rsize)
    int left = 0, right = 0;int cur = start;
    while(left < lsize && right < rsize){
        if(v[left] < v[right+lsize]){
            A[cur] = v[left];
            left++;cur++;
        }else{
            A[cur] = v[right+lsize];
            // Debug(cur)
            // Debug(A[cur])
            right++;cur++;
            ct += lsize - left;
        }
    }
    while(left < lsize){
        A[cur] = v[left];
        left++;cur++;
    }
     while(right < rsize){
        A[cur] = v[right+lsize];
        right++;cur++;
    }
    // cout << start << " is start and end = " << end << "\n";
    // cout << ct << " is ct\n";
    return ct;
}
int countInversions(vector<int> &A) {
    int n = A.size();
    int ct = count(A,0,n-1);
    // for(int i = 0; i < n; i++) cout << A[i] << "= A[i]\n";
    return ct;
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n; cin >> n;
    std::vector<int> v(n);
    For(i,0,n) cin >> v[i];
    cout << countInversions(v);


    ///////////
    return 0;
}