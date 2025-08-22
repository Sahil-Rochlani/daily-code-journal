#include<bits/stdc++.h>
using namespace std;

//recursion
bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2];
}
int solve(vector<vector<int>>& cuboids, int i, int prev){
    if(i >= cuboids.size())return 0;
    int include = (prev == -1) || (check(cuboids[i], cuboids[prev])) ? cuboids[i][2] + solve(cuboids, i + 1, i) : 0;
    int exclude = solve(cuboids, i + 1, prev);
    return max(include, exclude);
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &i : cuboids){
        sort(i.begin(), i.end());
    }
    sort(cuboids.begin(), cuboids.end());
    return solve(cuboids, 0, -1);
}

//memoization
bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2];
}
int solve(vector<vector<int>>& cuboids, int i, int prev, vector<vector<int>> &dp){
    if(i >= cuboids.size())return 0;
    if(dp[i][prev + 1] != -1)return dp[i][prev + 1];
    int include = (prev == -1) || (check(cuboids[i], cuboids[prev])) ? cuboids[i][2] + solve(cuboids, i + 1, i, dp) : 0;
    int exclude = solve(cuboids, i + 1, prev, dp);
    dp[i][prev + 1] = max(include, exclude);
    return dp[i][prev + 1];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &i : cuboids){
        sort(i.begin(), i.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(cuboids, 0, -1, dp);
}


//tabulation
bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &i : cuboids){
        sort(i.begin(), i.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || (check(cuboids[i], cuboids[prev])) ? cuboids[i][2] + dp[i + 1][i + 1] : 0;
            int exclude = dp[i + 1][prev + 1];
            dp[i][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

//space optimization #1

bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &i : cuboids){
        sort(i.begin(), i.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || (check(cuboids[i], cuboids[prev])) ? cuboids[i][2] + next[i + 1] : 0;
            int exclude = next[prev + 1];
            curr[prev + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

//space optimization #2

bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &i : cuboids){
        sort(i.begin(), i.end());
    }
    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size();
    vector<int> next(n + 1, 0);
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || (check(cuboids[i], cuboids[prev])) ? cuboids[i][2] + next[i + 1] : 0;
            int exclude = next[prev + 1];
            next[prev + 1] = max(include, exclude);
        }
    }
    return next[0];
}