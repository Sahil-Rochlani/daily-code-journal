#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
    // code here
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0;i < arr.size();i++)pq.push(arr[i]);
    int ans = 0;
    while(pq.size() > 1){
        int top1 = pq.top();pq.pop();
        int top2 = pq.top();pq.pop();
        int sum = top1 + top2;
        ans += sum;
        pq.push(sum);
    }
    return ans;
}