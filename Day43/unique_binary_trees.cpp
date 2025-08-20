#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(int s, int e){
    if(s >= e)return 1;
    
    int ans = 0;
    for(int i = s;i <= e;i++){
        ans += solve(s, i - 1) * solve(i + 1, e);
    }
    return ans;
}
int numTrees(int n) {
    return solve(1, n);
}

//memoization
int solve(int s, int e, vector<vector<int>> &dp){
    if(s >= e)return 1;
    if(dp[s][e] != -1)return dp[s][e];
    int ans = 0;
    for(int i = s;i <= e;i++){
        ans += solve(s, i - 1, dp) * solve(i + 1, e, dp);
    }
    dp[s][e] = ans;
    return ans;
}
int numTrees(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, dp);
}

//tabulation :1

int numTrees(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for(int s = n; s >= 1;s--){
        for(int e = s + 1;e <= n;e++){
            int ans = 0;
            for(int i = s;i <= e;i++){
                ans += (i - 1 >= s ? dp[s][i - 1] :1) * (i + 1 <= e ? dp[i + 1][e] : 1);
            }
            dp[s][e] = ans;
        }
    }
    return dp[1][n];
}

//tabulation :2

int numTrees(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for(int len = 2; len <= n;len++){
        for(int s = 1;s <= n - len + 1;s++){
            int e  = s + len - 1;
            int ans = 0;
            for(int i = s;i <= e;i++){
                ans += (i - 1 >= s ? dp[s][i - 1] :1) * (i + 1 <= e ? dp[i + 1][e] : 1);
            }
            dp[s][e] = ans;
        }
    }
    return dp[1][n];
}