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

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL)return NULL;
    if(root == p)return p;
    if(root == q)return q;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if(!left && !right)return NULL;
    else if(left && !right)return left;
    else if(!left && right)return right;
    else return root;
}