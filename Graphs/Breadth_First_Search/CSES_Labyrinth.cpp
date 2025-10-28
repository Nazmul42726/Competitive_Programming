#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> parent;

int bfs(int source, int dest, vector<vector<int>>& adjList){
    int n = adjList.size();
    vector<bool> visited(n,false);
    parent = vector<int>(n,-1);

    queue<pair<int,int>> q;
    q.push({source,0});
    visited[source] = true;
    parent[source] = 0;

    while(!q.empty()){
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        for(auto neighbour: adjList[cur]){
            if(!visited[neighbour]){
                parent[neighbour] = cur;
                if(neighbour == dest) return dist+1;
                q.push({neighbour,dist+1});
                visited[neighbour] = true;
            }
        }
    }
    return -1;
}

string path(int end, int n, int m){
    string result;
    int cur = end;

    while(parent[cur] != 0){
        int p = parent[cur];
        if(p == cur-m) result.push_back('D');
        else if(p == cur-1) result.push_back('R');
        else if(p == cur+1) result.push_back('L');
        else result.push_back('U');
        cur = parent[cur];
    }
    reverse(result.begin(), result.end());
    return result;
}
void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjList((n*m)+1);

    int start,end;
    vector<string> labyrinth(n);
    for(int i=0; i<n; i++) cin>>labyrinth[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(labyrinth[i][j] != '#'){
                int ind = (m*i)+j+1;
                if(labyrinth[i][j] == 'A') start=ind;
                else if(labyrinth[i][j] == 'B') end=ind;
                
                if(j>0 and labyrinth[i][j-1] != '#'){
                    adjList[ind-1].push_back(ind);
                    adjList[ind].push_back(ind-1);
                }
                if(i>0 and labyrinth[i-1][j] != '#'){
                    adjList[ind-m].push_back(ind);
                    adjList[ind].push_back(ind-m);
                }
                if(j<m-1 and labyrinth[i][j+1] != '#'){
                    adjList[ind+1].push_back(ind);
                    adjList[ind].push_back(ind+1);
                }
                if(i<n-1 and labyrinth[i+1][j] != '#'){
                    adjList[ind+m].push_back(ind);
                    adjList[ind].push_back(ind+m);
                }
            }
        }
    }

    int distance = bfs(start,end,adjList);
    if(distance == -1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl<<distance<<endl;
    cout<<path(end,n,m)<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}