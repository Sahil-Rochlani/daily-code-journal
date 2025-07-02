#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;
        for(int i = n - 1;i >= 0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();
            if(!st.empty())ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 0;i < n;i++){
            while(!st.empty() && nums[st.top()] > nums[i])st.pop();
            if(!st.empty())ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& nums) {
        vector<int> prev = prevSmaller(nums);
        vector<int> next = nextSmaller(nums);
        int mod = 1e9 + 7, sum = 0;
        for(int i = 0;i < nums.size();i++){
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contri = (left * right * nums[i]) % mod;
            sum = (sum + contri) % mod;
        }
        return sum % mod;
    }