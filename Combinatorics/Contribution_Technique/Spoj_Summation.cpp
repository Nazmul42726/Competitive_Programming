#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 100000007;
const int mxN = 1010;

vector<int> p2(mxN);

void solve(){
    int n;
    cin>>n;

    int result = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;

        int cntr = (p2[n-1] * x) % mod;
        result = (result + cntr) % mod;
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    p2[0] = 1;
    for(int i = 1; i<mxN; i++){
        p2[i] = p2[i-1]*2;
        p2[i] %= mod;
    }

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
