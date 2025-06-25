#include<bits/stdc++.h>
using namespace std;
int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')st.push(ch);
            else if(ch == ')'){
                bool operatorFound = false;
                while(!st.empty() && st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        operatorFound = true;
                    }
                    st.pop();
                    
                }
                if(!operatorFound)return 1;
                st.pop();
            }
        }
        return 0;
    }