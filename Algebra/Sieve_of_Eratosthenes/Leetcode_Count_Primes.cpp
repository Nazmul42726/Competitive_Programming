class Solution {
public:
    int countPrimes(int n) {
        int result=0;
        vector<char> sieve(n,true);
        for(long long i=2; i<n; i++){
            if(sieve[i]){
                result++;
                for(long long j=i*i; j<n; j+=i)
                    sieve[j]=false;
            }
        }
        return result;
    }
};