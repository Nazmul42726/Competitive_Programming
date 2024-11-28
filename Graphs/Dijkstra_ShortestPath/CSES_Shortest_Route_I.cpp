#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void dijkstra(ll n, ll source, vector<vector<pair<ll,ll>>>& adjList, vector<ll>& dist){
    const ll inf = 1e18;
    dist.assign(n+1,inf);

    using pi = pair<ll,ll>;
    priority_queue<pi,vector<pi>,greater<pi>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        ll v = pq.top().second;
        ll distOfV = pq.top().first;
        pq.pop();

        if(distOfV != dist[v]) continue;

        for(auto edge: adjList[v]){
            ll to = edge.first;
            ll weight = edge.second;
            if(dist[to] > dist[v]+weight){
                dist[to] = dist[v]+weight;
                pq.push({dist[to], to});
            }
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>> adjList(n+1);
    for(ll i=0; i<m; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adjList[a].push_back({b,c});
    }
    vector<ll> dist;

    dijkstra(n,1,adjList,dist);

    for(ll i=1; i<=n; i++) cout<<dist[i]<<" ";
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}