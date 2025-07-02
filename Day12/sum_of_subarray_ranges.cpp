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

vector<int> nextGreater(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, n);
    stack<int> st;
    for(int i = n - 1;i >= 0;i--){
        while(!st.empty() && nums[st.top()] <= nums[i])st.pop();
        if(!st.empty())ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerEqual(vector<int> &nums){
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

vector<int> prevGreaterEqual(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = 0;i < n;i++){
        while(!st.empty() && nums[st.top()] < nums[i])st.pop();
        if(!st.empty())ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
long long subArrayRanges(vector<int>& nums) {
    vector<int> prevSE = prevSmallerEqual(nums);
    vector<int> prevGE = prevGreaterEqual(nums);
    vector<int> nextS = nextSmaller(nums);
    vector<int> nextG = nextGreater(nums);
    long long sum = 0;
    for(int i = 0;i < nums.size();i++){
        int leftG = i - prevGE[i];
        int rightG = nextG[i] - i;
        int leftS = i - prevSE[i];
        int rightS = nextS[i] - i;
        long long mincontri = -1 * 1ll * leftS * rightS;
        long long maxcontri = 1ll * rightG * leftG;
        cout << mincontri << " " << maxcontri << endl;
        sum = (sum + (maxcontri + mincontri) * nums[i]);
    }
    return sum;
}