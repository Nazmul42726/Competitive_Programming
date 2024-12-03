#include <bits/stdc++.h>
using namespace std;

int n;
const int inf = 1e9 + 7;
vector<vector<int>> capacity;
vector<vector<int>> adjList;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({s, inf});
    parent[s] = -2;

    while (!q.empty())
    {
        int curNode = q.front().first;
        int curFlow = q.front().second;
        q.pop();

        for (auto next : adjList[curNode])
        {
            if (parent[next] == -1 and capacity[curNode][next] > 0)
            {
                parent[next] = curNode;
                int nextFlow = min(curFlow, capacity[curNode][next]);

                if (next == t)
                    return nextFlow;

                q.push({next, nextFlow});
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n);

    while (1)
    {
        int addedFlow = bfs(s, t, parent);
        if (addedFlow == 0)
            break;

        flow += addedFlow;

        int current = t;

        while (current != s)
        {
            int previous = parent[current];
            capacity[previous][current] -= addedFlow;
            capacity[current][previous] += addedFlow;
            current = previous;
        }
    }
    return flow;
}