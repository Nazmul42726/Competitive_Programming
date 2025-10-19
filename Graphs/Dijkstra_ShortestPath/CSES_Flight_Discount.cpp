#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll inf = 1e18;

void dijkstra(ll source, vector<vector<pair<ll,ll>>>& adjList, vector<ll>& dist){
    ll n = adjList.size();
    dist = vector<ll>(n,inf);

    using pii= pair<ll,ll>;
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty()){
        ll v = pq.top().second;
        ll distOfV = pq.top().first;
        pq.pop();

        if(distOfV > dist[v]) continue;

        for(auto edge: adjList[v]){
            ll to = edge.first;
            ll length = edge.second;

            if(dist[v] + length < dist[to]){
                dist[to] = dist[v]+length;
                pq.push({dist[to],to});
            }
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adjList1(n+1),adjList2(n+1);
    map<ll,map<ll,ll>> edges;

    for(ll i=0; i<m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adjList1[a].push_back({b,c});
        adjList2[b].push_back({a,c});
        if(edges[a].find(b)==edges[a].end()) edges[a][b] = c;
        else edges[a][b] = min(edges[a][b],c);
    }
    
    vector<ll> distFrom1, distFromN;
    dijkstra(1,adjList1,distFrom1);
    dijkstra(n,adjList2,distFromN);

    ll result = inf;
    for(auto it: edges){
        for(auto itt: it.second){
            result = min(result, distFrom1[it.first]+distFromN[itt.first]+itt.second/2);
        }
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}