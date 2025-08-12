#include<bits/stdc++.h>
using namespace std;
//recursion
int solve(vector<int> &nums, int i){
    if(i >= nums.size())return 0;
    int include = nums[i] + solve(nums, i + 2);
    int exclude = solve(nums, i + 1);
    return max(include, exclude);
}
int rob(vector<int>& nums) {
    return solve(nums, 0);
}

//memoization

int solve(vector<int> &nums, int i, vector<int> &dp){
    if(i >= nums.size())return 0;
    if(dp[i] != -1)return dp[i];
    int include = nums[i] + solve(nums, i + 2, dp);
    int exclude = solve(nums, i + 1, dp);
    dp[i] = max(include, exclude);
    return dp[i];
}
int rob(vector<int>& nums) {
    vector<int> dp(nums.size() + 2, -1);
    return solve(nums, 0, dp);
}

//tabulation

int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, -1);
        dp[nums.size()] = 0;
        dp[nums.size() + 1] = 0;

        for(int i = nums.size() - 1;i >= 0;i--){
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }

//space optimized
int rob(vector<int>& nums) {
    int prev2 = 0, prev = 0;
    for(int i = nums.size() - 1;i >= 0;i--){
        int curr = max(prev, nums[i] + prev2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}