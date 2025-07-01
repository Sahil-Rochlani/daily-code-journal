#include<bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> vec;
    for(int i = 0;i < position.size();i++){
        vec.push_back({position[i], speed[i]});
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    stack<float> st;
    for(auto &it : vec){
        float time = (float)(target - it.first) / it.second;
        if(st.empty() || st.top() < time)st.push(time);
    }
    return st.size();
}