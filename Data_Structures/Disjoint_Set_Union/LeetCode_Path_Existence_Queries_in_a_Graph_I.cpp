// Problem Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/

class Solution {
public:
    static const int nodes=1e5;    
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
    vector<bool> pathExistenceQueries(int n, vector<int>& a, int maxDiff, vector<vector<int>>& queries) {
        for(int i=0; i<n; i++) make_set(i);
        for(int i=1; i<n; i++){
            int diff = a[i] - a[i-1];
            if(diff <= maxDiff) union_set(i-1, i);
        }
        int q = queries.size();
        vector<bool> result(q, false);
        for(int i=0; i<q; i++){
            if(find_set(queries[i][0]) == find_set(queries[i][1]))
                result[i] = true;
        }
        return result;
    }
};
