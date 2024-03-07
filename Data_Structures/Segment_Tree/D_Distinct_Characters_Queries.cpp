#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=3e5;
int tr[mx][26];
string s;

void build(int v, int vl, int vr, char treeChar){
    if(vl==vr){
        if(s[vl]==treeChar) tr[v][treeChar-'a']=1;
        return;     
    }
    int mid=vl+(vr-vl)/2;
    build(2*v,vl,mid,treeChar);
    build(2*v+1,mid+1,vr,treeChar);
    tr[v][treeChar-'a']=tr[2*v][treeChar-'a']+tr[2*v+1][treeChar-'a'];
}
void Remove(int v, int vl, int vr, int position, char toRemove){
    if(vl==vr){
        tr[v][toRemove-'a']=0;
        return;
    }
    int mid=vl+(vr-vl)/2;
    if(position<=mid) Remove(2*v,vl,mid,position,toRemove);
    else Remove(2*v+1,mid+1,vr,position,toRemove);

    tr[v][toRemove-'a']=tr[2*v][toRemove-'a']+tr[2*v+1][toRemove-'a'];
}
void Insert(int v, int vl, int vr, int position, char toInsert){
    if(vl==vr){
        tr[v][toInsert-'a']=1;
        return;
    }
    int mid=vl+(vr-vl)/2;
    if(position<=mid) Insert(2*v,vl,mid,position,toInsert);
    else Insert(2*v+1,mid+1,vr,position,toInsert);

    tr[v][toInsert-'a']=tr[2*v][toInsert-'a']+tr[2*v+1][toInsert-'a'];
}
int calculate(int v, int vl, int vr, int l, int r, int treeChar){
    if(l>r) return 0;
    if(vl==l and vr==r) return tr[v][treeChar];

    int mid=vl+(vr-vl)/2;
    return calculate(2*v,vl,mid,l,min(mid,r),treeChar)+calculate(2*v+1,mid+1,vr,max(l,mid+1),r,treeChar);
}
void solve(){
    cin>>s;
    ll n=s.size();
    for(char ch='a'; ch<='z'; ch++)
        build(1,0,n-1,ch);
    ll q;
    cin>>q;
    for(ll i=0; i<q; i++){
        ll t;
        cin>>t;
        if(t==1){
            ll x; cin>>x;
            char ch; cin>>ch;
            if(s[x-1]==ch) continue;
            Remove(1,0,n-1,x-1,s[x-1]);
            s[x-1]=ch;
            Insert(1,0,n-1,x-1,ch);
        }
        else{
            ll l,r;
            cin>>l>>r;
            int cnt=0;
            for(int i=0; i<26; i++)
                if(calculate(1,0,n-1,l-1,r-1,i)) cnt++;
            cout<<cnt<<endl;
        }
    }
}
signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}