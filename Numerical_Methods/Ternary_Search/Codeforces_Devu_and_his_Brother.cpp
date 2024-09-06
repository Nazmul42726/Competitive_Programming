#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll f(vector<ll>& a, vector<ll>& b, ll m){
    ll r=0;
    for(auto it: a){
        if(it<m) r+=(m-it);
        else break;
    }
    for(auto it: b)
        if(it>m) r+=(it-m);

    return r;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=0; i<m; i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(b[m-1]<=a[0]){
        cout<<0<<endl;
        return;
    }
    ll l=a[0], r=b[m-1];
    while(r-l>2){
        ll m1=l+(r-l)/3;
        ll m2=r-(r-l)/3;
        ll f1=f(a,b,m1);
        ll f2=f(a,b,m2);

        if(f1>f2) l=m1+1;
        else r=m2-1;
    }
    ll result=min(f(a,b,l),min(f(a,b,l+1),f(a,b,l+2)));
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}