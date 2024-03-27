#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    int cities,stationCnt,distanceMax;
    cin>>cities>>stationCnt>>distanceMax;

    vector<bool> visited(cities+1,false);
    vector<int> parent(cities+1,-1);
    queue<int> q;

    for(int i=0; i<stationCnt; i++){
        int policeStation;
        cin>>policeStation;
        q.push(policeStation);
        parent[policeStation]=0;
    }

    vector<set<pair<int,int>>> adjList(cities+1);

    for(int i=1; i<cities; i++){
        int city1,city2;
        cin>>city1>>city2;
        adjList[city1].insert({city2,i});
        adjList[city2].insert({city1,i});
    }
    
    vector<int> roads(cities+1,0);

    while(!q.empty()){
        int current=q.front();
        q.pop();

        if(visited[current]) continue;
        visited[current]=true;

        for(auto neighbour: adjList[current]){
            if(neighbour.first!=parent[current]){
                if(visited[neighbour.first])
                    roads[neighbour.second]=1;
                else{
                    q.push(neighbour.first);
                    if(parent[neighbour.first]==-1)
                        parent[neighbour.first]=current;
                }
            }
        }
    }
    int removedRoadCnt=0;
    for(int i=1; i<=cities; i++)
        if(roads[i]) removedRoadCnt++;

    cout<<removedRoadCnt<<endl;
    for(int i=1; i<=cities; i++)
        if(roads[i]) cout<<i<<" ";
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}