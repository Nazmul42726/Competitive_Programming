#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int sum = 0;
    int result = -1 * (1e9+7);
    for(int i=0; i<n; i++){
        if(sum + a[i] < a[i]) sum = a[i];
        else sum += a[i];

        result = max(result, sum);
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}