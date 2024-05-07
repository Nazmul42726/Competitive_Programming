#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=45;
int n,m,power;
int dis[N][N];
vector<string> vs(N);

void BFS(int sourceX, int sourceY){
    queue<pair<int,int>> q;
    q.push(make_pair(sourceX,sourceY));
    dis[sourceX][sourceY]=0;

    while(!q.empty()){
        int currentX=q.front().first;
        int currentY=q.front().second;
        q.pop();
        int add=0;
        if(vs[currentX][currentY]=='s')
            add=1;
        if(currentX>0){
            if(vs[currentX-1][currentY]!='#' and dis[currentX-1][currentY]>dis[currentX][currentY]+add){
                dis[currentX-1][currentY]=dis[currentX][currentY]+add;
                q.push(make_pair(currentX-1,currentY));
            }
        }
        if(currentX<n-1){
            if(vs[currentX+1][currentY]!='#' and dis[currentX+1][currentY]>dis[currentX][currentY]+add){
                dis[currentX+1][currentY]=dis[currentX][currentY]+add;
                q.push(make_pair(currentX+1,currentY));
            }
        }
        if(currentY>0){
            if(vs[currentX][currentY-1]!='#' and dis[currentX][currentY-1]>dis[currentX][currentY]+add){
                dis[currentX][currentY-1]=dis[currentX][currentY]+add;
                q.push(make_pair(currentX,currentY-1));
            }
        }
        if(currentY<m-1){
            if(vs[currentX][currentY+1]!='#' and dis[currentX][currentY+1]>dis[currentX][currentY]+add){
                dis[currentX][currentY+1]=dis[currentX][currentY]+add;
                q.push(make_pair(currentX,currentY+1));
            }
        }
    }
}

void solve(){
    cin>>n>>m>>power;
    for(int i=0; i<n; i++)
        cin>>vs[i];

    int treasureX,treasureY;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dis[i][j]=1e9;
            if(vs[i][j]=='x'){
                treasureX=i;
                treasureY=j;
            }
        }
    }
    BFS(treasureX,treasureY);
    int result=1e9;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vs[i][j]=='@'){
                result=min(result,dis[i][j]*2);
            }
        }
    }
    if(power>=result)
        cout<<"SUCCESS"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}