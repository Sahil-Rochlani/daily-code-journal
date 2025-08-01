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

TreeNode* solve(vector<int> &preorder, int n, int &i){
    if(n < 1)return nullptr;
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    root->left = solve(preorder, n / 2, i);
    root->right = solve(preorder, n - n / 2 - 1, i);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return solve(preorder, preorder.size(), i);
}