#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int cntSetBits(int x){
    int result=0;
    while(x){
        if(x&1) result++;
        x>>=1;
    }
    return result;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m+1);
    for(int i=0; i<=m; i++)
        cin>>a[i];
    
    int result=0;
    for(int i=0; i<m; i++){
        int x=a[i]^a[m];
        int diff=cntSetBits(x);
        if(diff<=k) result++;
    }
    cout<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}