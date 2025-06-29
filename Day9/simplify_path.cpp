#include<bits/stdc++.h>
using namespace std;
//approach 1
string simplifyPath(string s) {
        // Placeholder for logic to simplify path
        string ans;
        
        for(int i = 0;i < s.length();i++){
            if(isalpha(s[i])){
                ans.push_back(s[i]);
            }
            else if(s[i] == '/'){
                if(ans.back() != '/' || ans.empty())ans.push_back(s[i]);
            }
            else if(s[i] == '.'){
                int count = 0;
                int j = i;
                while(j < s.length() && s[j] == '.'){
                    count++;
                    j++;
                }
                if(count == 1)i++;
                else if(count == 2){
                    if(ans.size() > 1)ans.pop_back();
                    while(!ans.empty() && ans.back() != '/'){
                        ans.pop_back();
                    }
                    i+=2;
                }
                else{
                    while(s[i] == '.'){
                        ans.push_back(s[i++]);
                    }
                    i--;
                }
                
            }
        }
        while(ans.size() > 1 && ans.back() == '/')ans.pop_back();
        return ans;
    }
//approach 2

string simplifyPath(string path) {
        stack<string> st;
        for(int i = 0;i < path.length();i++){
            string dir = "";
            while(i < path.length() && path[i] != '/'){
                dir += path[i++];
            }
            if(dir == ".."){
                if(!st.empty())st.pop();
            }
            else if(dir != "" && dir != "."){
                st.push(dir);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }

//approach 3

string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string segment;
        while(getline(ss, segment, '/')){
            if(segment == ".."){
                if(!st.empty())st.pop();
            }
            else if(segment != "." && segment != "")st.push(segment);
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }