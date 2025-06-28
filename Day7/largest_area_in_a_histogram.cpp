#include<bits/stdc++.h>
using namespace std;

//approach 1: brute force
int largestRectangleArea(vector<int>& heights) {
        int ans = INT_MIN;
        for(int i = 0;i < heights.size();i++){
            int mini = heights[i];
            for(int j = i;j >= 0;j--){
                mini = min(mini, heights[j]);
                ans = max(ans, mini * (i - j + 1));
            }
        }
        return ans;
    }