#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};

int getMax(TreeNode* root){
        if(!root)return -1;
        while(root->right)root = root->right;
        return root->val;
    }
    
    // void(TreeNode* root, int key)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        // deleteBST(root, key);
        if(root->val == key){
            //4 cases
            //no child
            if(!root->left && !root->right){
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }
            //only left child
            if(root->left && !root->right){
                TreeNode* temp = root;
                TreeNode* child = root->left;
                temp->left = NULL;
                delete temp;
                return child;
            }
            //only right child
            //both child
            if(!root->left && root->right){
                TreeNode* temp = root;
                TreeNode* child = root->right;
                temp->right = NULL;
                delete temp;
                return child;
            }
            if(root->left && root->right){
                //find the max val in left subtree and replace current value 
                //with it and delete the node in the left subtree with 
                //the max value
                int max = getMax(root->left);
                root->val = max;
                root->left = deleteNode(root->left, max);

                //find the min val in right subtree and replace current value 
                //with it and delete the node in the right subtree with 
                //the min value
                // int min = getMax(root->right);
                // root->val = min;
                // root->right = deleteNode(root->right, max);
                return root;
                
            }
        }
        else{
            if(root->val < key){
                //deletion from right side
                root->right = deleteNode(root->right, key);
            }
            else{
                //deletion from left side
                root->left = deleteNode(root->left, key);

            }
            return root;
        }
        return NULL;
    }