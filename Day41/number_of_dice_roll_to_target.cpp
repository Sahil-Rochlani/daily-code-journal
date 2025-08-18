#include<bits/stdc++.h>
using namespace std;
//recursion
const int MOD = 1e9 + 7;
int solve(int n, int k, int target){
    if(target < 0)return 0;
    if(n == 0)return target == 0;
    int ans = 0;
    for(int j = 1;j <= k;j++){
        ans += solve(n - 1, k, target - j);
    }
    return ans;
}
int numRollsToTarget(int n, int k, int target) {
    return solve(n, k, target);
}

//memoization

int solve(int n, int k, int target, vector<vector<int>> &dp){
    if(target < 0)return 0;
    if(dp[n][target] != -1)return dp[n][target];
    if(n == 0)return target == 0;
    int ans = 0;
    for(int j = 1;j <= k;j++){
        ans = (ans * 1LL + solve(n - 1, k, target - j, dp)) % MOD;
    }
    dp[n][target] = ans;
    return ans;
}
int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return solve(n, k, target, dp);
}

//tabulation

int numRollsToTarget(int n, int k, int target) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int t = 1;t <= target;t++){
            int ans = 0;
            for(int j = 1;j <= k;j++){
                long long temp = (t-j  >= 0) ? dp[i - 1][t - j] : 0;
                ans = (ans * 1ll + temp) % MOD;
            }
            dp[i][t] = ans;
        }
    }
    return dp[n][target];
}

//space optimized

int numRollsToTarget(int n, int k, int target) {
    vector<int>curr(target + 1, 0);
    vector<int> prev(target + 1, 0);
    prev[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int t = 1;t <= target;t++){
            int ans = 0;
            for(int j = 1;j <= k;j++){
                if(t >= j)
                ans = (ans * 1ll + prev[t - j]) % MOD;
            }
            curr[t] = ans;
        }
        prev = curr;
    }
    return prev[target];
}
