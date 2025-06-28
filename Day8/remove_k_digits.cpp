#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    if(k == num.length())return "0";
    for(char ch : num){
        while(!st.empty() && k > 0 && st.top() > ch){
            st.pop();
            k--;
        }
        st.push(ch);
    }
    while(!st.empty() && k > 0){
        st.pop();
        k--;
    }
    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    while(ans.back() == '0')ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}