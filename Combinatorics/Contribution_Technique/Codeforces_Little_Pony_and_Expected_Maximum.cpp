#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double binExpo(double base, int exp){
    double result = 1;
    while(exp){
        if(exp % 2) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

void solve(){
    double m, n;
    cin>>m>>n;

    double result = m;
    for(int i=1; i<m; i++){
        result -= binExpo(1.0*i/m, n);
    }

    cout<<setprecision(12)<<fixed<<result<<endl;
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();
    solve();
    return 0;
}
