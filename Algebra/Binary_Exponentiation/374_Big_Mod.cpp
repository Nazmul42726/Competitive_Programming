#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() "ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);"

void b_to_p_mod_m(ll b, ll p, ll m){
    b%=m;
    ll ans=1;
    while(p>0){
        if(p&1)
            ans=ans*b%m;
        b=b*b%m;
        p>>=1;
    }
    cout<<ans<<endl;
}
void solve(){
     ll b,p,m;
     while(cin>>b>>p>>m)
        b_to_p_mod_m(b,p,m);
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}