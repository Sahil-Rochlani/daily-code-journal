#include<bits/stdc++.h>
using namespace std;


//my approach: reducing search when no nges on the right by only keep a increasing sequence of numbers
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n, INT_MIN);
    stack<int> st;
    for(int i = n - 1;i >= 0;i--){
        while(!st.empty() && st.top() <= nums[i])st.pop();
        if(!st.empty())next[i] = st.top();
        st.push(nums[i]);
    }
    vector<int> temp;
    for(int i = 0;i < nums.size();i++){
        
        if(next[i] == INT_MIN && !temp.empty() && (temp.back() >= nums[i])){
            for(int j = 0;j < temp.size();j++){
                if(temp[j] > nums[i]){
                    next[i] = temp[j];
                    break;
                }
            }
            
        }
        if(next[i] == INT_MIN)next[i] = -1;
        if(temp.empty() || nums[i] > temp.back())temp.push_back(nums[i]);
        
    }
    return next;
    
}

//optimal approach using monotonic stack on a circular array 2 * n % concept

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = 2 * n - 1;i >= 0;i--){
        while(!st.empty() && st.top() <= nums[i % n])st.pop();
        if(i < n && !st.empty())ans[i] = st.top();
        st.push(nums[i % n]);
    }
    return ans;
}

