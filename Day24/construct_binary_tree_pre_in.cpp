#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getIndex(int el, vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == el)return i;
    }
    return -1;
}
TreeNode* build(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int inorderStart, int inorderEnd){
    if(preorderIndex >= preorder.size())return nullptr;
    if(inorderStart > inorderEnd)return nullptr;

    int element = preorder[preorderIndex];
    preorderIndex++;
    TreeNode* root = new TreeNode(element);
    int InordereleIndex = getIndex(element, inorder);

    root->left = build(preorder, inorder, preorderIndex, inorderStart, InordereleIndex - 1);
    root->right = build(preorder, inorder, preorderIndex, InordereleIndex + 1, inorderEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // Function to construct the tree from preorder and inorder traversals
    int preorderIndex = 0, inorderStart = 0, inorderEnd = inorder.size() - 1;
    TreeNode* root = build(preorder, inorder, preorderIndex, inorderStart, inorderEnd);
    return root;
}