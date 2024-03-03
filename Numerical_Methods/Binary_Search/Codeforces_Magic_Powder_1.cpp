#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mx=1e3+10;
ll n,k;
vector<ll> a(mx),b(mx);

bool possible(ll c){
    ll dk=k;
    for(ll i=0; i<n; i++){
        ll need=(a[i]*c)-b[i];
        if(need>0) dk-=need;
        if(dk<0) break;
    }
    return dk>=0;
}
void solve(){
    cin>>n>>k;
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=0; i<n; i++) cin>>b[i];

    ll low=0,high=1e9+10,mid;
    while(high-low>1){
        mid=(low+high)/2;
        if(possible(mid)) low=mid;
        else high=mid-1;
    }
    if(possible(high)) cout<<high<<endl;
    else cout<<low<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    solve();
    return 0;
}