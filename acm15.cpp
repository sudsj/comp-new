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
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
 
 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 
 
151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
 
 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 
 
313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
 
 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 
 
491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 
 
599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677,
 
 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 
 
787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881,
 
 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    int main()
    {
        std::vector<int> p; int ps = sizeof(primes)/sizeof(primes[0]);
        For(i,0,ps) p.push_back(primes[i]);
        tests{
            int n; cin >> n;int a[n];
            set <int> s;
            For(i,0,n) cin >> a[i];
            long long int ans = 1; int t;int j;
            For(i,0,n){
                cin >> t; j = 0;
                while(t != 1 || j < ps){
                    if(t%primes[j] == 0) t /= primes[j];
                    s.insert(primes[j]);
                    
                }
                if(t != 1){
                    //t is prime > 1000
                    s.insert(t);
                }
            }
            ans = 1;
            std::set<int>::iterator it;
            for (it = s.begin(); it != s.end(); ++it)
            {
                ans *= *it;
                if(ans > mod) ans = ans%mod;
            }
            cout << ans << "\n";
        } 
        return 0;
    }
