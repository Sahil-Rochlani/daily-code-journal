#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0;i < nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        for(auto &it : m){
            if((pq.size() < k)){
                pq.push({it.second, it.first});
            }
            else if(it.second > pq.top().first){
                pq.pop();
                pq.push({it.second, it.first});
            } 
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }