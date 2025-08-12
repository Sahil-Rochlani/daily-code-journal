#include<bits/stdc++.h>
using namespace std;
//recursion
int solve(vector<int> &heights, int k, int i){
    if(i == heights.size() - 1)return 0;
    int ans = INT_MAX;
    for(int j = 1;j <= k && j + i < heights.size();j++){
        ans = min(ans, abs(heights[i] - heights[i + j]) + solve(heights, k, i + j));
    }
    return ans;
}
int minCost(vector<int>& heights, int k) {
    // Code here
    return solve(heights, k, 0);
}

//memoization

int solve(vector<int> &heights, int k, int i, vector<int> &dp){
    if(i == heights.size() - 1)return 0;
    if(dp[i] != -1)return dp[i];
    int ans = INT_MAX;
    for(int j = 1;j <= k && j + i < heights.size();j++){
        ans = min(ans, abs(heights[i] - heights[i + j]) + solve(heights, k, i + j, dp));
    }
    dp[i] = ans;
    return dp[i];
}
int minCost(vector<int>& heights, int k) {
    // Code here
    vector<int> dp(heights.size(), -1);
    return solve(heights, k, 0, dp);
}

//tabulation

int minCost(vector<int>& heights, int k) {
    // Code here
    vector<int> dp(heights.size(), -1);
    dp[heights.size() - 1] = 0;
    for(int i = heights.size() - 2;i >= 0;i--){
        int ans = INT_MAX;
        for(int j = 1;j <= k && j + i < heights.size();j++){
            ans = min(ans, abs(heights[i] - heights[i + j]) + dp[i + j]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
