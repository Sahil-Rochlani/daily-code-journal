#include<bits/stdc++.h>
using namespace std;


//approach 1: using recursion
void helper(ListNode* head, vector<int> &ans, stack<int> &st){
    if(!head){
        return;
    }
    helper(head->next, ans, st);
    while(!st.empty() && st.top() <= head->val)st.pop();
    if(!st.empty())ans.push_back(st.top());
    else ans.push_back(0);
    st.push(head->val);
}
vector<int> nextLargerNodes(ListNode* head) {
    stack<int> st;
    vector<int> ans;
    helper(head, ans, st);
    reverse(ans.begin(), ans.end());
    return ans;
}

//approach 2: by taking LL element in to a vector to perform nge

vector<int> nextlargerllNodes(ListNode* head){
    ListNode* temp = head;
    vector<int> vec;
    while(temp){
        vec.push_back(temp->val);
        temp = temp->next;
    }
    int n = vec.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for(int i = n - 1;i >= 0;i--){
        while(!st.empty() && st.top() <= vec[i]){
            st.pop();
        }
        if(!st.empty())ans[i] = st.top();
        st.push(vec[i]);
    }
    return ans;
}