#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll p1 = 31, p2 = 37;
const ll mod1 = 1e9+7, mod2 = 1e9+9;
const ll mxN = 1510;

vector<ll> pp1(mxN),pp2(mxN);
vector<ll> invpp1(mxN), invpp2(mxN);

struct PairHash {
    size_t operator()(const pair<ll, ll>& p) const {
        return ((p.first * 1LL * mod2 + p.second) % mod1);
    }
};

ll modularInverse(ll a, ll mod){
    ll result = 1;
    ll exp = mod-2;
    while(exp){
        if(exp%2) result = (result * a) % mod;
        a = (a * a) % mod;
        exp /= 2;
    }
    return result;
}

void solve(){
    string s;
    string vc;
    ll cnt;
    cin>>s>>vc>>cnt;

    ll n = s.size();

    vector<ll> cntInv(n,0);
    if(vc[s[0]-'a']=='0') cntInv[0] = 1;

    vector<ll> hsh1(n),hsh2(n);
    hsh1[0] = hsh2[0] = (ll)(s[0] - 'a' + 1);

    for(ll i=1; i<n; i++){
        hsh1[i] = (hsh1[i-1] + (ll)(s[i] - 'a' + 1)*pp1[i])%mod1;
        hsh2[i] = (hsh2[i-1] + (ll)(s[i] - 'a' + 1)*pp2[i])%mod2;
        cntInv[i] = cntInv[i-1];
        if(vc[s[i]-'a']=='0') cntInv[i]++;
    }

    unordered_set<pair<ll,ll>, PairHash> sh;

    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            ll invCnt = cntInv[j];
            if(i > 0) invCnt -= cntInv[i-1];
            if(invCnt > cnt) break;

            ll h1 = hsh1[j], h2 = hsh2[j];
            if(i>0){
                h1 = (h1 + mod1 - hsh1[i-1])%mod1;
                h2 = (h2 + mod2 - hsh2[i-1])%mod2;
                h1 *= invpp1[i];
                h2 *= invpp2[i];
                h1 %= mod1;
                h2 %= mod2;
            }
            sh.insert({h1,h2});
        }
    }

    cout<<sh.size()<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    pp1[0] = 1;
    invpp1[0] = modularInverse(pp1[0], mod1);

    pp2[0] = 1;
    invpp2[0] = modularInverse(pp2[0], mod2);

    for(ll i=1; i<mxN; i++){
        pp1[i] = (pp1[i-1]*p1)%mod1;
        pp2[i] = (pp2[i-1]*p2)%mod2;
        invpp1[i] = modularInverse(pp1[i], mod1);
        invpp2[i] = modularInverse(pp2[i], mod2);
    }
    
    solve();
    return 0;
}
