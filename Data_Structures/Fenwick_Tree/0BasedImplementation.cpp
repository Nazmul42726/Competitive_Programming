struct FenwickTree0{
    vector<int> BIT;
    int n;

    FenwickTree0(int n){
        this->n=n;
        BIT.assign(n,0);
    }
    FenwickTree0(vector<int>& a):FenwickTree0(a.size()){
        for(size_t i=0; i<a.size(); i++){
            add(i,a[i]);
        }
    }
    int sum(int ind){
        int result=0;
        for( ; ind>=0; ind=(ind&(ind+1))-1){
            result+=BIT[ind];
        }
        return result;
    }
    int sum(int l, int r){
        return sum(r)-sum(l-1);
    }
    void add(int ind, int value){
        for( ; ind<n; ind = ind|(ind+1)){
            BIT[ind]+=value;
        }
    }
};