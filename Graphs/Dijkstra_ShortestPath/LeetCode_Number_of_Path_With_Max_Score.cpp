//Problem Link: https://leetcode.com/problems/number-of-paths-with-max-score/description/

class Solution {
public:
        int calc(int x, int y, vector<vector<int>>& a, vector<int>& dist, vector<vector<int>>& dp, int mod){
        if(x < 0 or y < 0 or a[x][y] == -1) return 0;
        if(x == 0 and y == 0) return 1;
        if(dp[x][y] != -1) return dp[x][y];

        int cnt = 0;
        int id = x*1000 + y;
        int cur = dist[id];

        int leftId = (x-1)*1000 + y;
        int topId = x*1000 + y-1;
        int topLeftId = (x-1)*1000 + y-1;

        if(x > 0 and dist[leftId] != -1 and dist[leftId] + a[x][y] == cur)
            cnt = (cnt + calc(x-1, y, a, dist, dp, mod)) % mod;

        if(y > 0 and dist[topId] != -1 and dist[topId] + a[x][y] == cur)
            cnt = (cnt + calc(x, y-1, a, dist, dp, mod)) % mod;

        if(x > 0 and y > 0 and dist[topLeftId] != -1 and dist[topLeftId] + a[x][y] == cur)
            cnt = (cnt + calc(x-1, y-1, a, dist, dp, mod)) % mod;

        dp[x][y] = cnt;
        return cnt;
    }

    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();
        int m = b[0].size();

        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x;
                if(b[i][j] == 'S' or b[i][j] == 'E') x = 0;
                else if(b[i][j] == 'X') x = -1;
                else x = b[i][j] - '0';
                a[i][j] = x;
            }
        }

        int total = 1000*n + m;
        vector<int> dist(total, -1);
        priority_queue<pair<int,int>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            int d = pq.top().first;
            int id = pq.top().second;
            pq.pop();

            if(dist[id] > d) continue;

            int y = id % 1000;
            int x = id / 1000;

            if(x + 1 < n and a[x+1][y] != -1){
                int rid = (x+1)*1000 + y;
                if(dist[rid] < d + a[x+1][y]){
                    dist[rid] = d + a[x+1][y];
                    pq.push({d + a[x+1][y], rid});
                }
            }
            if(y + 1 < m and a[x][y+1] != -1){
                int bid = x*1000 + y + 1;
                if(dist[bid] < d + a[x][y+1]){
                    dist[bid] = d + a[x][y+1];
                    pq.push({d + a[x][y+1], bid});
                }
            }
            if(x + 1 < n and y + 1 < m and a[x+1][y+1] != -1){
                int lrid = (x+1)*1000 + y + 1;
                if(dist[lrid] < d + a[x+1][y+1]){
                    dist[lrid] = d + a[x+1][y+1];
                    pq.push({d + a[x+1][y+1], lrid});
                }
            }
        }

        if(dist[(n-1)*1000 + (m-1)] == -1) return {0, 0};

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int mod = 1e9+7;
        vector<int> result(2, 0);
        result[0] = dist[(n-1)*1000 + (m-1)];
        result[1] = calc(n-1, m-1, a, dist, dp, mod); 

        return result;
    }
};
