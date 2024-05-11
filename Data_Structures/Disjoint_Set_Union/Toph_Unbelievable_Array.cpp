#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e5+10;
ll parent[N];
ll setRank[N];

void makeSet(){
    for(ll i=0; i<N; i++){
        parent[i]=i;
        setRank[i]=0;
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
        if(setRank[a]<setRank[b])
            swap(a,b);
        parent[b]=a;
        if(setRank[a]==setRank[b])
            setRank[a]++;
    }
}
void solve(){
    ll n,q;
    cin>>n>>q;
    makeSet();
    vector<ll> a(n);
    vector<ll> indOfValue(N,-1),valueAtInd(N,-1);
    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(indOfValue[a[i]]==-1){
            indOfValue[a[i]]=i;
            valueAtInd[i]=a[i];
        }
        else{
            unionSet(indOfValue[a[i]],i);
            indOfValue[a[i]]=findSet(i);
            valueAtInd[indOfValue[a[i]]]=a[i];
        }
    }
    for(ll i=0; i<q; i++){
        ll type;
        cin>>type;
        if(type==1){
            ll x,y;
            cin>>x>>y;
            if(indOfValue[x]==-1 or x==y) continue;
            if(indOfValue[y]==-1){
                indOfValue[y]=indOfValue[x];
                valueAtInd[indOfValue[x]]=y;
                indOfValue[x]=-1;
            }
            else{
                ll a=indOfValue[x];
                ll b=indOfValue[y];
                unionSet(a,b);
                indOfValue[y]=findSet(b);
                valueAtInd[indOfValue[y]]=y;
                indOfValue[x]=-1;
            }
        }
        else if(type==2){
            ll ind;
            cin>>ind;
            ll a=findSet(ind-1);
            cout<<valueAtInd[a]<<endl;
        }
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}