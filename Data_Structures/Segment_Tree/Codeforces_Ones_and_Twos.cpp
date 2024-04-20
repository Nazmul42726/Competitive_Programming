#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5+10;
int tree[3*N];

void built(vector<int>& a, int v, int l, int r){
    if(l==r){
        tree[v]=a[l];
        return;
    }
    int mid=l+(r-l)/2;
    built(a,2*v,l,mid);
    built(a,2*v+1,mid+1,r);
    tree[v]=tree[2*v]+tree[2*v+1];
}
void update(int v, int l, int r, int ind, int newValue){
    if(l==r){
        tree[v]=newValue;
        return;
    }
    int mid=l+(r-l)/2;
    if(ind<=mid)
        update(v*2,l,mid,ind,newValue);
    else
        update(v*2+1,mid+1,r,ind,newValue);
    tree[v]=tree[2*v]+tree[2*v+1];
}
int sum(int v, int vl, int vr, int l, int r){
    if(l>r) return 0;
    if(l==vl and r==vr) return tree[v];

    int mid=vl+(vr-vl)/2;
    return sum(2*v,vl,mid,l,min(r,mid))
          +sum(2*v+1,mid+1,vr,max(l,mid+1),r);
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    int totalSum=0;
    set<int> indexOf1;
    int first1=n,last1=-1;
    for(int i=0; i<n; i++){
        cin>>a[i];
        totalSum+=a[i];
        if(a[i]==1) indexOf1.insert(i);
    }
    if(indexOf1.size()==0) first1=n;
    else{
        first1=*(indexOf1.begin());
        last1=*(--indexOf1.end());
    }
    built(a,1,0,n-1);
    for(int i=0; i<q; i++){
        int type;
        cin>>type;
        if(type==1){
            int reqSum;
            cin>>reqSum;
            if(reqSum>totalSum){
                cout<<"NO"<<endl;
                continue;
            }
            if(first1==n){  //no 1 is present
                if(reqSum<=totalSum and reqSum%2==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else{
                int all=max(sum(1,0,n-1,first1,n-1),sum(1,0,n-1,0,last1));
                int onlyEvens=totalSum-all;
                if(reqSum<=all)
                    cout<<"YES"<<endl;
                else if(reqSum<=onlyEvens and reqSum%2==0)
                    cout<<"YES"<<endl;
                else if((reqSum-all)%2==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
        else{
            int ind,newValue;
            cin>>ind>>newValue;
            update(1,0,n-1,ind-1,newValue);
            if(a[ind-1]!=newValue){
                if(newValue==1){
                    totalSum--;
                    a[ind-1]=1;
                    indexOf1.insert(ind-1);
                }
                else{
                    totalSum++;
                    a[ind-1]=2;
                    indexOf1.erase(ind-1);
                }
                if(indexOf1.size()==0) first1=n;
                else{
                    first1=*(indexOf1.begin());
                    last1=*(--indexOf1.end());
                }
            }
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
        solve();
    }
    return 0;
}