#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    vector<pair<ll,ll>> a(n,{-1,-1});
    stack<ll> lp;
    for(ll i=0; i<n; i++){
        if(s[i]=='(') lp.push(i);
        if(s[i]==')'){
            if(lp.empty()) a[i]={-1,-1};
            else{
                a[i].first=lp.top();
                a[i].second=(s[lp.top()-1]==')' and a[lp.top()-1].second!=-1)?a[lp.top()-1].second:a[i].first;
                lp.pop();
            }
        }
    }
    map<ll,ll> m;
    for(ll i=0; i<n; i++){
        if(a[i].first!=-1){
                m[i-a[i].first+1]++;
            if(a[i].second!=a[i].first){
                m[i-a[i].second+1]++;
            }
        }
    }
    if(m.size()){
        auto it=*(--m.end());
        cout<<it.first<<" "<<it.second<<endl;
    }
    else cout<<0<<" "<<1<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    solve();
    return 0;
}