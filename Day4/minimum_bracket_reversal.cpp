#include<bits/stdc++.h>
using namespace std;

int countReversals(string str) {
        
        if(str.length() & 1)return -1;
        // stack<char> st;
        int open = 0, close = 0;
        for(char ch : str){
            if(ch == '{'){
                open++;
            }
            else{
                if(open > 0)open--;
                else close++;
            }
        }
        return (open + 1) / 2 + (close + 1) / 2;
        
    }