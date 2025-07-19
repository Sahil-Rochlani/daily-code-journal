#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    queue<pair<TreeNode*, int>>q;
    unordered_map<int, vector<int>>m;
    q.push({root, 0});
    int maxi = 0, mini = 0;
    while(!q.empty()){
        TreeNode* front = q.front().first;
        int curr = q.front().second;
        q.pop();
        maxi = max(maxi, curr);
        mini = min(mini, curr);
        m[curr].push_back(front->val);
        if(front->left)q.push({front->left, curr - 1});
        if(front->right)q.push({front->right, curr + 1});
    }
    vector<vector<int>>ans;
    for(int i = mini;i <= maxi;i++){
        ans.push_back(m[i]);
    }
    return ans;
}