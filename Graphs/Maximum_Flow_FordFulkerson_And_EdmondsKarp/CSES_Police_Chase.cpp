#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,m;
const int inf = 1e9+7;
vector<bool> visited;
vector<vector<int>> adjList;
vector<vector<int>> capacity;

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(),parent.end(), -1);
    queue<pair<int,int>> q;
    q.push({s,inf});
    parent[s] = -2;  

    while(!q.empty()){
        int curNode = q.front().first;
        int curFlow = q.front().second;
        q.pop();

        for(auto next: adjList[curNode]){
            if(parent[next] == -1 and capacity[curNode][next]){
                parent[next] = curNode;
                ll nextFlow = min(curFlow, capacity[curNode][next]);

                if(next == t) return nextFlow;

                q.push({next, nextFlow});
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t){
    int flow = 0;
    vector<int> parent(n);


    while(1){
        int addedFlow = bfs(0,n-1,parent);
        if(addedFlow == 0) break;

        flow += addedFlow;
        int cur = t;

        while(cur != s){
            int previous = parent[cur];
            capacity[previous][cur] -= addedFlow;
            capacity[cur][previous] += addedFlow;
            cur=previous;
        }
    }
    return flow;
}

void dfs(int source){
    visited[source] = true;
    for(auto neighbour: adjList[source]){
        if(!visited[neighbour] and capacity[source][neighbour])
            dfs(neighbour);
    }
}

void solve(){
    cin>>n>>m;
    visited = vector<bool>(n,false);
    adjList = vector<vector<int>>(n);
    capacity = vector<vector<int>> (n,vector<int>(n));

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        capacity[a][b] = 1;
        capacity[b][a] = 1;
    }

    cout<<maxFlow(0,n-1)<<endl;

    dfs(0);

    for(int i=0; i<n; i++){
        if(!visited[i]) continue;
        for(auto v: adjList[i]){
            if(!visited[v]){
                cout<<i+1<<" "<<v+1<<endl;
            }
        }
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}