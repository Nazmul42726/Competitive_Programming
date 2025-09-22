#include<bits/stdc++.h>
using namespace std;

int n,lg;
vector<vector<int>> adjList;

int timer;
vector<int> tIn, tOut;
vector<vector<int>> ancestors;

void dfs(int source, int parent){
    timer++;
    tIn[source] = timer;

    ancestors[source][0] = parent;
    for(int i=1; i<=lg; i++){
        ancestors[source][i] = ancestors[ancestors[source][i-1]][i-1];
    }

    for(auto neighbour: adjList[source]){
        if(neighbour != parent){
            dfs(neighbour, source);
        }
    }
    timer++;
    tOut[source] = timer;
}

bool isAncestor(int u, int v){
    return (tIn[u]<=tIn[v] and tOut[u]>=tOut[v]);
}

int lca(int u, int v){
    if(isAncestor(u,v)) return u;
    if(isAncestor(v,u)) return v;

    for(int i = lg; i>=0; i--){
        if(!isAncestor(ancestors[u][i], v)){
            u = ancestors[u][i];
        }
    }
    return ancestors[u][0];
}

void preProcess(int root){
    tIn.resize(n);
    tOut.resize(n);
    timer = 0;
    lg = ceil(log2(n));
    ancestors.assign(n, vector<int>(lg+1));
    dfs(root, root);
}