#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i < s.length();i++){
            st.push(s[i]);
            if(st.size() >= 3){
                char c = st.top(); st.pop();
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();
                if(a == 'a' && b == 'b' && c == 'c'){
                    //do not push back
                }
                else{
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
        }
        return st.empty();
    }