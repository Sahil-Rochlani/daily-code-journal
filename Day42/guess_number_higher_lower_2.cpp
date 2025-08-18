#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(int s, int e){
    if(s >= e)return 0;
    int ans = INT_MAX;
    for(int i = s;i <= e;i++){
        int lower = (i - 1 >= s ? solve(s, i - 1) + i : 0);
        int higher = (i + 1 <= e ? i + solve(i + 1, e) : 0);
        int res = max(lower, higher);
        ans = min(ans, res);
    }
    return ans;
}
int getMoneyAmount(int n) {
    int ans = INT_MAX;
    return solve(1, n);
}

//memoization
int solve(int s, int e, vector<vector<int>> &dp){
    if(s >= e)return 0;
    if(dp[s][e] != -1)return dp[s][e];
    int ans = INT_MAX;
    for(int i = s;i <= e;i++){
        int lower = (i - 1 >= s ? solve(s, i - 1, dp) + i : 0);
        int higher = (i + 1 <= e ? i + solve(i + 1, e, dp) : 0);
        int res = max(lower, higher);
        ans = min(ans, res);
    }
    dp[s][e] = ans;
    return ans;
}
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, dp);
}

//tabulation
int getMoneyAmount(int n) {
    //prefilling to 0 to prefill base case
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int s = n;s >= 1;s--){
        for(int e = s + 1;e <= n;e++){
            int ans = INT_MAX;
            for(int i = s;i <= e;i++){
                int lower = i - 1 >= s ? i + dp[s][i - 1] : 0;
                int higher = i + 1 <= e ? i + dp[i + 1][e] : 0;
                ans = min(ans, max(lower, higher));
            }
            dp[s][e] = ans;
        }
    }
    return dp[1][n];
}
