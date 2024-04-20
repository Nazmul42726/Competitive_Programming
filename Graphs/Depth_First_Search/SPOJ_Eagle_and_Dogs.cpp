#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

unordered_map<ll,unordered_map<ll,ll>> adjList;

void DFS(ll source, ll parent, ll depth, ll& maxDepth, ll& farthestNode){
    if(depth>maxDepth){
        maxDepth=depth;
        farthestNode=source;
    }
    for(auto neighbour: adjList[source]){
        ll child=neighbour.first;
        ll weight=neighbour.second;
        if(child!=parent)
            DFS(child,source,depth+weight,maxDepth,farthestNode);
    }
}
void findPath(ll start, ll parent, ll end, vector<ll>& path){
    path.push_back(start);
    if(start==end) return;
    
    for(auto neighbour: adjList[start]){
        ll child=neighbour.first;
        if(child!=parent){
            findPath(child,start,end,path);
            if(path.back()!=end)
                path.pop_back();
        }
    }
}
void dfs(ll source, ll parent, ll maxPrev, vector<ll>& result, vector<char>& visited){
    visited[source]=true;
    for(auto neighbour: adjList[source]){
        ll child=neighbour.first;
        ll weight=neighbour.second;
        if(!visited[child])
            dfs(child,source,maxPrev+weight,result,visited);
    }
    result[source]=maxPrev;
}
void solve(){
    ll n;
    cin>>n;
    adjList.clear();
    for(ll i=1; i<n; i++){
        ll x,y,d;
        cin>>x>>y>>d;
        adjList[x][y]=d;
        adjList[y][x]=d;
    }
    ll maxDepth=0;
    ll farthestNode_1=-1;   //from 1
    ll farthestNode=-1;     //from farthestNode_1
    DFS(1,-1,0,maxDepth,farthestNode_1);
    maxDepth=0;
    DFS(farthestNode_1,-1,0,maxDepth,farthestNode);

    vector<ll> path;        //diameter of the tree with maximum possible weight;
    findPath(farthestNode_1,-1,farthestNode,path);
    
    ll nn=path.size();
    vector<ll> pathWeight_L_R(nn,0);
    vector<ll> pathWeight_R_L(nn,0);
    for(ll i=1; i<nn; i++){
        pathWeight_L_R[i]=adjList[path[i-1]][path[i]];
        pathWeight_L_R[i]+=pathWeight_L_R[i-1];
    }
    for(ll i=nn-2; i>=0; i--){
        pathWeight_R_L[i]=adjList[path[i]][path[i+1]];
        pathWeight_R_L[i]+=pathWeight_R_L[i+1];
    }
    
    vector<char> visited(n+1,false);
    vector<ll> result(n+1,0);
    for(ll i=0; i<nn; i++)
        visited[path[i]]=true;

    for(ll i=0; i<nn; i++){
        ll maxWeightedSide=max(pathWeight_L_R[i],pathWeight_R_L[i]);
        dfs(path[i],path[i],maxWeightedSide,result,visited);
    }
    for(ll i=1; i<=n; i++)
        cout<<result[i]<<" ";
    cout<<endl;
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