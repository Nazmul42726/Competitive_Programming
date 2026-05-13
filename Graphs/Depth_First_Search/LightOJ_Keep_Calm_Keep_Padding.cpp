#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void dfs(int src, int prnt, vector<vector<int>>& adjList,
         vector<int>& subTreeSize, vector<int>& bikesInSubTree, 
         vector<int>& bikeCnt){

    subTreeSize[src] = 1;
    bikesInSubTree[src] = bikeCnt[src];

    for(auto it: adjList[src]){
        if(it != prnt){
            dfs(it, src, adjList, subTreeSize, bikesInSubTree, bikeCnt);
            subTreeSize[src] += subTreeSize[it];
            bikesInSubTree[src] += bikesInSubTree[it];
        }
    }
}

void dfs1(int src, int prnt, vector<vector<int>>& adjList,
         vector<int>& subTreeSize, vector<int>& bikesInSubTree, 
         vector<int>& bikeCnt, vector<pair<int,int>>& result,
         int k, int& rem){
    
    if(bikeCnt[src] >= k){
        result.push_back({src+1, -1*(bikeCnt[src] - k)});
        rem += bikeCnt[src] - k;
        bikeCnt[src] = k;
    }
    else result.push_back({src+1, 0});

    sort(adjList[src].begin(), adjList[src].end(), [&bikesInSubTree, &subTreeSize, &k](int a, int b){
        int surplus_a = bikesInSubTree[a] - subTreeSize[a] * k;
        int surplus_b = bikesInSubTree[b] - subTreeSize[b] * k;
        return surplus_a > surplus_b;
    });
    
    for(auto it: adjList[src]){
        if(it != prnt){
            dfs1(it, src, adjList, subTreeSize, bikesInSubTree, bikeCnt, result, k, rem);
            result.push_back({src+1, 0});
        }
    }

    if(bikeCnt[src] < k){
        result.back().second += (k - bikeCnt[src]); 
        rem -= (k - bikeCnt[src]); 
        bikeCnt[src] = k;
    }
}

void solve(){
    int n, k;
    cin>>n>>k;

    vector<vector<int>> adjList(n);
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> bikeCnt(n);
    for(int i=0; i<n; i++){
        cin>>bikeCnt[i];
    }

    vector<int> subTreeSize(n, 0);
    vector<int> bikesInSubTree(n, 0);

    dfs(0, 0, adjList, subTreeSize, bikesInSubTree, bikeCnt);

    vector<pair<int,int>> result;
    int rem = 0;
    dfs1(0, 0, adjList, subTreeSize, bikesInSubTree, bikeCnt, result, k, rem);

    // for(int i=0; i<n; i++){
    //     cout<<i+1<<" "<<subTreeSize[i]<<" "<<bikesInSubTree[i]<<endl;
    // }

    if(result.size() == 2*n - 1){
        cout<<"YES"<<endl;
        for(auto it: result){
            cout<<it.first<<" ";
            cout<<it.second<<endl;
        }
    }
    else cout<<"NO"<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
