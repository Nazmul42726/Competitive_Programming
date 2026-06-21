//Problem Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description/

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1) return 0;
        int m = edges.size();
        vector<vector<pair<int,int>>> adjList(n);

        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adjList[u].push_back({v, w});
        }

        int inf = 1e9+7;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        if(k > n){
            vector<int> dist(n, inf);
            dist[0] = 0;
            pq.push({0, 0});

            while(!pq.empty()){
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if(d != dist[u]) continue;
                if(u == n-1) return d;

                for(auto it: adjList[u]){
                    int v = it.first;
                    int w = it.second;

                    if(dist[v] > d+w){
                        dist[v] = d+w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return -1;
        }

        int base1 = k+1;
        int base2 = 26 * base1;
        unordered_map<int, int> dist;

        int startLabel = labels[0] - 'a';

        //0'th node with label 'startLabel' for '1' consecutive time
        int startKey = 0*base2 + startLabel*base1 + 1;
        dist[startKey] = 0;

        pq.push({0, startKey});

        while(!pq.empty()){            
            int d = pq.top().first;
            int key = pq.top().second;
            pq.pop();

            if(d != dist[key]) continue;

            int cnt = key % (k+1);
            int tmp = key / (k+1);
            int lastLabel = tmp % 26;
            int u = tmp/26;

            if(u == n-1) return d;

            for(auto it: adjList[u]){
                int v = it.first;
                int w = it.second;

                int nxtLabel = labels[v] - 'a';
                int nxtCnt = (nxtLabel == lastLabel) ? cnt + 1 : 1;

                if(nxtCnt > k) continue;

                int nKey = v*base2 + nxtLabel*base1 + nxtCnt;
                int nxtDist = d + w;

                auto itt = dist.find(nKey);

                if(itt == dist.end() or nxtDist < itt->second){
                    dist[nKey] = nxtDist;
                    pq.push({nxtDist, nKey});
                }
            }
        }
        return -1;
    }
};
