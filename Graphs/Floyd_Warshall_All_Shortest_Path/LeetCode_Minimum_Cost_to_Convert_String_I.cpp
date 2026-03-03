class Solution {
public:
    const long long inf = 1e18;
    long long minimumCost(string src, string tar, vector<char>& org, vector<char>& cng, vector<int>& cst) {
        int x = org.size();
        vector<vector<long long>> dp(26, vector<long long> (26, inf));

        for(int i=0; i<26; i++) dp[i][i] = 0;

        for(int i=0; i<x; i++){
            int u = org[i] - 'a';
            int v = cng[i] - 'a';

            dp[u][v] = min(dp[u][v], (long long) cst[i]);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(dp[i][k] < inf and dp[k][j] < inf){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }

        long long result = 0;
        int n = src.size();
        for(int i=0; i<n; i++){
            int u = src[i] - 'a';
            int v = tar[i] - 'a';

            if(dp[u][v] == inf) return -1;
            result += dp[u][v];
        }
        return result;
    }
};
