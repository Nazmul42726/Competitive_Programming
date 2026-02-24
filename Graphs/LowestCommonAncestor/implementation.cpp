#include<bits/stdc++.h>
using namespace std;

struct LCA{
    vector<int> height, euler, first, logTable;
    vector<vector<int>> table;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>>& adjList, int root = 0){
        n = adjList.size();

        height.resize(n);
        first.resize(n);
        euler.reserve(2*n);
        visited.assign(n, false);

        dfs(adjList, root);
        build(euler);
    }

    void dfs(vector<vector<int>>& adjList, int node, int h = 0){
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);

        for(auto to: adjList[node]){
            if(!visited[to]){
                dfs(adjList, to, h+1);
                euler.push_back(node);
            }
        }
    }

    void build(vector<int>& euler){
        int mxN = euler.size();
        int exp = log2(mxN) + 1;

        logTable.assign(mxN+1, 0);
        table.assign(exp, vector<int>(mxN));

        for(int i=2; i<=mxN; i++)
            logTable[i] = logTable[i/2]+1;

        for(int i=0; i<mxN; i++)
            table[0][i] = euler[i];

        for(int i=1; i<exp; i++){
            for(int j=0; j+(1<<i) <= mxN; j++){
                int u = table[i-1][j];
                int v = table[i-1][j+(1<<(i-1))];
                table[i][j] = (height[u] < height[v]) ? u : v;
            }
        }
    }

    int query(int left, int right){
        int range = right-left+1;
        int logRange = logTable[range];

        int u = table[logRange][left];
        int v = table[logRange][right - (1<<logRange) + 1];
        return (height[u] < height[v]) ? u : v;
    }

    int lca(int u, int v){
        int left = first[u], right = first[v];
        if(left > right) swap(left, right);

        return query(left, right);
    }
};
