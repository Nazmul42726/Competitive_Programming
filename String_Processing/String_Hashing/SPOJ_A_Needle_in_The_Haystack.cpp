#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll p1 = 31, p2 = 37;
const ll mod1 = 1e9+7, mod2 = 1e9+9;
const ll mxN = 1e7+10;

vector<ll> pp1(mxN), pp2(mxN);
vector<ll> inv1(mxN), inv2(mxN);

ll modularInverse(ll a, ll mod){
    ll result = 1;
    ll exp = mod - 2;

    while(exp){
        if(exp % 2) result = (result*a)%mod;
        a = (a*a)%mod;
        exp /= 2;
    }
    return result;
}

void solve(){
    string needle, haystack;
    cin>>needle>>haystack;

    ll n1 = needle.size();
    ll n2 = haystack.size();

    if(n1 > n2) return;

    ll h1 = needle[0]-'a'+1;
    ll h2 = needle[0]-'a'+1;
    for(ll i=1; i<n1; i++){
        h1 = (h1 + ((ll)(needle[i]-'a'+1)*pp1[i]))%mod1;
        h2 = (h2 + ((ll)(needle[i]-'a'+1)*pp2[i]))%mod2;
    }

    vector<ll> hs1(n2), hs2(n2);
    hs1[0] = haystack[0] - 'a' + 1;
    hs2[0] = haystack[0] - 'a' + 1;
    for(ll i=1; i<n2; i++){
        hs1[i] = (hs1[i-1] + ((ll)(haystack[i]-'a'+1)*pp1[i]))%mod1;
        hs2[i] = (hs2[i-1] + ((ll)(haystack[i]-'a'+1)*pp2[i]))%mod2;
    }

    for(ll i=n1-1; i<n2; i++){
        ll v1 = hs1[i];
        ll v2 = hs2[i];

        if(i-n1 >= 0){
            v1 = (((v1 + mod1 - hs1[i-n1]) % mod1) * inv1[i-n1+1]) % mod1;
            v2 = (((v2 + mod2 - hs2[i-n1]) % mod2) * inv2[i-n1+1]) % mod2;
        }
        if(v1 == h1 and v2 == h2){
            cout<<i-n1+1<<endl;
        }
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    pp1[0] = pp2[0] = 1;
    inv1[0] = inv2[0] = 1;

    for(ll i=1; i<mxN; i++){
        pp1[i] = (pp1[i-1] * p1) % mod1;
        pp2[i] = (pp2[i-1] * p2) % mod2;

        inv1[i] = modularInverse(pp1[i], mod1);
        inv2[i] = modularInverse(pp2[i], mod2);
    }

    ll n;
    while(cin>>n){
        solve();
        cout<<endl;
    }
    return 0;
}