#include<bits/stdc++.h>
using namespace std;
//recursion
int solve(vector<int> &heights, int i){
    if(i == heights.size() - 1)return 0;
    int one = i + 1 < heights.size() ? abs(heights[i + 1] - heights[i]) + solve(heights, i + 1) : INT_MAX;
    int two = i + 2 < heights.size() ? abs(heights[i + 2] - heights[i]) + solve(heights, i + 2) : INT_MAX;
    return min(one, two);
}
int minCost(vector<int>& heights) {
    return solve(heights, 0);
}

//memoization

int solve(vector<int> &heights, int i, vector<int> &dp){
    if(i == heights.size() - 1)return 0;
    if(dp[i] != -1)return dp[i];
    int one = i + 1 < heights.size() ? abs(heights[i + 1] - heights[i]) + solve(heights, i + 1, dp) : INT_MAX;
    int two = i + 2 < heights.size() ? abs(heights[i + 2] - heights[i]) + solve(heights, i + 2, dp) : INT_MAX;
    dp[i] = min(one, two);
    return dp[i];
}
int minCost(vector<int>& heights) {
    vector<int> dp(heights.size(), -1);
    return solve(heights, 0, dp);
}

//tabulation

int minCost(vector<int>& heights) {
    if(heights.size() == 1)return 0;
    vector<int> dp(heights.size(), -1);
    dp[heights.size() - 1] = 0;
    dp[heights.size() - 2] = abs(heights[heights.size() - 1] - heights[heights.size() - 2]);
    
    for(int i = heights.size() - 3;i >= 0;i--){
        dp[i] = min(abs(heights[i] - heights[i + 1]) + dp[i + 1], abs(heights[i] - heights[i + 2]) + dp[i + 2]);
    }
    return dp[0];
}

//space optimized
int minCost(vector<int>& heights) {
    // Code here
    if(heights.size() == 1)return 0;
    // vector<int> dp(heights.size(), -1);
    int prev2 = 0;
    int prev = abs(heights[heights.size() - 1] - heights[heights.size() - 2]);
    
    for(int i = heights.size() - 3;i >= 0;i--){
        int curr = min(abs(heights[i] - heights[i + 1]) + prev, abs(heights[i] - heights[i + 2]) + prev2);
        prev2 = prev;
        prev = curr;
    }
    //idhar hamesha galti karta hoon prev return karna hai curr nahi
    return prev;
    
}