#include<bits/stdc++.h>
using namespace std;


//approach 1: using recursion to handle nested components
string recurse(string s, int &i){
    int num = 0;
    while(i < s.length() && isdigit(s[i])){
        num = num * 10 + s[i++] - '0';
    }
    i++;
    string segment = "";
    while(i < s.length() && s[i] != ']'){
        if(isdigit(s[i])){
            segment += recurse(s, i);
        }
        else segment += s[i++];
    }
    i++;
    string ans = "";
    for(int j = 1;j <= num;j++){
        ans += segment;
    }
    return ans;
}
string decodeString(string s) {
    string ans = "";
    int i = 0;
    while(i < s.length()){
        if(isdigit(s[i])){
            ans += recurse(s, i);
        }
        else {
            if(isalpha(s[i]))ans += s[i];
            i++;
        }
    }
    return ans;
}

//approach 2: using stack to handle nesting like before nesting store the current state and after exiting merge it with curr state
string decodeString(string s) {
    stack<string> strstk;
    stack<int> numstk;
    string currStr = "";
    int i = 0;
    while(i < s.length()){
        if(isdigit(s[i])){
            int num = 0;
            while(i < s.length() && isdigit(s[i])){
                num = num * 10 + s[i++] - '0';
            }
            numstk.push(num);
        }
        else if(s[i] == '['){
            strstk.push(currStr);
            currStr = "";
            i++;
        }
        else if(s[i] == ']'){
            string top = strstk.top(); strstk.pop();
            int num = numstk.top(); numstk.pop();
            for(int j = 1;j <= num;j++){
                top += currStr;
            }
            currStr = top;
            i++;
        }
        else{
            currStr += s[i++];
        }
    }
    return currStr;

}