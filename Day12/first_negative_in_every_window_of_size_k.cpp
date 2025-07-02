#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegInt(vector<int>& arr, int k) {
    // write code here
    deque<int> dq;
    vector<int> ans;
    
    //process 1st window
    for(int i = 0;i < k;i++){
        if(arr[i] < 0)dq.push_back(i);
    }
    if(!dq.empty())ans.push_back(arr[dq.front()]);
    else ans.push_back(0);
    
    //process remaining windows
    for(int i = k;i < arr.size();i++){
        if(!dq.empty() && (i - dq.front() >= k))dq.pop_front();
        if(arr[i] < 0)dq.push_back(i);
        if(!dq.empty())ans.push_back(arr[dq.front()]);
        else ans.push_back(0);
    }
    return ans;
}