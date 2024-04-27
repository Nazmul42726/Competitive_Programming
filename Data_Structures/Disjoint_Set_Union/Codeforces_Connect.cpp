#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,x1,y11,x2,y2;
char grid[55][55];
pair<int,int> parent[55][55];
int setRank[55][55];

pair<int,int> findSet(int x, int y){
    if(parent[x][y]==make_pair(x,y)) return make_pair(x,y);
    return parent[x][y]=findSet(parent[x][y].first, parent[x][y].second);
}
void unionSet(int a1, int a2, int b1, int b2){
    pair<int,int> a=findSet(a1,a2);
    pair<int,int> b=findSet(b1,b2);
    if(setRank[b.first][b.second]>setRank[a.first][a.second]) swap(a,b);
    parent[b.first][b.second]=a;
    if(setRank[a.first][a.second]==setRank[b.first][b.second])
        setRank[a.first][a.second]++;
}
void solve(){
    cin>>n>>x1>>y11>>x2>>y2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>grid[i][j];
            parent[i][j]={i,j};
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<n; j++){
            if(grid[i][j]==grid[i][j+1] and grid[i][j]=='0')
                unionSet(i,j,i,j+1);
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]==grid[i+1][j] and grid[i][j]=='0')
                unionSet(i,j,i+1,j);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            auto x=findSet(i,j);
        }
    }
    if(parent[x1][y11]==parent[x2][y2]){
        cout<<0<<endl;
        return;
    }
    set<pair<int,int>> stBegin,stEnd;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(parent[i][j]==parent[x1][y11])
                stBegin.insert(make_pair(i,j));
            if(parent[i][j]==parent[x2][y2])
                stEnd.insert(make_pair(i,j));
        }
    }
    int minCost=1e9;
    for(auto it: stBegin){
        for(auto itt: stEnd){
            int cost=pow((itt.first-it.first),2)+pow((itt.second-it.second),2);
            minCost=min(cost,minCost);
        }
    }
    cout<<minCost<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}