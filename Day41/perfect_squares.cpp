#include<bits/stdc++.h>
using namespace std;
//recursion
int solve(int n){
    if(n == 0)return 0;
    int mini = INT_MAX;
    for(int i = 1;i <= sqrt(n);i++){
        mini = min(mini, 1 + solve(n - i * i));
    }
    return mini;
}
int numSquares(int n) {
    return solve(n);
}

//memoization

int solve(int n, vector<int> &dp){
    if(n == 0)return 0;
    if(dp[n] != -1)return dp[n];
    int mini = INT_MAX;
    for(int i = 1;i <= sqrt(n);i++){
        mini = min(mini, 1 + solve(n - i * i, dp));
    }
    dp[n] = mini;
    return mini;
}
int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

//tabulation

int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        int mini = INT_MAX;
        for(int j = 1;j * j <= i;j++){
            mini = min(mini, 1 + dp[i - j * j]);
        }
        dp[i] = mini;
    }
    return dp[n];
}
