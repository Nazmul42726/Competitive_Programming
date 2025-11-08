#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll p = 31;
const ll mod = 1e9+7;
const ll mxN = 1e6+10;

vector<ll> pp(mxN);
vector<ll> invpp(mxN);

ll modularInverse(ll a){
    ll exp = mod-2;
    ll result = 1;

    while(exp){
        if(exp%2) result = (result*a)%mod;
        a = (a*a)%mod;
        exp /= 2;
    }
    return result;
}

void solve(){
    string a,b;
    cin>>a>>b;

    ll n1 = a.size();
    ll n2 = b.size();

    if(n2>n1){
        cout<<"Not Found"<<endl;
        return;
    }

    vector<ll> h1(n1);
    ll h2 = 0;

    h1[0] = (ll)(a[0]-'a'+1);
    for(ll i=1; i<n1; i++){
        h1[i] = (h1[i-1] + ((ll)(a[i]-'a'+1)*pp[i]))%mod;
    }
    for(ll i=0; i<n2; i++){
        h2 += ((ll)(b[i]-'a'+1) * pp[i]);
        h2 %= mod;
    }

    vector<ll> results;

    for(ll i = n2 -1; i<n1; i++){
        ll l = i - n2;
        
        ll hSub = h1[i];
        if(l >= 0){
            hSub = (hSub + mod - h1[l]) % mod;
            hSub *= invpp[l+1];
            hSub %= mod;
        }
        if(hSub == h2) results.push_back(l+2);
    }

    ll n = results.size();

    if(n==0){
        cout<<"Not Found"<<endl;
        return;
    }
    cout<<n<<endl;
    for(ll i=0; i<n; i++) cout<<results[i]<<" ";
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    pp[0] = 1;
    invpp[0] = modularInverse(pp[0]);
    for(ll i=1; i<mxN;  i++){
        pp[i] = (pp[i-1]*p)%mod;
        invpp[i] = modularInverse(pp[i]);
    }

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
        if(i<t) cout<<endl;
    }
    return 0;
}
