#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n,m,k;

bool cntPillow(ll x){
    ll total=x;
    ll leftCnt=k-1;
    ll rightCnt=n-k;
    if(leftCnt>=x-1){
        total+=(x*(x-1))/2;
        total+=leftCnt-(x-1);
    }
    else{
        total+=(x*(x-1))/2;
        ll y=x-1-leftCnt;
        total-=(y*(y+1))/2;
    }
    
    if(rightCnt>=x-1){
        total+=(x*(x-1))/2;
        total+=rightCnt-(x-1);
    }
    else{
        total+=(x*(x-1))/2;
        ll y=x-1-rightCnt;
        total-=(y*(y+1))/2;
    }
    return total<=m;
}
void solve(){
    cin>>n>>m>>k;

    ll l=0,r=m;
    while(r-l>1){
        ll mid=l+(r-l)/2;
        if(cntPillow(mid)) l=mid;
        else r=mid-1;
    }
    if(cntPillow(r))
        cout<<r<<endl;
    else cout<<l<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}