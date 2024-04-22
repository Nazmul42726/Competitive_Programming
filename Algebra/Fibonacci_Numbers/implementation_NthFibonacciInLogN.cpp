const long long mod=1000000007;
map<long long,long long> F;
//the series: F[0]=1, F[1]=1, F[2]=2, F[3]=3, F[4]=5, F[5]=8, F[6]=13, ...
//F[2*k]=F[k]*F[k] + F[k-1]*F[k-1];
//F[2*k+1]=F[k]*F[k+1] + F[k]*F[k-1];
//assign F[0]=F[1]=1 before calong longing the function
long long findFib(long long n){
    if(F.count(n)) return F[n];
    long long k=n/2;
    if(n%2==0) return F[n]=(findFib(k)*findFib(k) + findFib(k-1)*findFib(k-1))%mod;
    else return F[n]=(findFib(k)*findFib(k+1) + findFib(k-1)*findFib(k))%mod;
}