#include<bits/stdc++.h>
using namespace std;

vector<long long> segmentedSieve(long long left, long long right){
    long long limit=sqrt(right);
    vector<char> marked(limit+1,true);
    vector<long long> primes;

    for(long long i=2; i<=limit; i++){
        if(marked[i]){
            primes.emplace_back(i);
            for(long long j=i*i; j<=limit; j+=i)
                marked[j]=false;
        }
    }
    vector<char> segmented_sieve(right-left+1,true);
    for(long long i: primes){
        for(long long j=max(i*i,((left+i-1)/i)*i); j<=right; j+=i)
            segmented_sieve[j-left]=false;
    }
    if(left==1) segmented_sieve[0]=false;

    vector<long long> primesInGivenSegment;
    for(long long i=0; i<right-left+1; i++){
        if(segmented_sieve[i])
            primesInGivenSegment.emplace_back(left+i);
    }
    
    return primesInGivenSegment;
}
int main(){
    long long left,right;
    cin>>left>>right;

    vector<long long> primesInGivenSegment=segmentedSieve(left,right);

    for(auto it: primesInGivenSegment) cout<<it<<" ";
    cout<<endl;
}