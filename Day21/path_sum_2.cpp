#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode* root, int target, vector<int> &path, vector<vector<int>> &ans){
    if(!root)return;
    path.push_back(root->val);
    if(!root->left && !root->right && target - root->val == 0){
        ans.push_back(path);
    }
    solve(root->left, target - root->val, path, ans);
    solve(root->right, target - root->val, path, ans);
    path.pop_back();
}

vector<vector<int>> pathSum2(TreeNode* root, int target){
    vector<vector<int>> ans;
    vector<int> path;

}