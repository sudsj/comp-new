#include <bits/stdc++.h>
#define Debug(x) cout << "> " << #x << " : " << x << "\n";
using namespace std;

typedef long long int ll;
#define MAXN 200001LL
#define MOD 1000000007LL
ll ncr[MAXN];
ll ans[MAXN];

ll gcd(ll x, ll y){
    if(x == 0)return y;
    return gcd(y%x,x);
}

ll modexp(ll y, ll p){
    if(p == 0)return 1;
    if(p%2 == 0)return modexp((y*y)%MOD , p/2);
    return (y*modexp((y*y)%MOD, (p-1)/2))%MOD;
}

ll modinv(ll x, ll y){
    ll d = modexp(y%MOD,MOD-2);
    ll ans = ((x%MOD * d%MOD)%MOD);
    return ans;
}

ll inv(ll x){
    if(x == 1)return 1;
    ll d = modexp(x%MOD,MOD-2);
    return d%MOD;
}

void pre(ll k){
    ll good[MAXN];
    ll fact[MAXN];
    ll c1[MAXN];
    ll inve[MAXN];
    fact[0] = 1;
    for(int i=1;i<MAXN;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    for(int i=0;i<MAXN;i++){
        inve[i] = (inv(fact[i]))%MOD;
    }
    for(int i=1;i<MAXN;i++){
        if(i<k)ncr[i] = 0;
        else ncr[i] = ((fact[i] * inve[k])%MOD * inve[i-k])%MOD;
    }
    ll prime[MAXN];
    for(int i=1;i<MAXN;i++){
        prime[i] = 1;
    }
    for(int i=2;i<MAXN;i++){
        if(prime[i] == 1){
            for(int j=(i+i);j<MAXN;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(int i=1;i<MAXN;i++){
        good[i] = 1;
    }
    for(int i=2;i<MAXN;i++){
        if(prime[i] == 1){
            for(int j=(i+i);j<MAXN;j+=i){
                ll x = ((j/i)%i);
                if(x == 0)good[j] = 0;
            }
        }
    }
    
    ll C[MAXN];
    for(int i=1;i<MAXN;i++){
        C[i] = 0;
    }
    for(int i=2;i<MAXN;i++){
        if(prime[i] == 1){
            for(int j=i;j<MAXN;j+=i){
                C[j] = C[j]^1;
            }
        }
    }
    
    for(int i=2;i<MAXN;i++){
        if(C[i] == 1)C[i] = -1;
        else C[i] = 1;
    }
    for(int i=0;i<MAXN;i++){
        c1[i] = 0;
    }
    for(int i=2;i<MAXN;i++){
        if(good[i] == 1){
            // finds special nums
            // if(i < 5000) cout << i << "\n";
            c1[i] = (c1[i] + (C[i]*ncr[1])%MOD + 5*MOD)%MOD;
            for(int j=(i+i);j<MAXN;j+=i){
                c1[j] = (c1[j] + (C[i]*(ncr[j/i] - ncr[(j/i) - 1]))%MOD + 5*MOD)%MOD;
            }
        }
    }
    for(int i=3;i<MAXN;i++){
        c1[i] = (c1[i-1]+c1[i])%MOD;
    }
    for(int i=2;i<MAXN;i++){
        c1[i] = (c1[i] + ncr[i])%MOD;
    }
    c1[1] = ncr[1];
    // for(int i=1;i<=100;i++){
    //     cout << c1[i] << " ";
    // }
    // cout << endl;
    for(int i=1;i<MAXN;i++)ans[i]=0;
    
    for(int g=1;g<MAXN;g++){
        ans[g] = (ans[g] + (g*c1[1])%MOD)%MOD;
        for(int j=g+g;j<MAXN;j+=g){
            ans[j] = (ans[j] + ((g*c1[j/g])%MOD - (g*c1[(j/g) - 1])%MOD + 5*MOD)%MOD)%MOD;
        }
    }
    for(int i=2;i<MAXN;i++){
        ans[i] = (ans[i-1]+ans[i])%MOD;
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll q,k;
    cin >> q >> k;
    pre(k);
    for(int i=1;i<MAXN;i++){
        if(i == 1){
            if(k == 1){
                ans[i] = 1;
            }
            continue;
        }
        if(i<k){
            ans[i] = 0;
            continue;
        }
        ll x = ans[i]%MOD;
        // ll y = ncr[i]%MOD;
        // ans[i] = modinv(x,y);
        ans[i] = x;
    }
    while(q--){
        ll n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    // for(int i = 1; i <= 200000;i++){
    //     cout << i << "\n";
    // }
	return 0;
}