#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e5+10;
vector<ll> sieve(N,1);

void makeSieve(){
    sieve[0]=0;
    sieve[1]=0;
    for(ll i=2; i*i<N; i++){
        if(sieve[i]){
            for(ll j=i*i; j<N; j+=i)
                sieve[j]=0;
        }
    }
}
void preCal(){
    makeSieve();
    for(ll i=1; i<N; i++)
        sieve[i]+=sieve[i-1];
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll sqrtN=sqrt(n);
    ll sqrtK=sqrt(k);

    cout<<sieve[sqrtN]<<" "<<max(0ll,sieve[sqrtN]-sieve[sqrtK])<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    preCal();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}