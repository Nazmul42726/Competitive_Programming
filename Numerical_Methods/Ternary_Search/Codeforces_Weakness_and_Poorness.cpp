#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double weakness(vector<int>& a, double x){
    int n=a.size();
    double poorness=0.0,sum1=0.0,sum2=0.0;

    for(int i=0; i<n; i++){
        sum1=max(a[i]-x, sum1+a[i]-x);
        sum2=min(a[i]-x, sum2+a[i]-x);
        poorness=max(poorness,max(fabs(sum1),fabs(sum2)));
    }
    return poorness;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    double l=-1e5,r=1e5;
    int cnt=200;    //randomly taken
    while(cnt--){
        double mid1=l+(r-l)/3.0;
        double mid2=r-(r-l)/3.0;

        double w1=weakness(a,mid1);
        double w2=weakness(a,mid2);

        if(w1>w2) l=mid1;
        else r=mid2;
    }
    double result=min(weakness(a,l),weakness(a,r));
    printf("%0.12lf\n",result);
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}