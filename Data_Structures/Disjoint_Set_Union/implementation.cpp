#include<bits/stdc++.h>
using namespace std;

const int nodes=1e6;    //number of given elements
int parent[nodes+1];
int set_rank[nodes+1];

void make_set(int v){
    parent[v]=v;
    set_rank[v]=0;
}
int find_set(int v){
    if(parent[v]!=v)
        parent[v]=find_set(parent[v]);
    return parent[v];
}
void union_set(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(set_rank[a]<set_rank[b])
            swap(a,b);
        parent[b]=a;

        if(set_rank[a]==set_rank[b])
            set_rank[a]++;
    }
}
//don't forget to make_set for every element at the beginning