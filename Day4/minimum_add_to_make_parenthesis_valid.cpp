#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(!st.empty() && st.top() == 
            '(' && ch == ')')st.pop();
            else{
                st.push(ch);
            }
        }
        
        return st.size();
    }