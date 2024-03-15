#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> BFS(int source, int nodes, vector<vector<int>>& adjList){
    vector<int> distance(nodes+1,-1);
    vector<bool> visited(nodes+1,false);

    queue<int> q;
    q.push(source);
    visited[source]=true;
    distance[source]=0;

    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(auto neighbor: adjList[current]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
                distance[neighbor]=distance[current]+1;
            }
        }
    }
    return distance;
}

void solve(){
    int nodes,edges;
    cin>>nodes>>edges;

    vector<vector<int>> adjList(nodes+1);
    for(int i=0; i<edges; i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    int starts,finish,robber;
    cin>>starts>>finish>>robber;

    vector<int> distanceS=BFS(starts,nodes,adjList);
    vector<int> distanceF=BFS(finish,nodes,adjList);
    vector<int> distanceR=BFS(robber,nodes,adjList);

    map<int,int> farthestPath;  //from robber

    for(int i=1; i<=nodes; i++){
        if(distanceS[i]+distanceF[i]==distanceS[finish]){    // i is on one of the shortest path
            if(farthestPath.find(distanceS[i])==farthestPath.end())
                farthestPath[distanceS[i]]=distanceR[i];
            else
                farthestPath[distanceS[i]]=max(farthestPath[distanceS[i]],distanceR[i]);
        }
    }
    
    int closestPoint=INT_MAX;  //on the farthest path from robber
    for(auto it: farthestPath)
        closestPoint=min(closestPoint,it.second);
    
    cout<<closestPoint<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}