#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;
const ll mx = 10000+10;

vector<ll> fact(mx),invFact(mx);

ll modularInverse(ll a){
    ll exp = mod-2;
    ll result = 1;
    while(exp){
        if(exp % 2) result = (result * a)%mod;
        a = (a*a)%mod;
        exp /= 2;
    }
    return result;
}

ll nCr(ll n, ll r){
    return (fact[n] * ((invFact[r]*invFact[n-r])%mod))%mod;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0);
    for(ll i=1; i<=n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    ll totalSubset = nCr(n,k);
    ll result = 0;

    for(ll i=n; i>k; i--){
        ll ithMaxIn = totalSubset - nCr(i-1,k);
        totalSubset -= ithMaxIn;
        result = (result + ((ithMaxIn * a[i])%mod))%mod;
    }
    result = (result + (totalSubset * a[k]))%mod;
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    fact[0] = 1;
    for(ll i=1; i<mx; i++) fact[i] = (fact[i-1]*i)%mod;
    for(ll i=0; i<mx; i++) invFact[i] = modularInverse(fact[i]);

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
