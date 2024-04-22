#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=50010;
const ll exponent=17;
ll table[exponent+1][N];
ll logTable[N];

void makeLogTable(){
    logTable[1]=0;
    for(ll i=2; i<N; i++)
        logTable[i]=logTable[i/2]+1;
}
void makeTable(vector<ll> a){
    ll n=a.size();
    copy(a.begin(),a.end(),table[0]);

    for(ll i=1; i<=exponent; i++){
        for(ll j=0; j+(1<<i)<=n; j++){
            table[i][j]=max(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }
    }
}
ll query(ll left, ll right){
    ll range=right-left+1;
    ll logRange=logTable[range];
    ll maximum=max(table[logRange][left],table[logRange][right-(1<<(logRange))+1]);
    return maximum;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0; i<n; i++)
        cin>>a[i];
    
    makeTable(a);
    ll result=0;
    for(ll i=0; i<m; i++){
        ll x,y;
        cin>>x>>y;
        ll mxInRange=query(x-1,y-2);
        //max(A+1,A+2,A+3,...,B-1) must be less than of equals to A
        if(mxInRange==a[x-1]) result++;
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    makeLogTable();
    solve();
    return 0;
}