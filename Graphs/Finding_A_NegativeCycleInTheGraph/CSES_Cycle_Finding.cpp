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

vector<Edge> edges;

void solve(){
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        Edge e;
        cin>>e.a>>e.b>>e.w;
        edges.push_back(e);
    }

    vector<ll> d(n+1, 0);
    vector<ll> p(n+1, -1);

    ll changed = -1;

    for(ll i=0; i<n; i++){
        changed = -1;
        for(Edge e: edges){
            if(d[e.b] > d[e.a]+e.w){
                d[e.b] = max(-inf, d[e.a]+e.w);
                p[e.b] = e.a;
                changed = e.b;
            }
        }
    }

    if(changed == -1){
        cout<<"NO"<<endl;
        return;
    }

    ll y = changed;
    for(ll i=0; i<n; i++){
        y = p[y];
    }

    vector<ll> path;

    for(ll i = y; ; i = p[i]){
        path.push_back(i);
        if(path.size() > 1 and i == y) break;
    }
    reverse(path.begin(), path.end());

    cout<<"YES"<<endl;
    for(auto it: path){
        cout<<it<<" ";
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
