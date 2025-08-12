#include<bits/stdc++.h>
using namespace std;
//recursion
int solve4(int n){
  if(n == 0)return 0;
  if(n == 1)return 1;
  return solve4(n - 1) + solve4(n - 2);
}

//top down: rec + memoization

int solve(int n, vector<int> &dp){
    if(n == 0)return 0;
    if(n == 1)return 1;
    if(dp[n] != -1)return dp[n];
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}

int fib(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

//bottom up: tabulation
int solve2(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i <= n;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//space optimized
int solve3(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    int prev2 = 0, prev1 = 1;
    for(int i = 2; i <= n;i++){
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
