class Solution {
public:
    vector<vector<int>> res;
    vector<int> prev;
    void dp(int n){
        if(n==1){
            prev.push_back(1);
            res.push_back(prev);
            return;
        }
        if(n>1) dp(n-1);
        vector<int> newarr;
        newarr.push_back(1);
        for(int i=1; i<prev.size(); i++){
            newarr.push_back(prev[i]+prev[i-1]);
        }
        newarr.push_back(1);
        prev=newarr;
        res.push_back(newarr);
        return;
    }
    vector<vector<int>> generate(int numRows) {
        dp(numRows);
        return res;
    }
};