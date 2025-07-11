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

bool pathSum(TreeNode* root, int target){
    if(!root)return false;
    if(!root->left && !root->right && target - root->val == 0)return true;

    return pathSum(root->left, target - root->val) || pathSum(root->right, target - root->val);
}