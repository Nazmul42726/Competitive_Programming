// Problem Link: https://cses.fi/problemset/task/1628

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int n1 = n >> 1;
    int n2 = n - n1;

    vector<int> tmp1, tmp2;
    for(int i=0; i<n; i++){
        if(i < n1) tmp1.push_back(a[i]);
        else tmp2.push_back(a[i]);
    }

    vector<int> sum;
    for(int i=0; i<(1LL << n1); i++){
        int idx = 0, mask = i;
        int tmpSum = 0;
        while(mask){
            if(mask & 1) tmpSum += tmp1[idx];
            mask >>= 1;
            idx++;
        }
        sum.push_back(tmpSum);
    }
    sort(sum.begin(), sum.end());

    int result = 0;
    for(int i=0; i<(1LL << n2); i++){
        int idx = 0, mask = i;
        int tmpSum = 0;
        while(mask){
            if(mask & 1) tmpSum += tmp2[idx];
            mask >>= 1;
            idx++;
        }
        int target = x - tmpSum;
        int cnt = upper_bound(sum.begin(), sum.end(), target) - lower_bound(sum.begin(), sum.end(), target);
        result += cnt;
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
