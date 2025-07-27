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

int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root)return 0;
    int curr = root->val >= low && root->val <= high ? root->val : 0;
    int left = root->val < low ? 0 : rangeSumBST(root->left, low, high);
    int right = root->val > high ? 0 : rangeSumBST(root->right, low, high);
    
    return left + right + curr;
}