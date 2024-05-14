class Solution {
public:
    static const int N=20;
    int distance[N][N];
    bool visited[N][N];
    map<pair<int,int>, vector<pair<int,int>>> adjList;

    void makeZero(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                distance[i][j]=0;
                visited[i][j]=false;
            }
        }
    }
    int DFS(int x, int y, vector<vector<int>>& grid){
        visited[x][y]=true;
        distance[x][y]=grid[x][y];
        for(auto it: adjList[{x,y}]){
            if(!visited[it.first][it.second]){
                int inThisPath=DFS(it.first,it.second,grid);
                distance[x][y]=max(distance[x][y],grid[x][y]+inThisPath);
            }
        }
        visited[x][y]=false;
        return distance[x][y];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    if(i and grid[i-1][j])
                        adjList[{i,j}].push_back({i-1,j});
                    if(i<m-1 and grid[i+1][j])
                        adjList[{i,j}].push_back({i+1,j});
                    if(j and grid[i][j-1])
                        adjList[{i,j}].push_back({i,j-1});
                    if(j<n-1 and grid[i][j+1])
                        adjList[{i,j}].push_back({i,j+1});
                }
            }
        }
        int result=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    makeZero();
                    result=max(result,DFS(i,j,grid));
                }
            }
        }
        return result;
    }
};