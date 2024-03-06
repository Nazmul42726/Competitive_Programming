//when 
//1e6<l,r<1e12 and
//r-l<=1e7
#include<bits/stdc++.h>
using namespace std;

vector<char> segmentedSieve(long long l, long long r){      //pregenerating primes [1, sqrt(r)] // more efficient
    long long preGenerateLimit=sqrt(r);
    vector<char> primeSieve(preGenerateLimit+1,true);
    vector<long long> preGeneratedPrimes;
    for(int i=2; i<=preGenerateLimit; i++){
        if(primeSieve[i]){
            preGeneratedPrimes.emplace_back(i);
            for(long long j=i*i; j<=preGenerateLimit; j+=i)
                primeSieve[j]=false;
        }
    }
    vector<char> result(r-l+1,true);
    for(long long it: preGeneratedPrimes){
        for(long long i=max(it*it,(long long)(ceil(l*1.0/it)*it)); i<=r; i+=it){
            result[i-l]=false;
        }
    }
    if(l==1) result[0]=false;       //surprise!
    return result;
}
vector<char> segmented_Sieve(long long l, long long r){     //without pregenerating primes [1, sqrt(r)]
    vector<char> result(r-l+1,true);
    int limit=sqrt(r);
    for(long long i=2; i<=limit; i++){
        for(long long j=max(i*i,(long long)ceil(l*1.0/i)*i); j<=r; j+=i)
            result[j-l]=false;
    }
    if(l==1) result[0]=false;
    return result;
}
int main(){
    long long l,r;
    cin>>l>>r;
    vector<char> sieve=segmented_Sieve(l,r);
    for(int i=0; i<sieve.size(); i++){
        if(sieve[i]) cout<<i+l<<" ";
    }
    cout<<endl;
}