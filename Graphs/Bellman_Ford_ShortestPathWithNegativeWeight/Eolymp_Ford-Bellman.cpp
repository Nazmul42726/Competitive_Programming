#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int inf = 30000;

struct Edge{
    int a;
    int b;
    int w;
};

void solve(){
    int n, m;
    cin>>n>>m;

    vector<Edge> edges(m);

    for(int i=0; i<m; i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }

    vector<int> dist(n+1, inf);
    dist[1] = 0;

    for(int i=1; i<n; i++){
        for(Edge e: edges){
            if(dist[e.a] < inf){
                dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
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
