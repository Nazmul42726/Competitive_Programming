#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct FenwickTree1{
    ll n;
    vector<ll> tree;

    FenwickTree1(ll n){
        this->n=n;
        tree.assign(n+1,0);
    }
    FenwickTree1(vector<ll> a):FenwickTree1(a.size()){
        for(ll i=1; i<=a.size(); i++)
            add(i,a[i]);
    }
    ll sum(ll ind){
        ll result=0;
        while(ind>0){
            result+=tree[ind];
            ind-=(ind&(-ind));
        }
        return result;
    }
    ll sum(ll left, ll right){
        return sum(right)-sum(left-1);
    }
    void add(ll ind, ll value){
        while(ind<=n){
            tree[ind]+=value;
            ind+=(ind&(-ind));
        }
    }
};

void solve(ll n){
    vector<ll> a(n+1,0);
    for(ll i=1; i<=n; i++) cin>>a[i];

    FenwickTree1 fenwickTree(a);

    while(1){
        string s;
        cin>>s;
        if(s[0]=='E') break;
        if(s[0]=='M'){
            ll l,r;
            cin>>l>>r;
            cout<<fenwickTree.sum(l,r)<<endl;
        }
        else{
            ll index,newValue;
            cin>>index>>newValue;
            fenwickTree.add(index,newValue-a[index]);
            a[index]=newValue;
        }
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    ll t=0;
    while(1){
        ll n;
        cin>>n;
        if(n==0) break;
        t++;
        if(t>1) cout<<endl;
        cout<<"Case "<<t<<":"<<endl;
        solve(n);
    }
    return 0;
}