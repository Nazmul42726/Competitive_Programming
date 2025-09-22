#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n;

const ll maxN = 1e5+10;
const ll maxLog = 18;

ll logTable[maxN+1];
ll spTable[maxLog+1][maxN+1];
ll a[maxN], diff[maxN];

void makeLogTable(){
    logTable[1] = 0;
    for(ll i=2; i<= maxN; i++){
        logTable[i] = logTable[i/2] + 1;
    }
}

void makeTable(){
    for(ll i=1; i<n; i++){
        spTable[0][i] = diff[i];
    }
    for(ll i=1; i<=maxLog; i++){
        for(ll j=1; j + (1<<i) <= n; j++){
            spTable[i][j] = max(spTable[i-1][j], spTable[i-1][j+(1<<(i-1))]);
        }
    }
}

ll query(ll l, ll r){
    if(r < l) return 0;
    ll i = logTable[r-l+1];
    ll result = max(spTable[i][l], spTable[i][r-(1<<i)+1]);
    return result;
}

void solve(){
    cin>>n;
    
    for(ll i=1; i<=n; i++) cin>>a[i];
    for(ll i=1; i<n; i++) diff[i] = a[i+1] - a[i];

    makeTable();

    ll m;
    cin>>m;

    for(ll i=0; i<m; i++){
        ll t, d;
        cin>>t>>d;

        ll rgt = upper_bound(a+1, a+n+1, t) - a;
        
        if(rgt <=1 or query(1, rgt-1)<=d){
            cout<<1<<endl;
            continue;
        }

        ll l = 1;
        ll r = rgt - 2;
        ll result = -1;

        while(l <= r){
            ll mid = (r + l) / 2;
            if(query(mid, r) <= d){
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(result != -1) cout<<result<<endl;
        else cout<<rgt-1<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    makeLogTable();
    solve();

    return 0;
}
