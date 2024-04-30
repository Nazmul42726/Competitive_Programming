struct FenwickTree1{
    int n;
    vector<int> tree;

    FenwickTree1(int n){
        this->n=n;
        tree.assign(n+1,0);
    }
    //a is 1 based indexed vector, i.e. a[0]=0, a[1]=a1, a[2]=a2, a[3]=a3, ...
    FenwickTree1(vector<int> a):FenwickTree1(a.size()){
        for(int i=1; i<=a.size(); i++)
            add(i,a[i]);
    }
    int sum(int ind){
        int result=0;
        while(ind>0){
            result+=tree[ind];
            ind-=(ind&(-ind));
        }
        return result;
    }
    int sum(int left, int right){
        return sum(right)-sum(left-1);
    }
    void add(int ind, int value){
        while(ind<=n){
            tree[ind]+=value;
            ind+=(ind&(-ind));
        }
    }
};
