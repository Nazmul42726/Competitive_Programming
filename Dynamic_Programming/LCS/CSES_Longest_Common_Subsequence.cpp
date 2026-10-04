#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n, m;
    cin>>n>>m;

    vector<int> a(n+1), b(m+1);

    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout<<dp[n][m]<<endl;
    vector<int> result;
    int x = n, y = m;
    
    while(x and y){
        if(dp[x][y] == dp[x-1][y-1]+1 and (dp[x-1][y] < dp[x][y] and dp[x][y-1] < dp[x][y])){
            result.push_back(a[x]);
            x--;
            y--;
        }
        else if(dp[x][y] == dp[x-1][y]) x--;
        else y--;
    }
    reverse(result.begin(), result.end());
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}