double ternarySearch(double l,double r){
    double errorLimit=1e-9;
    while(r-l>errorLimit){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        double f1=f(m1);
        double f2=f(m2);
        //here f() is the unimodal function
        if(f1<f2) l=m1;
        else r=m2;
    }
    return f(l);
    //maximum of f(x) in [l,r]
}