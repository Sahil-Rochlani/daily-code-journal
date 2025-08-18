#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(int W, int i, vector<int> &val, vector<int> &wt){
    if(i >= val.size())return 0;
    int include =  W - wt[i] >= 0 ? val[i] + solve(W - wt[i], i + 1, val, wt) : 0;
    int exclude = solve(W, i + 1, val, wt);
    return max(include, exclude);
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    return solve(W, 0, val, wt);
}

//memoization
int solve(int W, int i, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
    if(i >= val.size())return 0;
    if(dp[i][W] != -1)return dp[i][W];
    int include =  W - wt[i] >= 0 ? val[i] + solve(W - wt[i], i + 1, val, wt, dp) : 0;
    int exclude = solve(W, i + 1, val, wt, dp);
    dp[i][W] = max(include, exclude);
    return dp[i][W];
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    vector<vector<int>> dp(val.size(), vector<int>(W + 1, -1));
    return solve(W, 0, val, wt, dp);
}

//tabulation
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, 0));
    for(int i = val.size() - 1;i >= 0;i--){
        for(int w = 0; w <= W;w++){
            int include =  w - wt[i] >= 0 ? val[i] + dp[i + 1][w-wt[i]] : 0;
            int exclude = dp[i + 1][w];
            dp[i][w] = max(include, exclude);
        }
    }
    return dp[0][W];
}

//space-optimized: #1
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    vector<int> next(W + 1, 0);
    vector<int> curr(W + 1, 0);
    for(int i = val.size() - 1;i >= 0;i--){
        for(int w = 0; w <= W;w++){
            int include =  w - wt[i] >= 0 ? val[i] + next[w-wt[i]] : 0;
            int exclude = next[w];
            curr[w] = max(include, exclude);
        }
        next = curr;
    }
    return next[W];
}


//space-optimized: #2
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> next(W + 1, 0);
    for(int i = n - 1;i>= 0;i--){
        for(int w = W;w >= 0;w--){
            int include = w - wt[i] >= 0 ? val[i] + next[w-wt[i]] : 0;
            int exclude = next[w];
            next[w] = max(include, exclude);
        }
    }
    return next[W];
}