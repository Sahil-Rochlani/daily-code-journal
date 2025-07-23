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
void populate(TreeNode* root, vector<int> &ans, int &i){
    if(!root)return;
    populate(root->left, ans, i);
    root->val = ans[i++];
    populate(root->right, ans, i);
}
TreeNode* convertBST(TreeNode* root){
    vector<int> ans;
    inorder(root, ans);
    for(int i = ans.size() - 2;i >= 0;i++){
        ans[i] += ans[i - 1];
    }
    int i = 0;
    populate(root, ans, i);
    return root;
}