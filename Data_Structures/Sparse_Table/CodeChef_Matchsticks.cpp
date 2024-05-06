#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll maxN=1e5+10;
const ll exponent=25;

ll logTable[maxN+1];
ll mxTable[exponent+1][maxN];
ll mnTable[exponent+1][maxN];

void makeLogTable(){
    logTable[1]=0;
    for(ll i=2; i<=maxN; i++){
        logTable[i]=logTable[i/2]+1;
    }
}
void makeTable(vector<double> a){
    ll n=a.size();
    copy(a.begin(),a.end(),mxTable[0]);
    copy(a.begin(),a.end(),mnTable[0]);
    for(ll i=1; i<=exponent; i++){
        for(ll j=0; j+(1<<i)<=n; j++){
            mxTable[i][j]=max(mxTable[i-1][j],mxTable[i-1][j+(1<<(i-1))]);
            mnTable[i][j]=min(mnTable[i-1][j],mnTable[i-1][j+(1<<(i-1))]);
        }
    }
}
double query(ll left, ll right, ll qType){
    ll range=right-left+1;
    ll logRange=logTable[range];

    if(qType){
        double result=max(mxTable[logRange][left],mxTable[logRange][right-(1<<logRange)+1]);
        return result;
    }
    else{
        double result=min(mnTable[logRange][left],mnTable[logRange][right-(1<<logRange)+1]);
        return result;
    }
}
void solve(){
    makeLogTable();
    ll n;
    cin>>n;
    vector<double> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];

    makeTable(a);

    ll q;
    cin>>q;
    for(ll i=0; i<q; i++){
        ll l,r;
        cin>>l>>r;
        double leftMax=(l==0)?0:query(0,l-1,1);
        double rightMax=(r==n-1)?0:query(r+1,n-1,1);
        double rangeMax=query(l,r,1);
        double rangeMin=query(l,r,0);
        double result=max(leftMax+rangeMin,max(rightMax+rangeMin,(rangeMax+rangeMin)/2));
        printf("%0.1lf\n",result);
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}