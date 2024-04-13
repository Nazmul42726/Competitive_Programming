const int N=1e7;
vector<int> sieve(N+1);
vector<int> primes;

for(int i=2; i<=N; i++){
    if(sieve[i]==0){
        sieve[i]=i;
        primes.push_back(i);
    }
    for(int j=0; i*primes[j]<=N; j++){
        sieve[i*primes[j]]=primes[j];
        if(primes[j]==sieve[j])
            break;
    }
}