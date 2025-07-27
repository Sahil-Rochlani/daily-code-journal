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

int leftHeight(TreeNode* root){
        if(!root)return 0;
        TreeNode* curr = root;
        int count = 0;
        while(curr){
            curr = curr->left;
            count++;
        }
        return count;
    }
    int rightHeight(TreeNode* root){
        if(!root)return 0;
        TreeNode* curr = root;
        int count = 0;
        while(curr){
            curr = curr->right;
            count++;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int left = leftHeight(root);
        int right = rightHeight(root);
        if(left == right){
            return pow(2, left) - 1;
        }
        else{
            int leftNodes = countNodes(root->left);
            int rightNodes = countNodes(root->right);
            return leftNodes + rightNodes + 1;

        }
    }