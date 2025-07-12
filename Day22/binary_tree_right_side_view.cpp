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

void solve(TreeNode* root, int i, vector<int> &ans){
    if(!root)return;
    if(i == ans.size()){
        ans.push_back(root->val);
    }
    solve(root->right, i + 1, ans);
    solve(root->left, i + 1, ans);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}