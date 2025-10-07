#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+10;
int n;
vector<int> tree(4*maxN);

//initially:
//v = 1 [first node of the tree]
//tl = 0 [first index of the range]
//tr = n-1 [last index of the range]

void build(vector<int>& a, int v, int tl, int tr){
    if(tl == tr){
        tree[v] = a[tl];
    }
    else{
        int tm = (tl+tr)/2;
        build(a,v*2,tl, tm);
        build(a,v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(l==tl and r==tr) return tree[v];

    int tm = (tl+tr)/2;
    return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update(int v, int tl, int tr, int pos, int newVal){
    if(tl == tr) tree[v] = newVal;
    else{
        int tm = (tl+tr)/2;
        if(pos<=tm) update(v*2,tl, tm, pos,newVal);
        else update(v*2+1,tm+1,tr,pos,newVal);
        tree[v] = tree[v*2]+tree[v*2+1];
    }
}

