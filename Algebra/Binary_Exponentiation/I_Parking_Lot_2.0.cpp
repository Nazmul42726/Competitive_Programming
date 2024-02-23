#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll calculate(ll base, ll expo){
    if(base==0) return 0;
    if(expo==0) return 1;

    ll result=calculate(base,expo/2);
    result*=result;
    if(expo%2) result*=base;

    return result;
}
void solve(){
    ll carCnt;
    cin>>carCnt;
    ll frontEndCntCombo=carCnt-2;
    ll ans=0;   //for each make
    ans=2*3*calculate(4,frontEndCntCombo-1);
    ans*=4;     //for all make
    if(carCnt<4) cout<<ans<<endl;
    else{
        ll sidesOfMidSegment=2;
        ll midSegmentPositions=carCnt-3;
        ll bothSideCombo=calculate(3,sidesOfMidSegment)*calculate(4,carCnt-4)*midSegmentPositions;  //for each make
        bothSideCombo*=4;  //for all make
        ans+=bothSideCombo;
        cout<<ans<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}