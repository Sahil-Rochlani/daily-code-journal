#include<bits/stdc++.h>
using namespace std;
//recursion
int solve(vector<int> &nums, int i, int prev){
    if(i >= nums.size())return 0;
    int include = (prev == -1) || (nums[i] > nums[prev]) ? 1 + solve(nums, i + 1, i) : 0;
    int exclude = solve(nums, i + 1, prev);
    return max(include, exclude);
}
int lengthOfLIS(vector<int>& nums) {
    return solve(nums, 0, -1);
}

//memoization

int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp){
    if(i >= nums.size())return 0;
    if(dp[i][prev + 1] != -1)return dp[i][prev + 1];
    int include = (prev == -1) || (nums[i] > nums[prev]) ? 1 + solve(nums, i + 1, i, dp) : 0;
    int exclude = solve(nums, i + 1, prev, dp);
    dp[i][prev + 1] = max(include, exclude);
    return dp[i][prev + 1];
}
int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    return solve(nums, 0, -1, dp);
}

//tabulation

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //create and initialize dp array
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    //prefill dp array, 
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || (nums[i] > nums[prev]) ? 1 + dp[i + 1][i + 1] : 0;
            int exclude = dp[i + 1][prev + 1];
            dp[i][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

//space optimization: #1
int lengthOfLIS(vector<int>& nums) {
    vector<int> curr(nums.size() + 1, 0);
    vector<int> next(nums.size() + 1, 0);
    int n = nums.size();
    for(int i = n - 1;i >= 0;i--){
        for(int j = i - 1;j >= -1;j--){
            int include = (j == -1) || (nums[i] > nums[j]) ? 1 + next[i + 1] : 0;
            int exclude = next[j + 1];
            curr[j + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

//space optimization: #2
int lengthOfLIS(vector<int>& nums) {
    vector<int> next(nums.size() + 1, 0);
    int n = nums.size();
    for(int i = n - 1;i >= 0;i--){
        for(int j = i - 1;j >= -1;j--){
            int include = (j == -1) || (nums[i] > nums[j]) ? 1 + next[i + 1] : 0;
            int exclude = next[j + 1];
            next[j + 1] = max(include, exclude);
        }
    }
    return next[0];
}
