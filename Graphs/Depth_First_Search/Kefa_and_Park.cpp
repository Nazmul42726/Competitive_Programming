#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e5+10;
vector<vector<int>> adjList(mx);
vector<int> parent(mx,-1),child(mx,0);
vector<int> catsPresence(mx,0);
vector<pair<int,int>> catsCnt(mx,{0,0});
vector<bool> visited(mx,false);

void DFS(int sourse){
    visited[sourse]=true;
    if(catsPresence[sourse]){
        if(parent[sourse]==-1) catsCnt[sourse].first=1,catsCnt[sourse].second=1;
        else{
            catsCnt[sourse].second=catsCnt[parent[sourse]].second+1;
            catsCnt[sourse].first=max(catsCnt[parent[sourse]].first,catsCnt[sourse].second);
        }
    }
    else{
        if(parent[sourse]==-1) catsCnt[sourse].first=0,catsCnt[sourse].second=0;
        else catsCnt[sourse].first=catsCnt[parent[sourse]].first;
    }
    for(auto it: adjList[sourse]){
        if(!visited[it]){
            child[sourse]++;
            parent[it]=sourse;
            DFS(it);            
        }
    }
}

void solve(){
    int nodes,cats;
    cin>>nodes>>cats;
    
    for(int i=1; i<=nodes; i++) cin>>catsPresence[i];
    for(int i=1; i<nodes; i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    DFS(1);

    int ans=0;
    for(int i=1; i<=nodes; i++){
        if(child[i]==0 and catsCnt[i].first<=cats) ans++;
    }

    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}