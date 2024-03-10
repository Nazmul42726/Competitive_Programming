#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int maxN=1e3+10;
const int exponent=10;

int table[maxN][exponent+1][maxN];
int logTable[maxN+1];

void makeLogTable(){
    logTable[1]=0;
    for(ll i=2; i<=maxN; i++)
        logTable[i]=logTable[i/2]+1;
}
void makeTableForRows(vector<ll> givenArray, ll row){
    ll N=givenArray.size();
    copy(givenArray.begin(),givenArray.end(),table[row][0]);

    for(ll i=1; i<=exponent; i++)
        for(ll j=0; j+(1<<i)<=N; j++)
            table[row][i][j]=min(table[row][i-1][j],table[row][i-1][j+(1<<(i-1))]);
}
void makeTableForBlocks(vector<ll> givenArray, ll row){
    ll N=givenArray.size();
    copy(givenArray.begin(),givenArray.end(),table[row][0]);

    for(ll i=1; i<=exponent; i++)
        for(ll j=0; j+(1<<i)<=N; j++)
            table[row][i][j]=min(table[row][i-1][j],table[row][i-1][j+(1<<(i-1))]);
}
ll findMinimumInRows(ll left, ll right, ll row){
    ll range=right-left+1;
    ll logRange=logTable[range];

    ll minimum=min(table[row][logRange][left],table[row][logRange][right-(1<<logRange)+1]);
    return minimum;
}
ll findMinimumInBlocks(ll left, ll right, ll row){
    ll range=right-left+1;
    ll logRange=logTable[range];

    ll minimum=min(table[row][logRange][left],table[row][logRange][right-(1<<logRange)+1]);
    return minimum;
}

void solve(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<ll>> grid(n,vector<ll>(m));

    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++) cin>>grid[i][j];
    
    for(ll i=0; i<n; i++) makeTableForRows(grid[i],i);

    vector<vector<ll>> gridForColumnMinimums(m-b+1,vector<ll>(n));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m-b+1; j++)
            gridForColumnMinimums[j][i]=findMinimumInRows(j,j+b-1,i);
    }
    for(ll i=0; i<m-b+1; i++) makeTableForBlocks(gridForColumnMinimums[i],i);

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            grid[i][j]=grid[i][j];
            if(i) grid[i][j]+=grid[i-1][j];
            if(j) grid[i][j]+=grid[i][j-1];
            if(i and j) grid[i][j]-=grid[i-1][j-1];
        }
    }

    vector<pair<ll,pair<ll,ll>>> costWithID;

    for(ll i=0; i<=n-a; i++){
        for(ll j=0; j<=m-b; j++){
            ll totalHeight=grid[i+a-1][j+b-1];
            if(i) totalHeight-=grid[i-1][j+b-1];
            if(j) totalHeight-=grid[i+a-1][j-1];
            if(i and j) totalHeight+=grid[i-1][j-1];
            ll minimumHeight=1e9+10;

            minimumHeight=findMinimumInBlocks(i,i+a-1,j);

            ll cost=totalHeight-(a*b*minimumHeight);

            costWithID.push_back({cost,{i,j}});
        }
    }
    sort(costWithID.begin(),costWithID.end());
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<ll> id1,id2,costs;

    for(auto it: costWithID){
        ll xID=it.second.first,yID=it.second.second;
        if(!visited[xID][yID]){
            for(ll i=max(xID-a+1,0ll); i<xID+a; i++){
                for(ll j=max(yID-b+1,0ll); j<yID+b; j++)
                    visited[i][j]=true;
            }
            id1.push_back(xID+1);
            id2.push_back(yID+1);
            costs.push_back(it.first);
        }
    }

    ll resultSize=costs.size();
    cout<<resultSize<<endl;
    for(ll i=0; i<resultSize; i++){
        cout<<id1[i]<<" "<<id2[i]<<" ";
        cout<<costs[i]<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    makeLogTable();
    solve();
    return 0;
}