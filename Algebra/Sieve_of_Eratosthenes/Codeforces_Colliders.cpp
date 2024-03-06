#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> primeFactors(n+1);
    vector<bool> sieve(n+1,true);
    for(ll i=2; i<=n; i++){
        if(sieve[i]){
            primeFactors[i].push_back(i);
            for(ll j=2*i; j<=n; j+=i){
                primeFactors[j].push_back(i);
                sieve[j]=false;
            }
        }
    }

    set<ll> alreadyOn;
    map<ll,ll> availableFactorsCnt;
    map<ll,vector<ll>> availableMultipleOf;

    for(ll i=0; i<m; i++){
        char ch;
        ll x;
        cin>>ch>>x;
        if(ch=='+'){
            if(alreadyOn.count(x)){
                cout<<"Already on"<<endl;
                continue;
            }
            bool conflicts=false;
            for(ll i=0; i<primeFactors[x].size(); i++){
                if(availableFactorsCnt[primeFactors[x][i]]>=1){
                    for(auto it: availableMultipleOf[primeFactors[x][i]]){
                        if(alreadyOn.count(it)){
                            cout<<"Conflict with "<<it<<endl;
                            break;
                        }
                    }
                    conflicts=true;
                    break;
                }
            }
            if(!conflicts){
                cout<<"Success"<<endl;
                alreadyOn.insert(x);
                for(ll i=0; i<primeFactors[x].size(); i++){
                    availableFactorsCnt[primeFactors[x][i]]++;
                    availableMultipleOf[primeFactors[x][i]].push_back(x);
                }
            }
        }
        else{
            if(alreadyOn.count(x)==0){
                cout<<"Already off"<<endl;
            }
            else{
                alreadyOn.erase(x);
                for(ll i=0;i <primeFactors[x].size(); i++){
                    availableFactorsCnt[primeFactors[x][i]]--;
                }
                cout<<"Success"<<endl;
            }
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