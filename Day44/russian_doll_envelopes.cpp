#include<bits/stdc++.h>
using namespace std;

//recursion
bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] > prev[0] && curr[1] > prev[1];
}
int solve(vector<vector<int>> &envelopes, int i, int prev){
    if(i >= envelopes.size())return 0;
    int include  = (prev == -1) || (check(envelopes[i], envelopes[prev])) ? 1 + solve(envelopes, i + 1, i) : 0;
    int exclude = solve(envelopes, i + 1, prev);
    return max(include, exclude);
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    return solve(envelopes, 0, -1);
}

//memoization
bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] > prev[0] && curr[1] > prev[1];
}
int solve(vector<vector<int>> &envelopes, int i, int prev,vector<vector<int>> &dp){
    if(i >= envelopes.size())return 0;
    if(dp[i][prev + 1] != -1)return dp[i][prev + 1];
    int include  = (prev == -1) || (check(envelopes[i], envelopes[prev])) ? 1 + solve(envelopes, i + 1, i, dp) : 0;
    int exclude = solve(envelopes, i + 1, prev, dp);
    dp[i][prev + 1] = max(include, exclude);
    return dp[i][prev + 1];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(envelopes, 0, -1, dp);
}


//tabulation
bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] > prev[0] && curr[1] > prev[1];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return solve(envelopes, 0, -1, dp);
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || check(envelopes[i], envelopes[prev]) ? 1 + dp[i + 1][i + 1] : 0;
            int exclude = dp[i + 1][prev + 1];
            dp[i][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

//space optimization #1

bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] > prev[0] && curr[1] > prev[1];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);
    // return solve(envelopes, 0, -1, dp);
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || check(envelopes[i], envelopes[prev]) ? 1 + next[i + 1] : 0;
            int exclude = next[prev + 1];
            curr[prev + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

//space optimization #2

bool check(vector<int> &curr, vector<int> &prev){
    return curr[0] > prev[0] && curr[1] > prev[1];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<int> next(n + 1, 0);
    for(int i = n - 1;i >= 0;i--){
        for(int prev = i - 1;prev >= -1;prev--){
            int include = (prev == -1) || check(envelopes[i], envelopes[prev]) ? 1 + next[i + 1] : 0;
            int exclude = next[prev + 1];
            next[prev + 1] = max(include, exclude);
        }
    }
    return next[0];
}

//sorting + greedy + binary search
int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Placeholder logic for maximum number of Russian doll envelopes calculation
    sort(envelopes.begin(), envelopes.end(), [&](const auto &a, const auto &b){
        if(a[0] == b[0])return a[1] > b[1];
        return a[0] < b[0];
    });
    int n = envelopes.size();
    vector<int> ans;
    ans.push_back(envelopes[0][1]);
    for(int i = 1;i < n;i++){
        int idx = lower_bound(ans.begin(), ans.end(), envelopes[i][1])- ans.begin();
        if(idx >= ans.size())ans.push_back(envelopes[i][1]);
        else ans[idx] = envelopes[i][1];
    }
    
    return ans.size();
}