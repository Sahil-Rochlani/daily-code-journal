#include<bits/stdc++.h>
using namespace std;

//recursion
bool solve(vector<int>& nums, int i, int sum){
    if(i >= nums.size() || sum < 0)return false;
    if(sum == 0)return true;
    bool include = solve(nums, i + 1, sum - nums[i]);
    bool exclude = solve(nums, i + 1, sum);
    return include || exclude;
}
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)return false;
    return solve(nums, 0, sum / 2);
}

//memoization
int solve(vector<int>& nums, int i, int sum, vector<vector<int>> &dp){
    if(i >= nums.size() || sum < 0)return 0;
    if(sum == 0)return 1;
    if(dp[i][sum] != -1)return dp[i][sum];
    int include = solve(nums, i + 1, sum - nums[i], dp);
    int exclude = solve(nums, i + 1, sum, dp);
    dp[i][sum] = include || exclude;
    return dp[i][sum];
}
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)return false;
    vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
    return solve(nums, 0, sum / 2, dp);
}

//tabulation
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)return false;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum / 2 + 1, false));
    //for(int i = 0;i <= nums.size();i++)dp[i][0] = true;
    for(int i = nums.size() - 1;i >= 0;i--){
        for(int s = 1;s <= sum / 2;s++){
            bool include = false;
            if(s - nums[i] >= 0){
                include = ((s - nums[i]) == 0) ? true : dp[i + 1][s - nums[i]];
            }
            bool exclude = dp[i + 1][s];
            dp[i][s] = include || exclude;
        }
    }
    return dp[0][sum / 2];
}

//space-optimized: #1
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)return false;
    vector<int> curr(sum / 2 + 1, false);
    vector<int> next(sum / 2 + 1, false);
    curr[0] = next[0] = true;
    for(int i = nums.size() - 1;i >= 0;i--){
        for(int s = 1;s <= sum / 2;s++){
            bool include = false;
            if(s - nums[i] >= 0){
                include = next[s - nums[i]];
            }
            bool exclude = next[s];
            curr[s] = include || exclude;
        }
        next = curr;
    }
    return next[sum / 2];
}


//space-optimized: #2
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)return false;
    vector<int> next(sum / 2 + 1, false);
    next[0] = true;
    for(int i = nums.size() - 1;i >= 0;i--){
        for(int s = sum / 2;s >= 0;s--){
            bool include = false;
            if(s - nums[i] >= 0){
                include = next[s - nums[i]];
            }
            bool exclude = next[s];
            next[s] = include || exclude;
        }
    }
    return next[sum / 2];
}