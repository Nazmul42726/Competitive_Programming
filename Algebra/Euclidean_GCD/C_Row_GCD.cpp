#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n,m;
    cin>>n>>m;
    ll first;
    cin>>first;
    ll gcd=0,x;
    for(ll i=1; i<n; i++){
        cin>>x;
        gcd=__gcd(gcd,abs(first-x));
        //gcd1=gcd(a1,a2-a1,a3-a1,a4-a1,..)
    }
    for(ll i=0; i<m; i++){
        cin>>x;
        cout<<__gcd((x+first),gcd)<<" ";    
        //gcd2=gcd(a1+x,a2+x,a3+x,...)
        //    =gcd(a1+x,(a2+x)-(a1+x),(a2+x)-(a1+x),...) 
        //                                  [since gcd(a,b)=gcd(a,b-a), b-a>=0]
        //    =gcd(a1+x,a2-a1,a3-a1,a4-a1,...)
        //    =gcd1
    }
    cout<<endl;
}

signed main(){
    optimize();
    solve();
    return 0;
}