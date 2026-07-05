//Problem Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/
    
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int inf = 1e9+7;
        using pi = pair<int,int>;
        using pii = pair<int,pair<int,int>>;
        vector<vector<int>> dist(n, vector<int>(m, inf));
        vector<pi> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int dis = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(dist[x][y] != inf) continue;
            dist[x][y] = dis;
            
            for(int i=0; i<4; i++){
                int px = x + dir[i].first;
                int py = y + dir[i].second;

                if(px < 0 or py < 0 or px >=n or py >=m or dist[px][py] != inf) continue;

                pq.push({dis + grid[px][py], {px, py}});
            }
        }
        return (dist[n-1][m-1] < health);
    }
};
