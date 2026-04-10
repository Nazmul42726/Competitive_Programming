#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 998244353;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i] = (a[i] * (i+1) * (n-i));
    }
    for(int i=0; i<n; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int result = 0;
    for(int i=0; i<n; i++){
        int contr = ((a[i] % mod) *b[i]) % mod;
        result = (result + contr) % mod;
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
