#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n;

ll fact(ll n){
    ll result = 1;
    while(n>1){
        result *= n;
        n--;
    }
    return result;
}

void solve(){
    vector<ll> catalan(11);
    catalan[0] = 1;
    catalan[1] = 1;
    for(ll i=2; i<11; i++){
        catalan[i] = fact(2*i)/(fact(i+1)*fact(i));
    }
    cout<<catalan[n]<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    bool f = false;
    while(cin>>n){
        if(f) cout<<endl;
        solve();
        f=true;
    }
    return 0;
}
