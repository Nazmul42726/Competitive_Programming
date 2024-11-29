class Solution {
private:
    const int inf = 1e9+7;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool neighbourExists(vector<vector<int>>& grid, int row, int column){
        return (row>=0 and row<grid.size() and column>=0 and column<grid[0].size());
    }

public:

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minCost(m, vector<int>(n, inf));
        minCost[0][0] = 0;

        using pii = pair<int,pair<int,int>>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int curCost = pq.top().first;
            int vRow = pq.top().second.first;
            int vColumn = pq.top().second.second;
            pq.pop();

            if(vRow == m-1 and vColumn == n-1) return curCost;

            for(auto dir: directions){
                int toRow = vRow + dir.first;
                int toColumn = vColumn + dir.second;

                if(neighbourExists(grid, toRow, toColumn)){
                    if(minCost[toRow][toColumn] > curCost + grid[toRow][toColumn]){
                        minCost[toRow][toColumn] = curCost + grid[toRow][toColumn];
                        pq.push({minCost[toRow][toColumn],{toRow,toColumn}});
                    }
                }
            }
       }
        return minCost[m-1][n-1];
    }
};