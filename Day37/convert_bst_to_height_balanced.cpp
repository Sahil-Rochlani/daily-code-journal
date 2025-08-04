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

void inorder(TreeNode* root, vector<int> &ans){
    if(!root)return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
TreeNode* build(vector<int> &ans, int &i, int n){
    if(n < 1)return NULL;
    TreeNode* left = build(ans, i, n / 2);
    TreeNode* root = new TreeNode(ans[i]);
    i++;
    root->left = left;
    root->right = build(ans, i, n - n / 2 - 1);
    return root;
}
TreeNode* balanceBST(TreeNode* root) {
    if(!root)return NULL;
    vector<int> ans;
    inorder(root, ans);
    int i = 0;
    return build(ans, i, ans.size());
}