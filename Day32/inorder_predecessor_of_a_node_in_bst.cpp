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

//approach 1 traversing inorder the whole tree

int solve(TreeNode* root, TreeNode* target, int &prev){
    if(!root)return -1;
    int left = solve(root->left, target, prev);
    if(left != -1)return left;
    if(root == target)return prev;
    prev = root->val;
    return solve(root->right, target, prev);
}
int inorderPredecessor(TreeNode* root, TreeNode* target) {
    int prev = -1;
    return solve(root, target, prev);
}

//approch 2 : recursive search using sspecific ordering property

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* target) {
    if(!root)return nullptr;
    if(root == target){
        TreeNode* right = root->right;
        while(right && right->left)right = right->left;
        return right;
    }
    else if(root->val > target->val){
        TreeNode* left = inorderSuccessor(root->left, target);
        return left ? left : root;
    }
    else{
        return inorderSuccessor(root->right, target);
    }
    return root;
    
}

//approach 3: iterative searching(optimal for space complexity)

int inorderPredecessor(TreeNode* root, TreeNode* target) {
        if(!root)return -1;
        int predecessor = -1;
        while(root){
            if(root->val < target->val){
                predecessor = root->val;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return predecessor;
    }
