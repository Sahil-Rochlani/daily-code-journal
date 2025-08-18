#include<bits/stdc++.h>
using namespace std;

//recursion
int countWays(int n, int k) {
    // code here
    if(n == 1)return k;
    if(n == 2)return k * k;
    return (k - 1)*(countWays(n - 1, k) + countWays(n - 2, k));
}

//memoization
int solve(int n, int k, vector<int> &dp){
    if(n == 1)return k;
    if(n == 2)return k * k;
    if(dp[n] != -1)return dp[n];
    dp[n] = (k - 1) * (solve(n - 1, k, dp) + solve(n - 2, k, dp));
    return dp[n];
}
int countWays(int n, int k) {
    // code here
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

//tabulation
int countWays(int n, int k) {
    // code here
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = k * k;
    for(int i = 3;i <= n;i++){
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

//space-optimized
int countWays(int n, int k) {
    // code here
    if(n == 1)return k;
    int prev2 = k;
    int prev = k * k;
    for(int i = 3;i <= n;i++){
        int curr = (k - 1) * (prev2 + prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}