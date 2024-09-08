#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double pi=3.1415926536;
double b,c;

double f(double x){
    double result= ((x*x) + (x*b) + c) / sin(x);
    return result;
}
void solve(){
    cin>>b>>c;
    double errorLimit=1e-7;
    double left=1e-6,right=pi/2;
    
    while(right-left > errorLimit){
        double mid1 = left+(right-left)/3;
        double mid2 = right-(right-left)/3;

        double f1=f(mid1);
        double f2=f(mid2);

        if(f1>f2) left=mid1;
        else right=mid2;
    }
    double result=min(f(left),f(right));
    printf("%0.8lf\n",result);
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