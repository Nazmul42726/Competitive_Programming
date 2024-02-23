#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> cnt_combination(29);
void calculate(){
    cnt_combination[0]=1;
    cnt_combination[1]=3;
    for(ll i=2; i<29; i++) cnt_combination[i]=4*cnt_combination[i-1];
}
void solve(){
    ll carCnt;
    cin>>carCnt;
    ll frontEndCnt=carCnt-2;
    ll ans=0;   //for each make
    for(ll i=0; i<=frontEndCnt; i++){
        ans+=(cnt_combination[i]*cnt_combination[frontEndCnt-i]);     //counting combo for both side
    }
    ans*=4;     //for all make
    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    calculate();
    solve();

    return 0;
}