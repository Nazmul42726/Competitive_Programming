#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double ax,ay,bx,by,cx,cy,dx,dy;

double distance(double x, double n){
    double x1=ax+((bx-ax)*(x/n));
    double x2=cx+((dx-cx)*(x/n));
    double y11=ay+((by-ay)*(x/n));
    double y2=cy+((dy-cy)*(x/n));

    double result=sqrt((x2-x1)*(x2-x1) + (y2-y11)*(y2-y11));
    return result;
}
void solve(){
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

    double errorLimit=1e-7;
    double aTob=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));

    double left=0,right=aTob;
    while(right-left > errorLimit){
        double mid1 = left + (right-left)/3;
        double mid2 = right - (right-left)/3;
        double d1=distance(mid1,aTob);
        double d2=distance(mid2,aTob);
        if(d1<d2) right=mid2;
        else left=mid1;
    }
    double result=min(distance(left,aTob),distance(right,aTob));
    printf("%0.8f\n",result);
}

signed main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    optimize();

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        printf("Case %d: ",i);
        solve();
    }
    return 0;
}