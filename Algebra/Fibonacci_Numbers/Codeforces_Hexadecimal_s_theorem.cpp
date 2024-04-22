#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n;
    cin>>n;
    if(n==0) cout<<"0 0 0"<<endl;
    else if(n==1) cout<<"0 0 1"<<endl;
    else{
        ll last=0, current=1;
        while(current<n){
            ll temp=current;
            current+=last;
            last=temp;
        }
        ll secondLast=current-last;
        cout<<0<<" "<<secondLast<<" "<<last<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}