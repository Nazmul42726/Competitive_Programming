#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll inf=1e18;
ll nodes,exitCell,times,edges;
ll BFS(ll source,vector<vector<pair<ll,ll>>>& adjList){
    vector<ll> timeTaken(nodes+1,inf);
    queue<ll> q;
    q.push(source);
    timeTaken[source]=0;
    
    while(!q.empty()){
        ll current=q.front();
        q.pop();
        for(auto neighbour: adjList[current]){
            if(timeTaken[neighbour.first]>timeTaken[current]+neighbour.second){
                timeTaken[neighbour.first]=timeTaken[current]+neighbour.second;
                q.push(neighbour.first);
            }
        }
    }
    return timeTaken[exitCell];
}
void solve(){
    cin>>nodes>>exitCell>>times>>edges;
    vector<vector<pair<ll,ll>>> adjList(nodes+1);
    for(ll i=0; i<edges; i++){
        ll x,y,w;
        cin>>x>>y>>w;
        adjList[x].push_back({y,w});
    }
    ll result=0;
    for(ll i=1; i<=nodes; i++){
        if(BFS(i,adjList)<=times)
            result++;
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}