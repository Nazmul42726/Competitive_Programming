#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;
const ll mx = 1e6+10;

vector<ll> fact(mx), invFact(mx);

void extendedEuclidean(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x=1, y=0;
        return;
    }
    ll x1, y1;
    extendedEuclidean(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
}

ll modularInverse(ll a){
    ll x, y;
    extendedEuclidean(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

ll expo(ll a, ll b){
    ll result = 1;
    while(b){
        if(b%2) result = (result * a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return result;
}

void solve(ll n, ll a, ll b, ll d){
    ll schoolSelection = (fact[n] * ((invFact[a] * invFact[n-a])%mod))%mod;
    ll studentSelection = (fact[b] * ((invFact[d] * invFact[b-d])%mod))%mod;

    ll result = schoolSelection;

    result = (result * expo(studentSelection, a))%mod;

    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    fact[0] = 1;
    for(ll i=1; i<mx; i++) fact[i] = (fact[i-1] * i) % mod;
    for(ll i=0; i<mx; i++) invFact[i] = modularInverse(fact[i]);

    ll n, a, b, d;
    while(cin>>n>>a>>b>>d){
        solve(n,a,b,d);
    }
    return 0;
}
