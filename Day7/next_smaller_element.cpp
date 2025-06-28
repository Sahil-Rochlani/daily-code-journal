#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr){
  stack<int> st;
  vector<int> ans;
  st.push(-1);
  for(int i = arr.size() - 1;i >= 0;i--){
    while(!st.empty() && st.top() >= arr[i]){
      st.pop();
    } 
    ans.push_back(st.top());
    st.push(arr[i]);
    
  }
  reverse(ans.begin(), ans.end());
  return ans;
}