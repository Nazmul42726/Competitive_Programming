#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll k,n,ans=0;
    string s;
    cin>>k>>s;
    n=s.size();

    if(k==0){
        ll lastOne=-1;
        for(ll i=0; i<=n; i++){
            if(s[i]=='1' or i==n){
                ll zeroCnt=i-lastOne-1;
                ans+=((zeroCnt*(zeroCnt+1))/2);
                lastOne=i;
            }
            if(i==n) break;
        }
        cout<<ans<<endl;
        return;
    }

    vector<ll> a(n+1,0);
    for(ll i=1; i<=n; i++){
        if(s[i-1]=='1') a[i]++;
        a[i]+=a[i-1];
    }

    for(ll i=1,j=1; i<=n and j<=n; ){
        if(a[i]-a[j-1]==k){
            ll leftzeros,rightzeros;
            ll nextRone=(ll)(upper_bound(a.begin(),a.end(),a[i])-a.begin());
            ll nextLone=(ll)(upper_bound(a.begin(),a.end(),a[j])-a.begin());
            ll prevOne=(ll)(lower_bound(a.begin(),a.end(),a[j-1])-a.begin());

            if(s[j-1]=='0') leftzeros=nextLone-prevOne;
            else leftzeros=j-prevOne;
            rightzeros=nextRone-i;

            ans+=(leftzeros*rightzeros);

            i=min((ll)(upper_bound(a.begin(),a.end(),a[i])-a.begin()),n+1);
            j=min((ll)(upper_bound(a.begin(),a.end(),a[j])-a.begin()),n);
        }
        else if((a[i]-a[j-1])<k){
            if(i==n) break;
            i++;
        }
        else j++;
    }
    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}