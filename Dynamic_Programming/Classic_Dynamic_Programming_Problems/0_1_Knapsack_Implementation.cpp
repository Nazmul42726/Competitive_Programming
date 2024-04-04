#include<bits/stdc++.h>
using namespace std;

const int maxWeight=1010;
const int cntItems=1010;

int weights[cntItems];
int profits[cntItems];
int best[cntItems][maxWeight];

int knapsack(int w, int n){
    if(n==0 or w==0) return 0;
    if(best[n][w]!=0)
        return best[n][w];

    if(weights[n]>w)
        best[n][w]=knapsack(w,n-1);
    else
        best[n][w]=max(profits[n]+knapsack(w-weights[n],n-1),knapsack(w,n-1));

    return best[n][w];  
}

int main(){
    int n,w;
    cin>>n>>w;
    for(int i=0; i<n; i++) cin>>profits[i];
    for(int i=0; i<n; i++) cin>>weights[i];
        
    cout<<knapsack(w,n-1)<<endl;    //zero based
}