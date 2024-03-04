#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int a,b;
    cin>>a>>b;
    vector<int> seq;
    seq.push_back(b);
    while(b>a){
        if(b%10==1) b/=10;
        else if(b%2==0) b/=2;
        else{
            cout<<"NO"<<endl;
            return;
        }
        seq.push_back(b);
    }
    if(b==a) cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
        return;
    }
    
    cout<<seq.size()<<endl;
    reverse(seq.begin(),seq.end());
    for(auto it: seq) cout<<it<<" ";
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}