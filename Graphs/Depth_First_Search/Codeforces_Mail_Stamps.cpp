#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

map<ll,vector<ll>> adjList;
map<ll,ll> notVisited;

void DFS(ll source){
    notVisited[source]=0;
    cout<<source<<" ";
    for(auto neighbour: adjList[source]){
        if(notVisited[neighbour])
            DFS(neighbour);
    }
}
void solve(){
    ll n;
    ll source;
    cin>>n;
    for(ll i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);

        notVisited[x]++;
        notVisited[y]++;
    }
    for(auto cities: notVisited){
        if(cities.second==1)
            source=cities.first;
    }
    DFS(source);
    cout<<endl;   
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}