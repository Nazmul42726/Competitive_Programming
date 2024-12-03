#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n;
const ll inf = 1e18;
vector<vector<ll>> capacity;
vector<set<ll>> adjList;

ll bfs(ll s, ll t, vector<ll> &parent){
    fill(parent.begin(), parent.end(), -1);
    queue<pair<ll, ll>> q;
    q.push({s, inf});
    parent[s] = -2;

    while (!q.empty()){
        ll cur = q.front().first;
        ll curFlow = q.front().second;
        q.pop();

        for (auto next : adjList[cur]){
            if (parent[next] == -1 and capacity[cur][next]){
                parent[next] = cur;
                ll nextFlow = min(curFlow, capacity[cur][next]);

                if (next == t) return nextFlow;

                q.push({next, nextFlow});
            }
        }
    }
    return 0;
}

ll maxFlow(ll s, ll t){
    ll flow = 0;
    vector<ll> parent(n);

    while (1){
        ll addedFlow = bfs(s, t, parent);
        if (addedFlow == 0) break;

        flow += addedFlow;
        ll cur = t;

        while (cur != s){
            ll prev = parent[cur];
            capacity[prev][cur] -= addedFlow;
            capacity[cur][prev] += addedFlow;
            cur = prev;
        }
    }
    return flow;
}

void solve(){
    ll m;
    cin >> n >> m;

    adjList = vector<set<ll>>(n);
    capacity = vector<vector<ll>>(n, vector<ll>(n));

    for (ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        capacity[a][b] += c;
        adjList[a].insert(b);
        adjList[b].insert(a);
    }
    cout << maxFlow(0, n - 1) << endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}