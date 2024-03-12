#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e3+10;
vector<bool> seive(mx+1,true);
vector<int> primes;

void makeSeive(){
    for(int i=2; i<=mx; i++){
        if(seive[i]){
            primes.push_back(i);
            for(int j=i*i; j<=mx; j+=i) seive[j]=false;
        }
    }
}
void solve(){
    makeSeive();
    int n,k;
    cin>>n>>k;
    for(int i=2; i<=n; i++){
        if(seive[i]){
            for(int j=1; j<primes.size(); j++){
                if(primes[j]<n){
                    if(primes[j]+primes[j-1]+1==i){
                        k--;
                        break;
                    }
                }
                else break;
            }
        }
    }
    if(k<=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}