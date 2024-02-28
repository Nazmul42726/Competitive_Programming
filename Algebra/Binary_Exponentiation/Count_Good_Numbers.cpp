class Solution {
public:
    long long mod=1e9+7;
    long long cal(long long a, long long b){
        a%=mod;
        long long result=1;
        while(b>0){
            if(b&1) result=(result*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return result;
    }
    long long countGoodNumbers(long long n) {
        long long five=n/2,four=n/2;
        if(n%2) five++;
        long long ans=(cal(5,five)*cal(4,four))%mod;
        return ans;
    }
};