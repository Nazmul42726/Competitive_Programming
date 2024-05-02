#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=2e5+10;
ll parent[N];
ll setRank[N];

void makeSet(ll n){
    for(ll i=1; i<=n; i++)
        parent[i]=i;
}
ll findSet(ll n){
    if(parent[n]==n) return n;
    return parent[n]=findSet(parent[n]);
}
void unionSet(ll a, ll b){
    a=findSet(a);
    b=findSet(b);
    if(setRank[a]<setRank[b])
        swap(a,b);
    parent[b]=a;
    if(setRank[a]==setRank[b])
        setRank[a]++;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    vector<set<ll>> vs(n+1);
    makeSet(n);
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        vs[i].insert(a[i]);
        vs[a[i]].insert(i);
        unionSet(i,a[i]);
    }
    ll maxSetCnt=0;
    for(ll i=1; i<=n; i++){
        ll x=findSet(i);
        if(parent[i]==i)
            maxSetCnt++;
    }
    ll nodeWithOneNeighbour=0;
    for(ll i=1; i<=n; i++){
        if(vs[i].size()==1)
            nodeWithOneNeighbour++;
    }
    ll setCanBeMargedlloOne=nodeWithOneNeighbour/2;
    ll cntSetToDecrease=setCanBeMargedlloOne-1;
    if(setCanBeMargedlloOne==0)
        cntSetToDecrease=0;
    ll minSetCnt=maxSetCnt-cntSetToDecrease;
    cout<<minSetCnt<<" "<<maxSetCnt<<endl;
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