class Solution {
public:
    pair<int,int> parent[310][310];
    int setRank[310][310];
    void makeSet(){
        for(int i=0; i<310; i++)
            for(int j=0; j<310; j++)
                parent[i][j]=make_pair(i,j);
    }
    pair<int,int> findSet(int x, int y){
        if(parent[x][y].first==x and parent[x][y].second==y)
            return make_pair(x,y);
        return parent[x][y]=findSet(parent[x][y].first,parent[x][y].second);
    }
    void unionSet(int a1, int a2, int b1, int b2){
        pair<int,int> a=findSet(a1,a2);
        pair<int,int> b=findSet(b1,b2);

        if(setRank[a.first][a.second]<setRank[b.first][b.second])
            swap(a,b);
        parent[b.first][b.second]=a;
        if(setRank[a.first][a.second]==setRank[b.first][b.second])
            setRank[a.first][a.second]++;
    }
    int numIslands(vector<vector<char>>& grid) {
        makeSet();

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m-1; j++){
                if(grid[i][j]==grid[i][j+1])
                    unionSet(i,j,i,j+1);
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==grid[i+1][j])
                    unionSet(i,j,i+1,j);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                auto p=findSet(i,j);
            }
        }
        int result=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(parent[i][j].first==i and parent[i][j].second==j and grid[i][j]=='1')
                    result++;
            }
        }
        return result;
    }
};