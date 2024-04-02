#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    if(k==1){
        cout<<*min_element(a.begin(),a.end())<<endl;
    }
    else if(k==2){
        cout<<max(a[0],a[n-1])<<endl;
    }
    else{
        cout<<*max_element(a.begin(),a.end())<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    solve();
    return 0;
}