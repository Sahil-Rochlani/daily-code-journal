#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(string text1, int i, string text2, int j){
    if(i >= text1.size() || j >= text2.size())return 0;
    int ans = 0;
    if(text1[i] == text2[j])ans = 1 + solve(text1, i + 1, text2, j + 1);
    else ans = max(solve(text1, i + 1, text2, j), solve(text1, i, text2, j + 1));
    return ans;
}
int longestCommonSubsequence(string text1, string text2) {
    return solve(text1, 0, text2, 0);
}

//memoization
int solve(string text1, int i, string text2, int j, vector<vector<int>> &dp){
    if(i >= text1.size() || j >= text2.size())return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(text1[i] == text2[j])ans = 1 + solve(text1, i + 1, text2, j + 1);
    else ans = max(solve(text1, i + 1, text2, j), solve(text1, i, text2, j + 1));
    dp[i][j] = ans;
    return dp[i][j];
}
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return solve(text1, 0, text2, 0, dp);
}

//tabulation :1

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    int n = text1.size(), m = text2.size();
    for(int i = n - 1;i >= 0;i--){
        for(int j = m - 1;j >= 0;j--){
            int ans = 0;
            if(text1[i] == text2[j])ans = 1 + dp[i + 1][j + 1];
            else ans = max(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//space-optimization :#1

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    if(n < m)return longestCommonSubsequence(text2, text1);
    vector<int> next(m + 1, 0);
    vector<int> curr(m + 1, 0);
    for(int i = n - 1;i >= 0;i--){
        for(int j = m - 1;j >= 0;j--){
            int ans = 0;
            if(text1[i] == text2[j])ans = 1 + next[j + 1];
            else ans = max(next[j], curr[j + 1]);
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

//space-optimization: 2

int longestCommonSubsequence(string text1, string text2) {
    vector<int> next(text2.size() + 1, 0);
    int prevDiagonal = 0;
    int n = text1.size(), m = text2.size();
    if(n < m)return longestCommonSubsequence(text2, text1);
    for(int i = n - 1;i >= 0;i--){
        prevDiagonal = next[m];
        for(int j = m - 1;j >= 0;j--){
            int ans = 0;
            if(text1[i] == text2[j])ans = 1 + prevDiagonal;
            else ans = max(next[j], next[j + 1]);
            prevDiagonal = next[j];
            next[j] = ans;
        }
    }
    return next[0];
}