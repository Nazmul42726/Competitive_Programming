#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> indicesInIdentity(int n){
    vector<int> a(n);
    for(int i=0; i<n; i++) a[i]=i;
    return a;
}
vector<int> indicesInFirstPermutation(int n){
    vector<int> a(n);
    for(int i=0; i<n; i++){
        if(i<n/2) a[i]=2*i;
        else a[i]=((i-n/2)*2)+1;
    }
    return a;
}
vector<int> getPermutation(vector<int> identityPermutation, vector<int> finalPositions,int n){
    vector<int> result(n);
    for(int i=0; i<n; i++) result[i]=identityPermutation[finalPositions[i]];
    return result;
}
vector<int> permutateIndices(int n, int cnt){
    if(cnt==0) return indicesInIdentity(n);

    vector<int> resultIndices=permutateIndices(n,cnt/2);

    resultIndices=getPermutation(resultIndices,resultIndices,n);

    if(cnt%2) resultIndices=getPermutation(resultIndices,indicesInFirstPermutation(n),n);

    return resultIndices;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> identityPermutation(n);
    for(int i=0; i<n; i++) identityPermutation[i]=i+1;
    
    vector<int> indicesAferKthPermutation=permutateIndices(n,k);

    vector<int> result=getPermutation(identityPermutation,indicesAferKthPermutation,n);

    for(int i=0; i<n; i++) cout<<result[i]<<" ";
    cout<<endl;
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