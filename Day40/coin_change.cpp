#include<bits/stdc++.h>
using namespace std;
//recursion
int solve(vector<int> &coins, int amount){
    if(amount == 0)return 0;
    int mini = INT_MAX;
    for(int i = 0;i < coins.size();i++){
        if(coins[i] <= amount){
            int ans = solve(coins, amount - coins[i]);
            if(ans != INT_MAX)mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int coinChange(vector<int>& coins, int amount) {
    int ans = solve(coins, amount);
    return ans == INT_MAX ? -1 : ans;
}

//memoization

int solve(vector<int> &coins, int amount, vector<int> &dp){
    if(amount == 0)return 0;
    if(dp[amount] != -1)return dp[amount];
    int mini = INT_MAX;
    for(int i = 0;i < coins.size();i++){
        if(coins[i] <= amount){
            int ans = solve(coins, amount - coins[i], dp);
            if(ans != INT_MAX)mini = min(mini, 1 + ans);
        }
    }
    dp[amount] = mini;
    return mini;
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    int ans = solve(coins, amount, dp);
    return ans == INT_MAX ? -1 : ans;
}

//tabulation

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for(int val = 1;val <= amount; val++){
        int mini = INT_MAX;
        for(int i = 0;i < coins.size();i++){
            if(coins[i] <= val){
                if(dp[val - coins[i]] != INT_MAX){
                    mini = min(mini, 1 + dp[val - coins[i]]);
                }
            }
        }
        dp[val] = mini;
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}