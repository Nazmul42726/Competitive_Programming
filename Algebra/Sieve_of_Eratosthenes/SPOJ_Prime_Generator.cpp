#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void primesInRange(ll l, ll r){
    ll limit=sqrt(r);
    vector<char> sieve(limit+1,true);
    vector<ll> primes;

    for(ll i=2; i<=limit; i++){
        if(sieve[i]){
            primes.emplace_back(i);
            for(ll j=i*i; j<=limit; j+=i)
                sieve[j]=false;
        }
    }

    vector<char> sieveInRange(r-l+1,true);
    for(ll i: primes){
        for(ll j=max(i*i,((l+i-1)/i)*i); j<=r; j+=i){
            sieveInRange[j-l]=false;
        }
    }
    if(l==1)
        sieveInRange[0]=false;
    
    for(ll i=0; i<=r-l; i++){
        if(sieveInRange[i])
            cout<<l+i<<endl;
    }
}
void solve(){
    ll l,r;
    cin>>l>>r;
    primesInRange(l,r);
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
        cout<<endl;
    }
    return 0;
}