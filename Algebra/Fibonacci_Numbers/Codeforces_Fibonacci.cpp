#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod=1e9+7;
unordered_map<ll,ll> F;

ll findFibo(ll n){
    if(F.count(n)) return F[n];
    ll k=n/2;
    if(n%2==0) return F[n]=(findFibo(k)*findFibo(k)+findFibo(k-1)*findFibo(k-1))%mod;
    else return F[n]=(findFibo(k)*findFibo(k+1)+findFibo(k)*findFibo(k-1))%mod;
}
void solve(){
    F[0]=F[1]=1;
    ll n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return;
    }
    n--;
    cout<<findFibo(n)<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}