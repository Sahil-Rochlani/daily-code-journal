#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(string s, int i, int j){
    if(i > j)return 0;
    if(i == j)return 1;
    int ans = 0;
    if(s[i] == s[j]){
        ans = 2 + solve(s, i + 1, j - 1);
    }
    else ans = max(solve(s, i + 1, j), solve(s, i, j - 1));
    return ans;
}
int longestPalindromeSubseq(string s) {
    return solve(s, 0, s.length() - 1);
}

//memoization
int solve(string &s, int i, int j, vector<vector<int>> &dp){
    if(i > j)return 0;
    if(i == j)return 1;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(s[i] == s[j]){
        ans = 2 + solve(s, i + 1, j - 1, dp);
    }
    else ans = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
    dp[i][j] = ans;
    return ans;
}
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(s, 0, s.length() - 1, dp);
}

//tabulation :1

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = n - 1;i >= 0;i--){
        dp[i][i] = 1;
        for(int j = i + 1;j < n;j++){
            int ans = 0;
            if(s[i] == s[j]){
                ans = 2 + dp[i + 1][j - 1];
            }
            else{
                ans = max(dp[i + 1][j], dp[i][j - 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}

//space-optimization :#1

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for(int i = n - 1;i >= 0;i--){
        curr[i] = 1;
        for(int j = i + 1;j < n;j++){
            int ans = 0;
            if(s[i] == s[j]){
                ans = 2 + next[j - 1];
            }
            else{
                ans = max(next[j], curr[j - 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[n - 1];
}

//space-optimization: 2

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<int> next(n + 1, 0);
    for(int i = n - 1;i >= 0;i--){
        next[i] = 1;
        int diagonal = 0;
        for(int j = i + 1;j < n;j++){
            int ans = 0;
            if(s[i] == s[j]){
                ans = 2 + diagonal;
            }
            else{
                ans = max(next[j], next[j - 1]);
            }
            diagonal = next[j];
            next[j] = ans;
        }
    }
    return next[n - 1];
}