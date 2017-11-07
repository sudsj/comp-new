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
int binarySearch(int sortedArray[], int toFind, int len)
{
    // Returns index of toFind in sortedArray, or -1 if not found
    int low = 0;
    int high = len - 1;
    int mid;

    int l = sortedArray[low];
    int h = sortedArray[high];

    while (l <= toFind && h >= toFind) {
        mid = (low + high)/2;

        int m = sortedArray[mid];

        if (m < toFind) {
            l = sortedArray[low = mid + 1];
        } else if (m > toFind) {
            h = sortedArray[high = mid - 1];
        } else {
            return mid;
        }
    }

    if (sortedArray[low] == toFind)
        return low;
    else
        return -1; // Not found
}

int main()
{
    vi c;
    c.pb(1);
    cout << c.size;
    return 0;
}

vector<int> d (n, INF),  p (n);
                d[s] = 0;
                set < pair<int,int> > q;
                q.insert (make_pair (d[s], s));
                while (!q.empty()) {
                    int v = q.begin()->second;
                    q.erase (q.begin());
             
                    for (size_t j=0; j<g[v].size(); ++j) {
                        int to = g[v][j].first,
                            len = g[v][j].second;
                        if (d[v] + len < d[to]) {
                            q.erase (make_pair (d[to], to));
                            d[to] = d[v] + len;
                            p[to] = v;
                            q.insert (make_pair (d[to], to));
                        }
                    }
                }