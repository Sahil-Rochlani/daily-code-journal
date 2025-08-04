#include<bits/stdc++.h>
using namespace std;

class Info{
    public:
        int ele;
        int row;
        int col;

        Info(int ele, int row, int col) : ele(ele), row(row), col(col) {}
};

class cmp{
    public:
        bool operator()(Info* a, Info* b){
            return a->ele > b->ele;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, cmp>pq;
        int maxi = INT_MIN, mini = INT_MAX;

        for(int i = 0;i < nums.size();i++){
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            Info* temp = new Info(nums[i][0], i, 0);
            pq.push(temp);
        }

        int ansMin = mini, ansMax = maxi;

        while(pq.size() >= nums.size()){
            Info* top = pq.top();pq.pop();
            int ele = top->ele, row = top->row, col = top->col;
            mini = ele;
            if((maxi - mini) < (ansMax - ansMin)){
                ansMin = mini;
                ansMax = maxi;
            }
            if(((maxi - mini) == (ansMax - ansMin)) && mini < ansMin){
                ansMin = mini;
                ansMax = maxi;
            }
            if(col + 1 < nums[row].size()){
                Info* temp = new Info(nums[row][col + 1], row, col + 1);
                pq.push(temp);
                maxi = max(maxi, temp->ele);
            }
        }
        return {ansMin, ansMax};
    }
    
};