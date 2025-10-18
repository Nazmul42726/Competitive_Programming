#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll inf = 1e18;

struct Edge{
    ll a;
    ll b;
    ll w;
};

void dfs(int source, vector<bool>& visited, vector<vector<int>>& adjList){
    visited[source] = true;
    for(auto neighbour: adjList[source]){
        if(!visited[neighbour]){
            dfs(neighbour, visited, adjList);
        }
    }
}

void solve(){
    ll n, m;
    cin>>n>>m;

    vector<Edge> edges(m);
    vector<vector<int>> adjList(n+1);

    for(ll i=0; i<m; i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
        adjList[edges[i].a].push_back(edges[i].b);
    }

    vector<ll> dist(n+1, -inf);
    dist[1] = 0;

    for(ll i=1; i<n; i++){
        for(Edge e: edges){
            if(dist[e.a] > -inf){
                dist[e.b] = max(dist[e.b], dist[e.a]+e.w);
            }
        }
    }
    ll cur = dist[n];
    vector<int> nds;
    for(Edge e: edges){
        if(dist[e.a] > -inf and dist[e.b] < dist[e.a] + e.w){
            nds.push_back(e.a);
        }
    }
    if(nds.size() == 0){
        cout<<cur<<endl;
        return;
    }
    
    vector<bool> visited(n+1, false);
    for(auto it: nds){
        dfs(it, visited, adjList);
    }

    if(visited[n]){
        cout<< -1<<endl;
        return;
    }
    cout<<cur<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
