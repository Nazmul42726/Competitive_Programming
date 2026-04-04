#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 998244353;
const int mxN = 3e5+10;

vector<int> fact(mxN);
vector<int> invFact(mxN);
vector<int> spf(mxN);

void makeSieve(){
    iota(spf.begin(), spf.end(), 0);
    
    for(int i=2; i*i < mxN; i++){
        if(spf[i] == i){
            for(int j=i*i; j < mxN; j+=i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}

int modularInverse(int x){
    int exp = mod-2;
    int result = 1;

    while(exp){
        if(exp & 1){
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        exp >>= 1;
    }
    return result;
}

int nCr(int n, int r){
    if(n < r) return 0;
    int result = (((fact[n] * invFact[r]) % mod) * invFact[n-r]) % mod;
    return result;
}

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<int> avail(n+1, 0);

    for(int i=0; i<n; i++){
        int cur = a[i];

        while(spf[cur] != cur){
            int curFact = spf[cur];
            avail[curFact]++;
            while(cur % curFact == 0) cur /= curFact;
        }
        if(cur > 1) avail[cur]++;
    }

    int totalSub = nCr(n, k);
    
    int result = 0;
    for(int i=2; i<=n; i++){
        if(avail[i]){
            int dsntHv = n - avail[i];
            int cntX = nCr(dsntHv, k);

            int cnt = (totalSub - cntX + mod) % mod;
            int cntr = (cnt * i) % mod;
            result = (result + cntr) % mod;
        }
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    fact[0] = fact[1] = 1;
    invFact[0] = invFact[1] = modularInverse(1);

    makeSieve();

    for(int i=2; i<mxN; i++){
        fact[i] = (fact[i-1] * i) % mod;
        invFact[i] = modularInverse(fact[i]);
    }

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        solve();
    }
    return 0;
}
