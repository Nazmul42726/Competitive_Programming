#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double x,y,x2,y2,v1,v2;

double landDis(double dis){
    double dx=dis-x;
    double dy=y;
    return sqrt(dx*dx+dy*dy);
}
double waterDis(double dis){
    double dx=x2-dis;
    double dy=y2;
    return sqrt(dx*dx+dy*dy);
}
double timeTaken(double dis){
    return (landDis(dis)/v1)+(waterDis(dis)/v2);
}

double ternarySearch(double l, double r){
    double result=1e9;
    double errorLimit=1e-5;

    double fl=timeTaken(l);
    double fr=timeTaken(r);

    while (r-l>errorLimit){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;

        double fm1=timeTaken(m1);
        double fm2=timeTaken(m2);

        result=min(result,min(fm1,fm2));

        if(fm1>fm2) l=m1+1;
        else r=m2;
    }
    return result;
}
void solve(){
    cin>>x>>y>>x2>>y2>>v1>>v2;
    if(x>x2) swap(x,x2);

    double result=ternarySearch(x,x2);
    printf("%0.5lf\n",result);
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