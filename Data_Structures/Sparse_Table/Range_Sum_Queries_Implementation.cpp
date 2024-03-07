#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6;    //possible max size of given array
const int exponent=25; //more than log2(maxN)

long long table[exponent+1][maxN];

void makeTable(vector<int> givenArray){
    int N=givenArray.size();
    copy(givenArray.begin(),givenArray.end(),table[0]);

    for(int i=1; i<=exponent; i++)
        for(int j=0; j+(1<<i)<=N; j++)
            table[i][j]=table[i-1][j]+table[i-1][j+(1<<(i-1))];
}

long long sumQueries(int left, int right){   //left and right are 0-based index
    long long sum=0;
    int range=right-left+1;
    for(int i=exponent; i>=0; i--){
        if((1<<i)<=range){
            sum+=table[i][left];
            left+=(1<<i);
            range-=(1<<i);
        }
    }
    return sum;
}
