class Solution {
private:
    const int inf = 1e9+7;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool neighbourExists(vector<vector<int>>& grid, int row, int column){
        return (row>=0 and row<grid.size() and column>=0 and column<grid[0].size());
    }

public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;        

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> takenTime(m,vector<int>(n,inf));

        using pii = pair<int, pair<int,int>>;
        priority_queue<pii,vector<pii>,greater<pii>> pq;

        pq.push({0,{0,0}});
        takenTime[0][0] = 0;

        while(!pq.empty()){
            int curTakenTime = pq.top().first;
            int vRow = pq.top().second.first;
            int vColumn =  pq.top().second.second;
            pq.pop();

            if(vRow == m-1 and vColumn == n-1) return curTakenTime;
            if(curTakenTime != takenTime[vRow][vColumn]) continue;

            for(auto dir: directions){
                int toRow = vRow + dir.first;
                int toColumn = vColumn + dir.second;

                if(neighbourExists(grid, toRow, toColumn)){
                    int newTime;
                    int diff = grid[toRow][toColumn] - curTakenTime;
                    if(diff>1){
                        if(diff%2) newTime = grid[toRow][toColumn];
                        else newTime = grid[toRow][toColumn]+1;
                    }
                    else newTime = curTakenTime+1;

                    if(takenTime[toRow][toColumn] > newTime){
                        takenTime[toRow][toColumn] = newTime;
                        pq.push({takenTime[toRow][toColumn],{toRow,toColumn}});
                    }
                }
            }
        }
        return takenTime[m-1][n-1];
    }
};