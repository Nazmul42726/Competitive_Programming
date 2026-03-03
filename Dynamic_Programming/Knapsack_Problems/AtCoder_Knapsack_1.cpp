#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n, w;
    cin>>n>>w;

    vector<int> weight(n), value(n);
    for(int i=0; i<n; i++){
        cin>>weight[i]>>value[i];
    }

    vector<int> dp(w+1, 0);
    for(int i=0; i<n; i++){
        for(int j=w; j>=weight[i]; j--){
            dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[w]<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
