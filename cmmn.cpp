 MAXN = 100006;
vi maxt(4*MAXN),mint(4*MAXN);
vi hi(MAXN,0),hf(MAXN, 0);
 
 void buildmax(long long int node, long long int left, long long int right) {
    if (left == right) {
        maxt[node] = hf[left];
    } else {
        long long int tm = (left + right) / 2;
        buildmax( node*2, left, tm);
        buildmax( node*2+1, tm+1, right);
        maxt[node] = max(maxt[node*2],maxt[node*2+1]);
    }
}


 
void buildmin(long long int node, long long int left, long long int right) {
    if (left == right) {
        mint[node] = hi[left];
    } else {
        long long int tm = (left + right) / 2;
        buildmin(node*2, left, tm);
        buildmin(node*2+1, tm+1, right);
        mint[node] = min(mint[node*2],mint[node*2+1]);
    }
}
 
long long int findmax(long long int node, long long int left, long long int right, long long int l, long long int r) {
    if (l > r) 
        return -1;
    if (l == left && r == right) {
        return maxt[node];
    }
    long long int tm = (left + right) / 2;
    return max(findmax(node*2, left, tm, l, min(r, tm))
           , findmax(node*2+1, tm+1, right, max(l, tm+1), r));
}
long long int findmin(long long int node, long long int left, long long int right, long long int l, long long int r) {
    if (l > r) 
        return 99999999999;
    if (l == left && r == right) {
        return mint[node];
    }
    long long int tm = (left + right) / 2;
    return min(findmin(node*2, left, tm, l, min(r, tm))
           , findmin(node*2+1, tm+1, right, max(l, tm+1), r));
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    //freopen("test.txt","r",stdin);
    long long int tt;
    cin>>tt;
    while(tt--){
        clock_t st = clock();
        long long int n;
        cin>>n;
        repA(i,0,n-1)cin>>hi[i];
        repA(i,0,n-1)cin>>hf[i];
        mii m;
        unordered_map<ll,vi> mp;
        long long int f=1;
        repA(i,0,n-1){
            hi[i]-=hf[i];
            if(hi[i]<0){
                cout<<-1<<endl;
                f=0;
                break;
            }
        }
        if(!f)continue;
        buildmax(1,0,n-1);
        buildmin(1,0,n-1);
        
        repA(i,0,n-1){
            if(hi[i]){
                m[hf[i]]++;
                mp[hf[i]].pb(i);    
            }
        }
        repA(i,0,n-1){
            hi[i]+=hf[i];
        }
        
        long long int ans=0;
        for(auto i:m){
            if(i.se >1){
                repA(j,1,i.se-1){
                    if(findmax(1,0,n-1,mp[i.fi][j-1],mp[i.fi][j])>i.fi || findmin(1,0,n-1,mp[i.fi][j-1],mp[i.fi][j])<i.fi)
                        ans++;
                    
                }
            }
            ans++;
        }
        if(m[0])ans--;
         cout<<ans<<endl;
        clock_t end = clock();
        //cout << (double)(end - st)/CLOCKS_PER_SEC << endl;
 
    }