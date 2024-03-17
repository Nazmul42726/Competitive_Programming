#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll n=1e8+10;
vector<char> seive(n,true);
vector<ll> primes;

void makeSeive(){
    seive[0]=seive[1]=false;

    for(ll i=2; i<n; i++){
        if(seive[i]){
            primes.push_back(i);
            for(ll j=i*i; j<n; j+=i)
                seive[j]=false;
        }
    }
}
ll findexRow(ll index){
    ll l=1, r=index;
    while(r-l>1){
        ll mid=l+(r-l)/2;
        ll val=(mid*(mid+1))/2;
        if(val<=index) l=mid;
        else r=mid-1;
    }
    ll val=(r*(r+1))/2;
    if(val<=index) return r;
    return l;
}
void solve(){
    ll x;
    cin>>x;

    auto it=lower_bound(primes.begin(),primes.end(),x);

    if(it==primes.end() or *it!=x) cout<<-1<<endl;
    else{
        ll index=it-primes.begin()+1;
        ll completeRows=findexRow(index);
        ll elementInRows=(completeRows*(completeRows+1))/2;

        if(elementInRows==index) cout<<completeRows<<" "<<completeRows<<endl;
        else cout<<completeRows+1<<" "<<index-elementInRows<<endl;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    makeSeive();
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}