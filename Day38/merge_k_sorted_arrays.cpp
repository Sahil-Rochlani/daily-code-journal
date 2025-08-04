#include<bits/stdc++.h>
using namespace std;

class Info{
    public:
        int ele;
        int row;
        int col;
        
        Info(int val, int rowi, int coli) : ele(val), row(rowi), col(coli) {}
};

class compare{
public:
  bool operator()(Info* a, Info* b){
      return a->ele > b->ele;
  }  
};

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        // code here
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        int rows = arr.size();
        int cols = arr[0].size();
        for(int i = 0;i < k;i++){
            int ele = arr[i][0];
            Info* temp = new Info(ele, i, 0);
            pq.push(temp);
        }
        while(!pq.empty()){
            Info* front = pq.top(); pq.pop();
            int ele = front->ele;
            int row = front->row;
            int col = front->col;
            ans.push_back(ele);
            if(col + 1 < cols){
                Info* temp = new Info(arr[row][col + 1], row, col + 1);
                pq.push(temp);
            }
        }
        return ans;
        
    }
};