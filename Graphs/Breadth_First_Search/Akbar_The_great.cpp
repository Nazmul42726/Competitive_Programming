#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void BFS(int sourse,int range,vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& protectedBy){
    queue<pair<int,int>> q;
    protectedBy[sourse]++;
    visited[sourse]=true;
    q.push({sourse,range});

    while(!q.empty()){
        int v=q.front().first;
        int remaining=q.front().second;
        q.pop();
        if(remaining<=0) continue;
        for(auto it: adjList[v]){
            if(visited[it]) continue;
            q.push({it,remaining-1});
            visited[it]=true;
            protectedBy[it]++;
        }
    }
}

void solve(){
    int nodes,edges,soldiers;
    cin>>nodes>>edges>>soldiers;
    vector<vector<int>> adjList(nodes+1);
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<bool> visited(nodes+1,false);
    vector<pair<int,int>> strength;
    vector<int> protectedBy(nodes+1,0);

    for(int i=0; i<soldiers; i++){
        int k,s;
        cin>>k>>s;
        strength.push_back({k,s});
    }
    
    bool flag=true;
    for(auto it: strength){
        BFS(it.first,it.second,adjList,visited,protectedBy);
    }
    for(int i=1; i<=nodes; i++){
        if(protectedBy[i]!=1){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}