//implementation of BFS
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
int nodes;
vector<int> d,p;
vector<bool> vis;

void BFS(int source){
    queue<int> q;
    vector<bool> visited(nodes,false);
    vector<int> distanceFromSource(nodes,-1), parent(nodes);
    /*
    if -1 then it's not connected with the graph component that
    contains source, because path length cannot be negative in BFS
    */
    q.push(source);
    visited[source]=true;
    parent[source]=-1;
    distanceFromSource[source]=0;

    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto it: adjList[v]){
            q.push(it);
            visited[it]=true;
            distanceFromSource[it]=distanceFromSource[v]+1;
            parent[it]=v;
        }
    }
    d=distanceFromSource;
    p=parent;
    vis=visited;
}

vector<int> pathFromSource(int source,int node){
    BFS(source);
    vector<int> path;
    if(!vis[node]) return path;
    
    for(int i=node; i!=-1; i=p[node]) path.push_back(i);
    reverse(path.begin(),path.end());
    return path;
}