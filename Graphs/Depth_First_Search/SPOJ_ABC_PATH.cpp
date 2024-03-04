#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=55;
int height,width;
char grid[mx][mx];
int cntLenght[mx][mx];
bool visited[mx][mx];
map<pair<int,int>,vector<pair<int,int>>> adjList;

void makeList(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            vector<pair<char,pair<int,int>>> tempList;
            if(j) tempList.push_back({grid[i][j-1],{i,j-1}}); //left
            if(j<width-1) tempList.push_back({grid[i][j+1],{i,j+1}}); //right
            if(i){
                tempList.push_back({grid[i-1][j],{i-1,j}}); //up
                if(j) tempList.push_back({grid[i-1][j-1],{i-1,j-1}}); //upperLeft
                if(j<width-1) tempList.push_back({grid[i-1][j+1],{i-1,j+1}}); //upperRight
            }
            if(i<height-1){
                tempList.push_back({grid[i+1][j],{i+1,j}}); //down
                if(j) tempList.push_back({grid[i+1][j-1],{i+1,j-1}}); //lowerLeft
                if(j<width-1) tempList.push_back({grid[i+1][j+1],{i+1,j+1}}); //lowerRight
            }
            sort(tempList.begin(),tempList.end());

            for(auto it: tempList){
                adjList[{i,j}].push_back({it.second.first,it.second.second});
            }
        }
    }
}
void printList(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            for(auto it: adjList[{i,j}]) cout<<"["<<it.first<<" "<<it.second<<"]"<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}

void DFS(int sourceX, int sourceY,int lastX, int lastY){
    if(lastX==-1 and lastY==-1) cntLenght[sourceX][sourceY]=1;
    else cntLenght[sourceX][sourceY]=cntLenght[lastX][lastY]+1;

    visited[sourceX][sourceY]=true;

    for(auto it: adjList[{sourceX,sourceY}]){
        if(!visited[it.first][it.second]){
            if(grid[it.first][it.second]!=grid[sourceX][sourceY]+1) continue;
            DFS(it.first,it.second,sourceX,sourceY);
        }
    }
}
void makeZero(){
    for(int i=0; i<mx; i++){
        for(int j=0; j<mx; j++){
            cntLenght[i][j]=0;
            visited[i][j]=false;
        }
    }
}
void solve(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++) cin>>grid[i][j];
    }
    makeList();
    // printList();

    int ans=0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(grid[i][j]=='A'){
                DFS(i,j,-1,-1);
                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        ans=max(ans,cntLenght[i][j]);
                    }
                }
                makeZero();
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    int t=1;
    while(1){
        cin>>height>>width;
        if(height and width){
            cout<<"Case "<<t<<": ";
            solve();
            t++;
        }
        else break;
    }
    return 0;
}