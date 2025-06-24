#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
        stack<char>st;
        for(char ch : s){
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()){
            if(ans == "")ans = st.top();
            else ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }