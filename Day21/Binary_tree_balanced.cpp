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
 
//approach1: O(N^2)
int maxDepth(TreeNode* root){
    if(!root)return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
bool isBalanced(TreeNode* root) {
    //if root is null return true as empty tree is balanced
    if(!root)return true;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    if(abs(left - right) > 1)return false;
    else{
        return isBalanced(root->left) && isBalanced(root->right);
    }
}

//approach 2: O(n)

int maxDepth(TreeNode* root){
    if(!root)return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    if(left ==  -1 || right == -1 || abs(left - right) > 1)return -1;
    return 1 + max(left, right);
}
bool isBalanced(TreeNode* root) {
    //if root is null return true as empty tree is balanced
    return maxDepth(root) != -1;
}