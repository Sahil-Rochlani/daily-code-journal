#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &heights){
    int n = heights.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = 0;i < n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
        if(!st.empty())ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> &heights){
    int n = heights.size();
    vector<int> ans(n, n);
    stack<int> st;
    for(int i = n - 1;i >= 0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
        if(!st.empty())ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestAreaHistogram(vector<int> &heights){
    vector<int> prev = prevSmaller(heights);
    vector<int> next = nextSmaller(heights);
    int ans = -1;
    for(int i = 0;i < heights.size();i++){
        ans = max(ans, heights[i] * (next[i] - prev[i] - 1));
    }
    return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> prefix(matrix.size(), vector<int> (matrix[0].size(), 0));
    for(int i = 0;i < matrix[0].size();i++){
        int sum = 0;
        for(int j = 0;j < matrix.size();j++){
            if(matrix[j][i] == '1')sum++;
            else sum = 0;
            prefix[j][i] = sum;
        }
    }
    int ans = -1;
    for(int i = 0;i < prefix.size();i++){
        ans = max(ans, largestAreaHistogram(prefix[i]));
    }
    return ans;
}