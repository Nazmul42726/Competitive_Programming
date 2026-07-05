//Problem Link: https://leetcode.com/problems/network-recovery-pathways/description/

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int m = edges.size();

        using pii = pair<int,int>;
        vector<vector<pii>> adjList(n);
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];

            adjList[u].push_back({v, cost});
        }

        long long inf = 1e18;
        long long low = 0, high = 1e9;
        long long result = -1;

        while(low <= high){
            long long mid = (low + high) / 2;

            vector<long long> dist(n, inf);
            priority_queue<pii, vector<pii>, greater<pii>> pq;

            dist[0] = 0;
            pq.push({0, 0});

            while(!pq.empty()){
                long long cur = pq.top().first;
                long long cst = pq.top().second;
                pq.pop();

                if(cst > dist[cur]) continue;

                for(auto it : adjList[cur]){
                    long long nxt = it.first;
                    long long wgt = it.second;

                    long long nxtCst = cst + wgt;
                    if(!online[nxt] or nxtCst > k or wgt < mid) continue;

                    if(nxtCst < dist[nxt]){
                        dist[nxt] = nxtCst;
                        pq.push({nxt, nxtCst});
                    }
                }
            }

            if(dist[n-1] <= k){
                result = max(result, mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        return (int)result;
    }
};
