#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct FenwickTree0{
    vector<ll> bit;
    ll n;

    FenwickTree0(ll n){
        this->n=n;
        bit.assign(n,0);
    }
    FenwickTree0(vector<ll>& a):FenwickTree0(a.size()){
        for(size_t i=0; i<a.size(); i++){
            add(i,a[i]);
        }
    }
    ll sum(ll ind){
        ll result=0;
        for( ; ind>=0; ind=(ind&(ind+1))-1)
            result+=bit[ind];
        return result;
    }
    ll sum(ll l, ll r){
        return sum(r)-sum(l-1);
    }
    void add(ll ind, ll value){
        for( ; ind<n; ind=ind|(ind+1))
            bit[ind]+=value;
    }
    void printBit(){
        for(int i=0; i<n; i++)
            cout<<bit[i]<<" ";
        cout<<endl;
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0; i<n; i++)
        cin>>a[i];

    FenwickTree0 ft= FenwickTree0(a);

    for(ll i=0; i<q; i++){
        ll type;
        cin>>type;
        if(type==1){
            ll ind;
            cin>>ind;
            ll result=ft.sum(ind,ind);
            ft.add(ind,-result);
            cout<<result<<endl;
        }
        else if(type==2){
            ll ind, value;
            cin>>ind>>value;
            ft.add(ind,value);
        }
        else{
            ll l,r;
            cin>>l>>r;
            ll result=ft.sum(l,r);
            cout<<result<<endl;
        }
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}