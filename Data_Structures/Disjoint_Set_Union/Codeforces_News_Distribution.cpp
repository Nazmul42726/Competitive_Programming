#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=5e5+10;
vector<ll> parent(N);
vector<ll> setSize(N);

void makeSet(ll n){
    for(ll i=0; i<=n; i++){
        parent[i]=i;
        setSize[i]=1;
    }
}
ll findSet(ll a){
    if(parent[a]==a) return a;
    return parent[a]=findSet(parent[a]);
}
void unionSet(ll a, ll b){
    a=findSet(a);
    b=findSet(b);
    if(a!=b){
        if(setSize[a]<setSize[b])
            swap(a,b);
        parent[b]=a;
        setSize[a]+=setSize[b];
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    makeSet(n);
    for(ll i=0; i<m; i++){
        ll x;
        cin>>x;
        if(x==0) continue;
        ll y;
        cin>>y;
        for(ll j=1; j<x; j++){
            ll p;
            cin>>p;
            unionSet(y,p);
        }
    }
    ll result=0;
    for(ll i=1; i<=n; i++){
        ll x=findSet(i);
        cout<<setSize[x]<<" ";
    }  
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}