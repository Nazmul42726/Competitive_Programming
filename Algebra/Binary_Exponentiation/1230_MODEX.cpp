#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;
        x%=n;
        int ans=1;
        while(y>0){
            if(y&1)
                ans=ans*x%n;
            x=x*x%n;
            y>>=1;            
        }
        cout<<ans<<endl;
    }
    cin>>t;
}