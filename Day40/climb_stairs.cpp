#include<bits/stdc++.h>
using namespace std;
//recursion
int climbStairs(int n) {
    if(n == 1)return 1;
    if(n == 0)return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

//memoization

int solve(int n, vector<int> &dp){
    if(n == 0 || n == 1)return 1;
    if(dp[n] != -1)return dp[n];
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

//tabulation

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//space optimized
int climbStairs(int n) {
    int prev2 = 1;
    int prev = 1;
    for(int i = 2; i <= n;i++){
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}