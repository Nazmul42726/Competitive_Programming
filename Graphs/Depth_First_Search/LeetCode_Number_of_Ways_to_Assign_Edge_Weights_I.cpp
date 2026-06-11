//Problem Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/

class Solution {
public:
    int modularInverse(int n, int mod){
        int exp = mod-2;
        int result = 1;
        while(exp){
            if(exp & 1) result = (1LL * result * n) % mod;
            n = (1LL*n*n) % mod;
            exp >>= 1;
        }
        return result;
    }

    int dfs(int src, int prnt, vector<vector<int>>& adjList){
        int result = 0;
        for(auto child: adjList[src]){
            if(child != prnt){
                result = max(result, dfs(child, src, adjList)+1);
            }
        }
        return result;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adjList(n+1);
        for(int i=0; i<n-1; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int mod = 1e9+7;
        int mxDepth = dfs(1, 0, adjList);
        vector<int> fact(mxDepth+1), invFact(mxDepth+1);
        
        fact[0] = invFact[0] = 1;
        for(int i=1; i<=mxDepth; i++)
            fact[i] = (1LL * fact[i-1] * i) % mod;
        invFact[mxDepth] = modularInverse(fact[mxDepth], mod);
        for(int i=mxDepth-1; i>0; i--)
            invFact[i] = (1LL * invFact[i+1] * (i+1)) % mod;

        int result = 0;
        for(int i=1; i<=mxDepth; i+=2){
            int nCr = (((1LL * fact[mxDepth] * invFact[i]) % mod) * invFact[mxDepth - i]) % mod;
            result = (result + nCr) % mod;
        }
        return result;
    }
};
