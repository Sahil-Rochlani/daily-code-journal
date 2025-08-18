#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(vector<int> &arr, int s, int e, vector<vector<int>> &maxVal){
    if(s >= e)return 0;
    int ans = INT_MAX;
    for(int i = s;i < e;i++){
        ans = min(ans, maxVal[s][i] * maxVal[i + 1][e] + solve(arr, s, i, maxVal) + solve(arr, i + 1, e, maxVal));
    }
    return ans;
}
int mctFromLeafValues(vector<int>& arr) {
    vector<vector<int>> maxVal(arr.size(), vector<int>(arr.size(), 0));
    for(int i = 0;i < arr.size();i++){
        maxVal[i][i] = arr[i];
        for(int j = i + 1;j < arr.size();j++){
            maxVal[i][j] = max(arr[j], maxVal[i][j - 1]);
        }
    }
    return solve(arr, 0, arr.size() - 1, maxVal);
}

//memoization
int solve(vector<int> &arr, int s, int e, vector<vector<int>> &maxVal, vector<vector<int>> &dp){
    if(s >= e)return 0;
    if(dp[s][e] != -1) return dp[s][e];
    int ans = INT_MAX;
    for(int i = s;i < e;i++){
        ans = min(ans, maxVal[s][i] * maxVal[i + 1][e] + solve(arr, s, i, maxVal, dp) + solve(arr, i + 1, e, maxVal, dp));
    }
    dp[s][e] = ans;
    return ans;
}
int mctFromLeafValues(vector<int>& arr) {
    vector<vector<int>> maxVal(arr.size(), vector<int>(arr.size(), 0));
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    for(int i = 0;i < arr.size();i++){
        maxVal[i][i] = arr[i];
        for(int j = i + 1;j < arr.size();j++){
            maxVal[i][j] = max(arr[j], maxVal[i][j - 1]);
        }
    }
    return solve(arr, 0, arr.size() - 1, maxVal, dp);
}

//tabulation
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> maxVal(arr.size(), vector<int>(arr.size(), 0));
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
    for(int s = n - 1;s >= 0;s--){
        maxVal[s][s] = arr[s];
        for(int e = s + 1;e < arr.size();e++){
            maxVal[s][e] = max(arr[e], maxVal[s][e - 1]);
            int ans = INT_MAX;
            for(int i = s;i < e;i++){
                ans = min(ans, maxVal[s][i] * maxVal[i + 1][e] + dp[s][i] + dp[i + 1][e]);
            }
            dp[s][e] = ans;
        }
    }
    return dp[0][n - 1];
}
