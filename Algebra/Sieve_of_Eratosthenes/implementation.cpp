#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> primeSieve(n+1,true);
    primeSieve[0]=primeSieve[1]=false;
    for(int i=2; i*i<=n; i++){
        if(primeSieve[i])
            for(int j=i*i; j<=n; j+=i) primeSieve[j]=false;
    }

    cout<<"Prime numbers [1,"<<n<<"]: "<<endl;
    for(int i=2; i<=n; i++){
        if(primeSieve[i]) cout<<i<<" ";
    }
    cout<<endl;
}