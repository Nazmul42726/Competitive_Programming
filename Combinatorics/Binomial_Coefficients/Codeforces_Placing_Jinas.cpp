#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;
const ll mx = 1e6+10;

vector<ll> fact(mx), invFact(mx);

ll modularInverse(ll a){
    ll exp = mod - 2;
    ll result = 1;
    while(exp){
        if(exp % 2) result = (result * a) % mod;
        a = (a * a) % mod;
        exp /= 2;
    }
    return result;
}

ll nCr(ll n, ll r){
    if(n<r) return 0;
    ll result = fact[n];
    result = (result * invFact[r]) % mod;
    result = (result * invFact[n-r]) % mod;
    return result;
}

void solve(){
    ll n;
    cin>>n;
    
    ll result = 0;
    for(ll k=0; k<=n; k++){
        ll m;
        cin>>m;
        result = (result + nCr((m-1+k)+1,k+1))%mod;
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    fact[0] = 1;
    for(ll i=1; i<mx; i++) fact[i] = (fact[i-1] * i) % mod;
    for(ll i=0; i<mx; i++) invFact[i] = modularInverse(fact[i]);

    solve();
    
    return 0;
}
