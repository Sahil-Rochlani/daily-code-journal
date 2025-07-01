#include<bits/stdc++.h>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<double> ans(cars.size(), -1);
    stack<int> st;
    for(int i = cars.size() - 1;i >= 0;i--){
        while(!st.empty() && cars[st.top()][1] >= cars[i][1])st.pop();
        while(!st.empty()){
            double cTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
            if(cTime <= ans[st.top()] || ans[st.top()] == -1){
                ans[i] = cTime;
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    return ans;
}