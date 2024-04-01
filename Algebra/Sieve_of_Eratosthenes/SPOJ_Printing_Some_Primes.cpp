#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e8+1;
vector<char> sieve(N,true);
vector<ll> primes;

void generatePrimes(){
    for(ll i=2; i<N; i++){
        if(sieve[i]){
            primes.emplace_back(i);
            for(ll j=i*i; j<=N; j+=i)
                sieve[j]=false;
        }
    }
}
void solve(){
    generatePrimes();
    ll n=primes.size();
    for(ll i=0; i<n; i+=100)
        cout<<primes[i]<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}