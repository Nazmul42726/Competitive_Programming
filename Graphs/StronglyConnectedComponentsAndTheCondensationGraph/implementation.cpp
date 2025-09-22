#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int source, vector<vector<int>>& adjList, vector<int>& order){
    visited[source] = true;
    for(auto neighbour: adjList[source]){
        if(!visited[neighbour]){
            dfs(neighbour,adjList,order);
        }
    }
    order.push_back(source);
}

void stronglyConnectedComp(vector<vector<int>>& adjList,
                           vector<vector<int>>& adjCond,
                           vector<vector<int>>& components){
    int n = adjList.size()-1;
    adjCond.clear();
    components.clear();

    visited.assign(n+1,false);
    vector<int> order;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i,adjList,order);
        }
    }

    reverse(order.begin(), order.end());

    vector<vector<int>> revAdjList(n+1);
    for(int i=0; i<=n; i++){
        for(auto neighbour: adjList[i]){
            revAdjList[neighbour].push_back(i);
        }
    }

    visited.assign(n+1,false);
    vector<int> roots(n+1,0);

    for(auto v: order){
        if(!visited[v]){
            vector<int> comp;
            dfs(v, revAdjList, comp);
            components.push_back(comp);
            int root = *min_element(comp.begin(), comp.end());

            for(auto u: comp){
                roots[u] = root;
            }  
        }
    }

    adjCond.assign(n+1,{});
    for(int i=0; i<=n; i++){
        for(auto neighbour: adjList[i]){
            if(roots[i] != roots[neighbour]){
                adjCond[roots[i]].push_back(roots[neighbour]);
            }
        }
    }
}