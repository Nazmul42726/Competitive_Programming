#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n;
    cin>>n;

    vector<ll> c(n);
    for(ll i=0; i<n; i++){
        cin>>c[i];
    }
    vector<string> a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(2, 1e18));
    dp[0][0] = 0ll;
    dp[0][1] = c[0];

    string last = a[0];
    reverse(a[0].begin(), a[0].end());
    string tsal = a[0];

    for(ll i=1; i<n; i++){
        string cur = a[i];
        reverse(a[i].begin(), a[i].end());
        string ruc = a[i];

        if(cur >= last)
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(cur >= tsal)
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(ruc >= last)
            dp[i][1] = min(dp[i][1], dp[i-1][0]+c[i]);
        if(ruc >= tsal)
            dp[i][1] = min(dp[i][1], dp[i-1][1]+c[i]);

        last = cur;
        tsal = ruc;
    }
    ll result = min(dp[n-1][0],dp[n-1][1]);
    
    if(result == 1e18) cout<<-1<<endl;
    else cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
