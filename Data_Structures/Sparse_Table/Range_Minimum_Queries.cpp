#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6;    //possible max size of given array
const int exponent=25; //more than log2(maxN)

long long table[exponent+1][maxN];
int logTable[maxN+1];

void makeLogTable(){            //call this function once in the main function
    logTable[1]=0;
    for(int i=2; i<=maxN; i++)
        logTable[i]=logTable[i/2]+1;
}

void makeTable(vector<int> givenArray){
    int N=givenArray.size();
    copy(givenArray.begin(),givenArray.end(),table[0]);

    for(int i=1; i<=exponent; i++)
        for(int j=0; j+(1<<i)<=N; j++)
            table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
}

long long findMinimum(int left, int right){   //left and right are 0-based index
    int range=right-left+1;
    int logRange=logTable[range];

    int minimum=min(table[logRange][left],table[logRange][right-(1<<logRange)+1]);
    return minimum;
}

int main(){
    makeLogTable();
    vector<int> a={3,1,7,2,4,1,5,4};
    makeTable(a);
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int l,r;
        cin>>l>>r;
        cout<<findMinimum(l-1,r-1)<<endl;
    }
}
