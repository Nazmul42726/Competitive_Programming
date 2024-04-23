#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod=1000000007;
map<ll,ll> F;

ll findFib(ll n){
    if(F.count(n)) return F[n];
    ll k=n/2;
    if(n%2==0){
        return F[n]=(findFib(k)*findFib(k) + findFib(k-1)*findFib(k-1))%mod;
    } else{
        return F[n]=(findFib(k)*findFib(k+1) + findFib(k-1)*findFib(k))%mod;
    }
}
void solve(){
    ll n;
    F[0]=F[1]=1;        //1,1,2,3,5,8,...
    cin>>n;
    if(n==0) cout<<0<<endl;
    else if(n==1) cout<<2<<endl;
    else cout<<(findFib(n)%mod + findFib(n+1)%mod)%mod<<endl;
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