#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll a,b;
    cin>>a>>b;
    cout<<__gcd(a,b)<<" "<<lcm(a,b)<<endl;     //lol    //surprised?
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}