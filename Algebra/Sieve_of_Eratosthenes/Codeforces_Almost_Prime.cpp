#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
vector<int> primeSieve(){
    vector<char> sieve(n+1,true);
    vector<int> primeDivisorCnt(n+1,0);
    
    for(int i=2; i<=n; i++){
        if(sieve[i]){
            for(int j=2*i; j<=n; j+=i){
                sieve[j]=false;
                primeDivisorCnt[j]++;
            }
        }
    }
    return primeDivisorCnt;
}

void solve(){
    cin>>n;
    int ans=0;
    vector<int> primeDivisorCnt=primeSieve();
    for(auto it: primeDivisorCnt) if(it==2) ans++;
    cout<<ans<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}