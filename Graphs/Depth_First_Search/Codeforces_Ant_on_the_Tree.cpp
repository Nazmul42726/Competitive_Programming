#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=310;
int n,cntLeafs=0;
vector<bool> visited(N,false);
vector<vector<int>> adjList(N);
vector<int> childCnt(N);

int countLeafs(int root){                              //DFS
    visited[root]=true;
    if(adjList[root].size()==1 and visited[adjList[root][0]])
        cntLeafs++;
    else{
        for(auto neighbour: adjList[root]){
            if(!visited[neighbour])
                countLeafs(neighbour);
        }
    }
}
void countChild(int root){                             //BFS
    visited=vector<bool>(N,false);
    queue<int> q;
    q.push(root);
    visited[root]=true;
    
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(auto neighbour: adjList[current]){
            if(!visited[neighbour]){
                childCnt[current]++;
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
}
bool getPath(int start, int end, vector<int>& path){    //DFS
    visited[start]=true;
    if(start==end) return true;     //excluding the end node

    path.push_back(start);

    for(auto neighbour: adjList[start]){
        if(!visited[neighbour])
            if(getPath(neighbour,end,path))
                return true;
    }
    visited[path.back()]=false;
    path.pop_back();
    return false;
}
void solve(){
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    countLeafs(1);
    countChild(1);
    
    vector<int> destinationOrder(1+cntLeafs+1);
    destinationOrder[0]=destinationOrder[cntLeafs+1]=1;

    for(int i=1; i<=cntLeafs; i++) cin>>destinationOrder[i];
    
    vector<int> path;
    for(int i=0; i<=cntLeafs; i++){
        visited=vector<bool>(N,false);
        getPath(destinationOrder[i],destinationOrder[i+1],path);
    }
    path.push_back(1);
    
    vector<int> visitCnt(n+1,0);
    for(auto it: path){
        visitCnt[it]++;
        if(visitCnt[it]>childCnt[it]+1){
            cout<<-1<<endl;
            return;
        }
    }
    for(auto it: path)
        cout<<it<<" ";
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}