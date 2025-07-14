#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//method 1
TreeNode* solve(TreeNode* root){
    if(!root)return root;
    TreeNode* temp = root;
    TreeNode* tail = root;
    // int val = root->right ? root->right->val : 0;
    // cout << val << " ";
    while(temp != nullptr){
        if(temp->left){
            TreeNode* leftTail = solve(temp->left);
            TreeNode* right = temp->right;
            temp->right = temp->left;
            temp->left = nullptr;
            leftTail->right = right;
        }
        tail = temp;
        temp = temp->right;
    }
    // cout << root->right == nullptr;
    // cout << root->right->val << endl;
    return tail;
}
void flatten(TreeNode* root) {
    // Placeholder for tree flattening logic
    solve(root);
    
}

//method 2:

void flatten(TreeNode* root){
    if(!root)return ;
    flatten(root->left);
    flatten(root->right);

    TreeNode* right = root->right;
    root->right = root->left;
    root->left = NULL;

    TreeNode* curr = root;
    while(curr->right){
        curr = curr->right;
    }
    curr->right = right;
}