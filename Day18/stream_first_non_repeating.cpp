#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string &s) {
    queue<char> q;
    unordered_map<char, int>m;
    string ans;
    for(int i = 0;i < s.length();i++){
        m[s[i]]++;
        if(m[s[i]] == 1)q.push(s[i]);
        while(!q.empty() && m[q.front()] > 1)q.pop();
        if(!q.empty())ans.push_back(q.front());
        else ans.push_back('#');
    }
    return ans;
}