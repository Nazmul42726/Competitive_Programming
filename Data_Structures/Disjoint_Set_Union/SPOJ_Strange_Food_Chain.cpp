#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=150000+10;
ll parent[N];

/*
1-n -> main set
(n+1)-(2*n) -> eats
(2*n+1)-(3*n) -> eaten by
*/

void make_set(ll n){
    for(ll i=1; i<=3*n; i++)
        parent[i]=i;
}
ll find_set(ll v){
    if(parent[v]!=v)
        parent[v]=find_set(parent[v]);
    return parent[v];
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    make_set(n);

    for(ll i=0; i<k; i++){
        ll d,x,y;
        cin>>d>>x>>y;
        if(x>n or y>n){
            ans++;
            continue;
        }
        if(d==1){
            if(x!=y and (find_set(x)==find_set(y+n) or find_set(x)==find_set(y+2*n)))
                ans++;
            else{
                parent[find_set(y)]=find_set(x);
                parent[find_set(y+n)]=find_set(x+n);
                parent[find_set(y+2*n)]=find_set(x+2*n);
            }
        }
        else{
            if(find_set(x)==find_set(y) or find_set(x)==find_set(y+n))
                ans++;
            else{
                parent[find_set(x)]=find_set(y+2*n);
                parent[find_set(x+n)]=find_set(y);
                parent[find_set(x+2*n)]=find_set(y+n);       
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}