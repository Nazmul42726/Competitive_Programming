//Problem Link: https://leetcode.com/problems/block-placement-queries/

class Solution {
public:
    static const int maxN = 50001;
    vector<int> tree;

    int query(int v, int tl, int tr, int l, int r){
        if(l>r) return 0;
        if(l==tl and r==tr) return tree[v];

        int tm = (tl+tr)/2;
        return max(query(v*2, tl, tm, l, min(r,tm)), query(v*2+1, tm+1, tr, max(l,tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int newVal){
        if(tl == tr) tree[v] = newVal;
        else{
            int tm = (tl+tr)/2;
            if(pos<=tm) update(v*2,tl, tm, pos,newVal);
            else update(v*2+1,tm+1,tr,pos,newVal);
            tree[v] = max(tree[v*2], tree[v*2+1]);
        }
    }

    vector<bool> getResults(vector<vector<int>>& q) {
        set<int> st;
        st.insert(0);
        st.insert(maxN-1);
        tree.assign(4*maxN, 0);

        update(1, 0, maxN-1, maxN-1, maxN-1);

        vector<bool> result;

        for(auto it: q){
            if(it[0] == 1){
                int x = it[1];
                auto itr = st.upper_bound(x);
                int r = *itr;
                int l = *prev(itr);

                update(1, 0, maxN-1, x, x-l);
                update(1, 0, maxN-1, r, r-x);
                st.insert(x);
            }
            else{
                int x = it[1];
                int sz = it[2];
                auto itr = st.upper_bound(x);
                int l = *prev(itr);

                int mxSz = query(1, 0, maxN-1, 0, l);
                mxSz = max(mxSz, x-l);

                result.push_back(mxSz >= sz);
            }
        }
        return result;
    }
};
