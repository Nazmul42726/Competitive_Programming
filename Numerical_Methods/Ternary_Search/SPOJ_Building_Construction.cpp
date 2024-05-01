#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll N;
vector<ll> height(10001),cost(10001);

ll costCnt(ll reqHeight){
    ll result=0;
    for(ll i=0; i<N; i++)
        result+=abs(height[i]-reqHeight)*cost[i];
    return result;
}
ll ternarySearch(){
    double low=0.0, high=10010.0,errorLimit=1e-9;
    while(high-low>errorLimit){
        double mid1=low+(high-low)/3.0;
        double mid2=high-(high-low)/3.0;

        if(costCnt(mid1)>costCnt(mid2)) low=mid1;
        else high=mid2;
    }
    return min(costCnt(floor(low)),costCnt(ceil(low)));
}
void solve(){
    scanf("%lld", &N);
    for(ll i=0; i<N; i++) scanf("%lld", &height[i]);
    for(ll i=0; i<N; i++) scanf("%lld", &cost[i]);

    printf("%lld\n",ternarySearch());
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // optimize();

    ll t;
    scanf("%lld",&t);
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}