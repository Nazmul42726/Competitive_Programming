#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int b;
        cin>>b;
        int c=upper_bound(a.begin(),a.end(),b)-a.begin();
        cout<<c<<endl;
    }
}
main(){
    solve();
}