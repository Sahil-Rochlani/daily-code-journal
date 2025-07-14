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

int solve(TreeNode* root){
    if(!root)return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    int curr = root->val;
    root->val = left + right;
    return root->val + curr;
}
void toSumTree(TreeNode* root) {
    solve(root);
}
