#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod=1e9+7;
map<ll,ll> F;

ll findFib(ll n){
    if(F.count(n)) return F[n];
    ll k=n/2;
    if(n%2==0) return F[n]=(findFib(k)*findFib(k) + findFib(k-1)*findFib(k-1))%mod;
    else return F[n]=(findFib(k)*findFib(k+1) + findFib(k-1)*findFib(k))%mod;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    n--,m--;    //our series is 1,1,2,3,5,8,13...
    //F[0]+F[1]+...+F[n]=F[n+2]-1
    ll mp2=findFib(m+2);
    ll np1=findFib(n+1);
    ll result=(mp2>=np1)?(mp2-np1):(mod-np1+mp2);
    cout<<result%mod<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    F[0]=F[1]=1;
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}