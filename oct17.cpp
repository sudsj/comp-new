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
//#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
/////////////////////////////////////////////////////////////////////
static struct IO {
    char tmp[1 << 10];
 
    // fast input routines
    char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }
 
    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
    inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }
 
    inline IO& operator >> (string & s) {
        if (skipBlanks()) { s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }
 
    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this; }
 
#define defineInFor(intType) \
    inline IO& operator >>(intType & n) { \
        if (skipBlanks()) { \
            int sign = +1; \
            if (peekChar() == '-') { \
                sign = -1; \
                n = nextChar() - '0'; \
            } else \
                n = peekChar() - '0'; \
            while (!isBlank(nextChar())) { \
                n += n + (n << 3) + peekChar() - 48; \
            } \
            n *= sign; \
        } \
        return *this; \
    }
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
    // fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
    inline char * toString(intType n) { \
        char * p = (tmp + 30); \
        if (n) { \
            bool isNeg = 0; \
            if (n < 0) isNeg = 1, n = -n; \
            while (n) \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg) *--p = '-'; \
        } else *--p = '0'; \
        return p; \
    } \
    inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
 
int main()
{
    
tests{
        int n,q;
        cin >> n >> q;
        std::vector<int> v[n+1],p[n+1],led[n+1],red[n+1],cumwt[n+1];
        int ns,t;
        int numnodes[n+1];
        //int cumwt[n+1];
        For(i,1,n+1){
            cin >> ns;
            numnodes[i] = ns;
            v[i].push_back(-1);//just to fill 0th position
            cumwt[i].push_back(0);//cumwt[i].push_back(0);
            For(j,1,ns+1){
                cin >> t;
                v[i].push_back(t);//i from 1 to n
                 cumwt[i].push_back(cumwt[i][j-1] + t);
            }
        }
        int v1,v2,w;
        int linkwts[n+1];
        For(i,1,n){
            cin >> v1 >> v2 >> w;
            //v1 is i's right exit and v2 is i+1's left exit
            p[i].push_back(v1);
            p[i+1].push_back(v2);
            linkwts[i] = w;//stores link weight between i and i+1
        }
        //for the last i == n v1 is n's right and 1's left 
        //each node filled with left first and then right except 1
        cin >> v1 >> v2 >> w;
        p[n].push_back(v1);
        p[1].push_back(v2);
        
        linkwts[n] = w;
        //make 1 left first
        t = p[1][0]; p[1][0] = p[1][1]; p[1][1] = t;
        //precompute distances to left and right nodes
        int lexit,rexit,d1,d2;
        For(i,1,n+1){
            led[i].push_back(-1);
            red[i].push_back(-1);
            For(j,1,numnodes[i]+1){
                //go thru all nodes and store distances to left and right exit nodes
                //j from 1 to numnodes[i]
                //calc leftd
                //to make index start from 1
                
                lexit = p[i][0];
                if(lexit < j){
                    d1 = 0;
                    //For(k,lexit,j) d1 += v[i][k];
                    d1 += cumwt[i][j-1] - cumwt[i][lexit-1];
                    d2 = 0;
                    //For(k,j,numnodes[i]+1) d2 += v[i][k];
                    d2 += cumwt[i][numnodes[i]] - cumwt[i][j-1];
                    //For(k,1,lexit) d2 += v[i][k];
                    d2 += cumwt[i][lexit-1] - cumwt[i][0];
                    led[i].push_back(min(d1,d2));
                }else if(lexit > j){
                    d1 = 0;
                    //For(k,j,lexit) d1 += v[i][k];
                    d1 += cumwt[i][lexit-1] - cumwt[i][j-1];
                    d2 = 0;
                    //For(k,lexit,numnodes[i]+1) d2 += v[i][k];
                    d2 += cumwt[i][numnodes[i]] - cumwt[i][lexit-1];
                    //For(k,1,j) d2 += v[i][k];
                    d2 += cumwt[i][j-1] - cumwt[i][0];
                    led[i].push_back(min(d1,d2));
                }else led[i].push_back(0);
                rexit  = p[i][1];
                if(rexit < j){
                    d1 = 0;
                    //For(k,rexit,j) d1 += v[i][k];
                    d1 += cumwt[i][j-1] - cumwt[i][rexit-1];
                    d2 = 0;
                    //For(k,j,numnodes[i]+1) d2 += v[i][k];
                    d2 += cumwt[i][numnodes[i]] - cumwt[i][j-1];
                    //For(k,1,rexit) d2 += v[i][k];
                    d2 += cumwt[i][rexit-1] - cumwt[i][0];
                    red[i].push_back(min(d1,d2));
                }else if(rexit > j){
                    d1 = 0;
                    //For(k,j,rexit) d1 += v[i][k];
                    d1 += cumwt[i][rexit-1] - cumwt[i][j-1];
                    d2 = 0;
                    //For(k,rexit,numnodes[i]+1) d2 += v[i][k];
                    d2 += cumwt[i][numnodes[i]] - cumwt[i][rexit-1];
                    //For(k,1,j) d2 += v[i][k];
                    d2 += cumwt[i][j-1] - cumwt[i][0];
                    red[i].push_back(min(d1,d2));
                }else red[i].push_back(0);
                //cout << "node" << i << "vertex" << j << "\n";
                //Debug(red[i][j]) Debug(led[i][j])
            }

        }
        int ldist[n+1];
        ldist[0] = 0; 
        ldist[1] = 0;
        //dist i stores from 1's left to i's left node
        //now store distances from left of 1st to rest of the nodes
        For(i,2,n+1){
            ldist[i] = ldist[i-1];
            ldist[i] += red[i-1][p[i-1][0]];//leftd to right dist
            ldist[i] += linkwts[i-1];
        }
        int nto1dist = red[n][p[n][0]] + linkwts[n];//dist from n's left to 1's left

        int rdist[n+1];//dist from 1's right to i's right node
        rdist[0] = 0;
        rdist[1] = 0;
        For(i,2,n+1){
            rdist[i] = rdist[i-1] + linkwts[i-1] + red[i][p[i][0]];//add link + left to right distance of i
        }
        //NOW WE TAKE QUERIES
        int c1,c2;
        For(i,0,q){
            cin >> v1 >> c1 >> v2 >> c2;
            //assume c1 < c2
            if(c1 > c2){
                swap(v1,v2); 
                swap(c1,c2);
            }
           //cout << "Go from node " << c1 << " 's " << v1 <<" vertex to "<<c2<<" 's "<< v2<<"\n";
            //calc dist c1 to c2 from right first and then from left
            d1 = 0;//right dist 
            //Debug(d1) 
            //go to right exit of c1 and then to left exit of c1 + 1 (right neighbour)
            //Debug(c1) Debug(v1) Debug(red[c1][v1])
            
            d1 += red[c1][v1];//Debug(d1) 
            d1 += linkwts[c1];//no we are at left exit of c1 + 1;
            //Debug(d1) 
            d1 += ldist[c2] - ldist[c1+1];//go from left of c1+1 to c2
            //Debug(d1) 
            d1 += led[c2][v2];//go from left exit of c2 to v2
            //Debug(d1) 
            //left dist
            d2 = 0;
            d2 += led[c1][v1];
            //now we have to reach 1's left exit first
            if(c1 != 1){
                d2 += linkwts[c1 - 1];//go to left node's right exit
                d2 += rdist[c1-1];//now we are at 1's right node
                d2 += led[1][p[1][1]];//dist from 1's right exit to left exit
            }
            d2 += linkwts[n];//we reach n's right
            d2 += rdist[n] - rdist[c2];//we reach c2's right node
            d2 += red[c2][v2];//dist from c2's right exit to v2
            //Debug(d1) Debug(d2)
            cout << min(d1,d2) << "\n";
        }
        //DEBUG HERE
        //DebugArr(rdist,n+1)
        //DebugArr(red[1],4)
        //DebugArr(numnodes,n+1)
        //Debug(p[1][1])// Debug(p[1][0])
    }
    return 0;
}
 