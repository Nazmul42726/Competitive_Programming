#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e5+10;
ll n,k;
vector<double> speed(N);
vector<double> dis(N);

double p(double ind, double time){
    return (speed[ind]*time)+dis[ind];
}
double f(double time){
    double minValue=p(0,time);
    double maxValue=p(0,time);
    for(ll i=1; i<n; i++){
        minValue=min(minValue,p(i,time));
        maxValue=max(maxValue,p(i,time));
    }
    return maxValue-minValue;
}
double ternarySearch(){
    double l=0,r=k,errorLimit=1e-9;
    while(r-l>errorLimit){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        double f1=f(m1);
        double f2=f(m2);
        if(f1>f2) l=m1;
        else r=m2;
    }
    return f(l);
}
void solve(){
    cin>>n>>k;
    for(ll i=0; i<n; i++){
        double s,d;
        cin>>s>>d;
        speed[i]=s;
        dis[i]=d;
    }
    double result=ternarySearch();
    printf("%0.6lf\n",result);
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}