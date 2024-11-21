#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin>>n;
    vector<int> dp(3);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        vector<int> tmp(3);
        tmp[0] = max(dp[0],max(dp[1],dp[2]));       //taking rest today
        if(x==1 or x==3)                            //contest today, result 
            tmp[1] = max(dp[0],dp[2])+1;            // = max result of (taking rest, going gym) yesterday +1;
        if(x==2 or x==3)                            //gym today, result
            tmp[2] = max(dp[0],dp[1])+1;            // = max result of (taking rest, participating contest) yesterday + 1;
        
        swap(dp, tmp);
    }
    int result = n - max(dp[0],max(dp[1],dp[2]));
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}