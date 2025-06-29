#include<bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> m = {{'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}};

    void solver(string &digits, int i, string &output, vector<string> &ans){
        if(i >= digits.length()){
            ans.push_back(output);
        }
        vector<char> temp = m[digits[i]];
        for(char ch : temp){
            output.push_back(ch);
            solver(digits, i + 1, output, ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "")return {};
        string output = "";
        vector<string> ans;
        solver(digits, 0, output, ans);
        return ans;
    }