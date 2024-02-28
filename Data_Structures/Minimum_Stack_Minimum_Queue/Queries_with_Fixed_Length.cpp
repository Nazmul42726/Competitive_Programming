#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];

    while(q--){
        ll d,ans=1e9;
        cin>>d;
        stack<pair<ll,ll>> st1,st2;
        for(ll i=0; i<d; i++){
            ll maximum=st1.empty()?a[i]:max(a[i],st1.top().second);
            st1.push({a[i],maximum});
        }
        for(ll i=d; i<n; i++){
            ll cur_max;
            if(st1.empty() or st2.empty())
                cur_max=st1.empty()?st2.top().second:st1.top().second;
            else
                cur_max=max(st1.top().second,st2.top().second);

            ans=min(ans,cur_max);

            if(st2.empty()){
                while(!st1.empty()){
                    ll element=st1.top().first;
                    st1.pop();
                    ll s2_max=st2.empty()?element:max(element,st2.top().second);
                    st2.push({element,s2_max});
                }
            }
            st2.pop();

            ll maximum=st1.empty()?a[i]:max(a[i],st1.top().second);
            st1.push({a[i],maximum});
        }
        ll cur_max;
        if(st1.empty() or st2.empty())
            cur_max=st1.empty()?st2.top().second:st1.top().second;
        else
            cur_max=max(st1.top().second,st2.top().second);

        ans=min(ans,cur_max);

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
