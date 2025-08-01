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

//approach 1: bottom up postorder traversal and stiching the right and left DLL
//and returning the head and tail of the combined DLL

pair<TreeNode*, TreeNode*> solve(TreeNode* root){
        if(!root)return {NULL,NULL};
        pair<TreeNode*, TreeNode*> left = solve(root->left);
        pair<TreeNode*, TreeNode*> right = solve(root->right);
        
        if(left.second){
            root->left = left.second;
            left.second->right = root;
        }
        if(right.first){
            root->right = right.first;
            right.first->left = root;
        }
        return {left.first ? left.first : root, right.second ? right.second : root};
    }
    TreeNode* bToDLL(TreeNode* root) {
        // code here
        if(!root)return NULL;
        pair<TreeNode*, TreeNode*> ans = solve(root);
        return ans.first;
        
        
        
    }

//approach 2: using sideeffects and in order traversal 