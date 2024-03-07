#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    int n,m;
    cin>>n>>m;
    set<int> s;
    vector<int> a(n+1,0);
    for(int i=1; i<=n; i++) s.insert(i);
    for(int i=0; i<m; i++){
        int l,r,winner;
        cin>>l>>r>>winner;
        auto it1=s.lower_bound(l),it2=s.upper_bound(r);
        while(1){
            if(it1==s.end() or it1==it2) break;
            int x=*it1;
            auto temp=it1;
            it1++;
            if(x!=winner){
                a[x]=winner;
                s.erase(temp);
            }
        }
    }
    for(int i=0; i<n; i++) cout<<a[i+1]<<" ";
    cout<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}