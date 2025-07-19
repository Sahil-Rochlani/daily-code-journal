#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> solve(TreeNode* root){
    if(!root)return {0, 0};
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    int include = root->val + left.second + right.second;
    int exclude = max(left.first, left.second) + max(right.first, right.second);
    return {include, exclude};
}
int getMaxSum(TreeNode* root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
    
}