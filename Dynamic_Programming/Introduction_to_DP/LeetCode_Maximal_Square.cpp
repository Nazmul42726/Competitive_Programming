class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> dp(n, vector<int>(m,0));

        int result = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '0') dp[i][j] = 0;
                else if(i and j)
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                else dp[i][j] = 1;
                
                result = max(result, dp[i][j]);
            }
        }
        return result*result;
    }
};
