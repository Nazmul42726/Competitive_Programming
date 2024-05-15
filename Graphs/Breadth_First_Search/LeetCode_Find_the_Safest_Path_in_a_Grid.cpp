class Solution {
public:
    static const int N=405;
    static const int inf=1e9+7;
    int distance[N][N];
    bool visited[N][N];

    void BFS(int x, int y, vector<vector<int>>& grid){
        int n=grid.size();
        queue<pair<int,int>> q;
        q.push({x,y});

        while(!q.empty()){
            int curX=q.front().first;
            int curY=q.front().second;
            q.pop();
            if(curX and distance[curX-1][curY]>(distance[curX][curY]+1)){
                q.push({curX-1,curY});
                distance[curX-1][curY]=distance[curX][curY]+1;
            }
            if(curY and distance[curX][curY-1]>(distance[curX][curY]+1)){
                q.push({curX, curY-1});
                distance[curX][curY-1]=distance[curX][curY]+1;
            }
            if(curX<n-1 and distance[curX+1][curY]>(distance[curX][curY]+1)){
                q.push({curX+1, curY});
                distance[curX+1][curY]=distance[curX][curY]+1;
            }
            if(curY<n-1 and distance[curX][curY+1]>(distance[curX][curY]+1)){
                q.push({curX, curY+1});
                distance[curX][curY+1]=distance[curX][curY]+1;
            }
        }
    }
    bool bfs(int minDistance, vector<vector<int>>& grid){
        if(distance[0][0]<minDistance) return false;
        int n=grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                visited[i][j]=false;
        }
        visited[0][0]=true;
        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            int curX=q.front().first;
            int curY=q.front().second;
            q.pop();
            if(curX and !visited[curX-1][curY] and distance[curX-1][curY]>=minDistance){
                q.push({curX-1, curY});
                visited[curX-1][curY]=true;
            }
            if(curY and !visited[curX][curY-1] and distance[curX][curY-1]>=minDistance){
                q.push({curX, curY-1});
                visited[curX][curY-1]=true;
            }
            if(curX<n-1 and !visited[curX+1][curY] and distance[curX+1][curY]>=minDistance){
                q.push({curX+1, curY});
                visited[curX+1][curY]=true;
            }
            if(curY<n-1 and !visited[curX][curY+1] and distance[curX][curY+1]>=minDistance){
                q.push({curX, curY+1});
                visited[curX][curY+1]=true;
            }
        }
        return visited[n-1][n-1];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid){
        int n=grid.size();
        if(grid[0][0] or grid[n-1][n-1]) return 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                distance[i][j]=inf;
                if(grid[i][j])
                    distance[i][j]=0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) BFS(i, j, grid);
            }
        }
        int minSafeness=0, maxSafeness=n;
        while(maxSafeness-minSafeness>1){
            int mid=(minSafeness+maxSafeness)/2;

            if(bfs(mid, grid)) minSafeness=mid;
            else maxSafeness=mid-1;
        }
        if(bfs(maxSafeness, grid)) return maxSafeness;
        return minSafeness;
    }
};