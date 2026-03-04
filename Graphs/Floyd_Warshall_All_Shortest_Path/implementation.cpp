for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][k] < INF and dp[k][j] < INF)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
/*
* n = number of nodes
* initially dp[i][i] = 0, dp[i][j] = weight of edge <i, j>
* if no such edge exist then INF
*/
