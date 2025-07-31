#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Placeholder logic for finding k closest points to the origin
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    for(int i = 0;i < points.size();i++){
        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        pq.push({dist, i});
    }
    vector<vector<int>> ans;
    while(!pq.empty() && k > 0){
        ans.push_back(points[pq.top().second]);
        pq.pop();
        k--;
    }
    return ans;
}