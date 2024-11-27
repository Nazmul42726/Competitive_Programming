//Implementation of Dijkstra Algorithm
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
vector<vector<pair<int,int>>> adjList;

void dijkstra(int source, vector<int>& distance, vector<int>& parent){
    int n = adjList.size();
    distance.assign(n,INF);
    parent.assign(n,-1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        int v = pq.top().second;
        int distanceOfV = pq.top().first;
        pq.pop();

        /*
        If the node is updated multiple times (via different paths),
        multiple entries for the same node may exist in the priority queue,
        but only the one with the smallest distance is relevant.
        */
        if(distanceOfV != distance[v]) continue;
        
        for(auto edge: adjList[v]){
            int to = edge.first;
            int weight = edge.second;

            if(distance[v]+weight < distance[to]){
                distance[to] = distance[v]+weight;
                parent[to] = v;
                pq.push({distance[to],to});
            }
        }
    }
}

vector<int> restorePath(int source, int target, vector<int>const& parent){
    vector<int> path;
    if(target!=source and parent[target]==-1) return path;

    for(int v = target; v!=source; v=parent[v]){
        path.push_back(v);
    }
    path.push_back(source);

    reverse(path.begin(), path.end());
    return path;
}
