#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int maxlen = 1;
        int start = 0;

        auto expand = [&](int l, int r){
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(r - l + 1 > maxlen){
                maxlen = r - l + 1;
                start = l;
            }
        };
        for(int i = 0;i < s.length();i++){
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxlen);
    }