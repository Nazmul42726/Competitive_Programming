#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1010;
int parent[N];
int r[N];

void make_set(int v){
    parent[v]=v;
    r[v]=0;
}
int find_set(int v){
    if(v!=parent[v])
        parent[v]=find_set(parent[v]);
    return parent[v];
}
void union_sets(int a, int b){
        if(r[a]<r[b]) swap(a,b);
        parent[b]=a;
        if(r[a]==r[b]) r[a]++;
}

void solve(){
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++)
        make_set(i);
    
    vector<pair<int,int>> roadsToRemove;
    for(int i=1; i<n; i++){
        int a,b,x,y;
        cin>>a>>b;
        x=find_set(a);
        y=find_set(b);

        if(x==y)
            roadsToRemove.push_back(make_pair(a,b));
        else
            union_sets(x,y);
    }

    set<int> roots;
    for(int i=1; i<=n; i++){
        int x=find_set(i);
        roots.insert(x);
    }

    auto it=roots.begin();
    auto itt=it;
    itt++;    
    int i=0;

    cout<<roadsToRemove.size()<<endl;
    while(itt!=roots.end()){
        cout<<roadsToRemove[i].first<<" "<<roadsToRemove[i].second<<" ";
        cout<<*it<<" "<<*itt<<endl;
        itt++;i++;
    }
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}