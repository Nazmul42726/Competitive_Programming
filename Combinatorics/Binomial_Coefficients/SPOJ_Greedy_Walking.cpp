#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;
const ll mx = 1e6+10;

vector<ll> fact(mx), invFact(mx);

void extendedEuclidean(ll a, ll b, ll& x, ll& y){
    if(b==0){
        x=1,y=0;
        return;
    }
    ll x1,y1;
    extendedEuclidean(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
}

ll modularInverse(ll a){
    ll x,y;
    extendedEuclidean(a, mod, x, y);
    x = (x%mod + mod) % mod;
    return x;
}

void solve(ll n){
    vector<ll> diff(n);

    ll moveCnt = 0;
    for(ll i=0; i<n; i++) cin>>diff[i];
    for(ll i=0; i<n; i++){
        ll x; cin>>x;
        diff[i] = x-diff[i];
        moveCnt += diff[i];
    }

    ll result = fact[moveCnt];
    for(ll i=0; i<n; i++)
        result = (result * invFact[diff[i]]) % mod;
    
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    fact[0] = 1;
    for(ll i=1; i<mx; i++) fact[i] = (fact[i-1] * i) % mod;
    for(ll i=0; i<mx; i++) invFact[i] = modularInverse(fact[i]);

    while(1){
        ll n;
        cin>>n;
        if(n==0) break;
        solve(n);
    }
    return 0;
}
