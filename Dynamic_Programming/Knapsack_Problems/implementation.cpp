// n items, capacity W
vector<int> dp(W+1, 0);

//0-1 Knapsack
for(int i=0; i<n; i++){
    int w=weight[i], v=value[i];
    for(int j=W; j>=w; j--){
        dp[j] = max(dp[j], dp[j-w]+v);
    }
}

//Complete Knapsack
for(int i=0; i<n; i++){
    int w=weight[i], v=value[i];
    for(int j=w; j<=W; j++){
        dp[j] = max(dp[j], dp[j-w]+v);
    }
}

//Multiple Knapsack
for(int i=0; i<n;i++){
    int w=weight[i], v=value[i], k=count[i];

    for (int p=1; k>0; p<<=1){
        int take = min(p, k);
        int ww = take*w;
        int vv = take*v;

        for (int j=W; j>=ww; j--){
            dp[j] = max(dp[j], dp[j-ww]+vv);
        }
        k -= take;
    }
}

//Mixed Knapsack
for(each item){
    if(type == 0){
        // 0-1 knapsack update
    }
    else if(type == 1){
        // complete knapsack update
    }
    else{
        // multiple knapsack (binary split)
    }
}
