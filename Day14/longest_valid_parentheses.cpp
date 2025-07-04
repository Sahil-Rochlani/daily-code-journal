#include<bits/stdc++.h>
using namespace std;

//my approach: overcomplicated by merfing lists using indices
int longestValidParentheses(string s){
    int start = -1, end = -1, ans = 0;
    stack<int> st;
    for(int i = 0;i < s.length();i++){
        if(!st.empty() && s[st.top()] == '(' && s[i] == ')'){
            int istart = 0, iend = 0;
            while(i < s.length() && !st.empty() && s[st.top()] == '(' && s[i] == ')'){
                istart = st.top();
                iend = i;
                i++;
                st.pop();
            }
            if(start == -1 && end == -1){
                start = istart;
                end = iend;
            }
            else if(istart - end <= 1){
                start = min(start, istart);
                end = iend;
            }
            else{
                start = istart;
                end = iend;
            }
            ans = max(ans, end - start + 1);
            i--;
        }
        else st.push(i);
    }
    return ans;
}

//approach 2:uncomplucated

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '(')st.push(i);
        else{
            st.pop();
            if(st.empty())st.push(i);
            else ans = max(ans, i-st.top());
        }
    }
    return ans;
}