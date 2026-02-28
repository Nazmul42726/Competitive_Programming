#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll maxN=1e6;
const ll expo=25;

ll table[expo+1][maxN];
ll logTable[maxN+1];

void makeLogTable(){
    logTable[1]=0;
    for(ll i=2; i<=maxN; i++)
        logTable[i]=logTable[i/2]+1;
}
void makeTable(vector<ll> a){
    ll n=a.size();
    copy(a.begin(),a.end(),table[0]);

    for(ll i=1; i<=expo; i++){
        for(ll j=0; j+(1<<i)<=n; j++){
            table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }
    }
}
ll query(ll left, ll right){
    ll range=right-left+1;
    ll logRange=logTable[range];

    ll minimum=min(table[logRange][left],table[logRange][right-(1<<logRange)+1]);
    return minimum;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    makeLogTable();
    makeTable(a);
    ll q;
    cin>>q;
    for(ll i=0; i<q; i++){
        ll x,y;
        cin>>x>>y;
        cout<<query(x,y)<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
