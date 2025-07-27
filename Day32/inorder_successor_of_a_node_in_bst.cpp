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

TreeNode* solve(TreeNode* root, TreeNode* target, int &i, int &k){
    if(!root)return nullptr;
    TreeNode* left = solve(root->left, target, i, k);
    if(left)return left;
    i++;
    if(k == -1 && root == target)k = i;
    else if(k != -1 && i == k + 1)return root;
    return solve(root->right, target, i, k);
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* target) {
    int i = 0, k = -1;
    return solve(root, target, i, k);

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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* target) {
    if(!root)return nullptr;
    TreeNode* successor = nullptr;
    while(root){
        if(root->val > target->val){
            successor = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return successor;
}
