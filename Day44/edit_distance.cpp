#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(string word1, int i, string word2, int j){
    if(i >= word1.length())return word2.length() - j;
    if(j >= word2.length())return word1.length() - i;
    if(word1[i] == word2[j]){
        return solve(word1, i + 1, word2, j + 1);
    }
    int replace = 1 + solve(word1, i + 1, word2, j + 1);
    int deleted = 1 + solve(word1, i + 1, word2, j);
    int insert = 1 + solve(word1, i, word2, j + 1);
    return min(replace, min(deleted, insert));
}
int minDistance(string word1, string word2) {
    return solve(word1, 0, word2, 0);
}

//memoization
int solve(string word1, int i, string word2, int j, vector<vector<int>> &dp){
    if(i >= word1.length())return word2.length() - j;
    if(j >= word2.length())return word1.length() - i;
    if(dp[i][j] != -1)return dp[i][j];
    if(word1[i] == word2[j]){
        return solve(word1, i + 1, word2, j + 1, dp);
    }
    int replace = 1 + solve(word1, i + 1, word2, j + 1, dp);
    int deleted = 1 + solve(word1, i + 1, word2, j,dp);
    int insert = 1 + solve(word1, i, word2, j + 1, dp);
    dp[i][j] = min(replace, min(deleted, insert));
    return dp[i][j];
}
int minDistance(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(word1, 0, word2, 0, dp);
}

//tabulation
int minDistance(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0;i < n;i++){ dp[i][m] = n - i; }
    for(int i = 0;i < m;i++){ dp[n][i] = m - i; }
    for(int i = n - 1;i >= 0;i--){
        for(int j = m - 1;j >= 0;j--){
            int ans;
            if(word1[i] == word2[j]){
                ans = dp[i + 1][j + 1];
            }
            else{
                int insert = 1 + dp[i][j + 1];
                int deleted = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min(insert, min(deleted, replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//space optimization #1

int minDistance(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    if(n < m)return minDistance(word2, word1);
    vector<int> curr(m + 1, 0), next(m + 1, 0);
    for(int i = 0;i < m;i++){ next[i] = m - i; }
    for(int i = n - 1;i >= 0;i--){
        curr[m] = n - i;
        for(int j = m - 1;j >= 0;j--){
            int ans;
            if(word1[i] == word2[j]){
                ans = next[j + 1];
            }
            else{
                int insert = 1 + curr[j + 1];
                int deleted = 1 + next[j];
                int replace = 1 + next[j + 1];
                ans = min(insert, min(deleted, replace));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

//space optimization #2

int minDistance(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    if(n < m)return minDistance(word2, word1);
    vector<int> next(m + 1, 0);
    for(int i = 0;i < m;i++){ next[i] = m - i; }
    for(int i = n - 1;i >= 0;i--){
        int diagonal = next[m];
        next[m] = n - i;
        for(int j = m - 1;j >= 0;j--){
            int ans;
            if(word1[i] == word2[j]){
                ans = diagonal;
            }
            else{
                int insert = 1 + diagonal;
                int deleted = 1 + next[j];
                int replace = 1 + next[j + 1];
                ans = min(insert, min(deleted, replace));
            }
            diagonal = next[j];
            next[j] = ans;
        }
    }
    return next[0];
}