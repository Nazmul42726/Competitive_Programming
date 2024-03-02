#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

map<pair<int,int>,vector<pair<int,int>>> adjList;
void makeList(){
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            if(i>2){
                if(j<8) adjList[{i,j}].push_back({i-2,j+1});
                if(j>1) adjList[{i,j}].push_back({i-2,j-1});
            }
            if(i<7){
                if(j<8) adjList[{i,j}].push_back({i+2,j+1});
                if(j>1) adjList[{i,j}].push_back({i+2,j-1});
            }
            if(j>2){
                if(i<8) adjList[{i,j}].push_back({i+1,j-2});
                if(i>1) adjList[{i,j}].push_back({i-1,j-2});
            }
            if(j<7){
                if(i<8) adjList[{i,j}].push_back({i+1,j+2});
                if(i>1) adjList[{i,j}].push_back({i-1,j+2});
            }
        }
    }
}
void BFS(int x1, int y1, vector<vector<int>>& moveCnt, vector<vector<bool>>& visited){
    moveCnt[x1][y1]=0;
    visited[x1][y1]=true;
    queue<pair<int,int>> q;
    q.push({x1,y1});

    while(!q.empty()){
        int vx=q.front().first;
        int vy=q.front().second;
        q.pop();
        for(auto it: adjList[{vx,vy}]){
            if(!visited[it.first][it.second]){
                visited[it.first][it.second]=true;
                moveCnt[it.first][it.second]=moveCnt[vx][vy]+1;
                q.push({it.first,it.second});
            }
        }
    }
}
void solve(){
    string start,end;
    cin>>start>>end;
    int x1=start[0]+1-'a';
    int y1=start[1]-'0';
    int x2=end[0]+1-'a';
    int y2=end[1]-'0';

    vector<vector<int>> moveCnt(9,vector<int>(9,0));
    vector<vector<bool>> visited(9,vector<bool>(9,false));

    BFS(x1,y1,moveCnt,visited);
    
    cout<<moveCnt[x2][y2]<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    makeList();
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}