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
TreeNode* build(vector<int> &postorder, vector<int> &inorder, int &postorderIndex, int inorderStart, int inorderEnd){
    if(postorderIndex >= postorder.size())return nullptr;
    if(inorderStart > inorderEnd)return nullptr;

    int element = postorder[postorderIndex];
    postorderIndex--;
    TreeNode* root = new TreeNode(element);
    int InordereleIndex = getIndex(element, inorder);

    root->right = build(postorder, inorder, postorderIndex, InordereleIndex + 1, inorderEnd);
    root->left = build(postorder, inorder, postorderIndex, inorderStart, InordereleIndex - 1);
    
    return root;
}
TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    // Function to construct the tree from postorder and inorder traversals
    int postorderIndex = postorder.size() - 1, inorderStart = 0, inorderEnd = inorder.size() - 1;
    TreeNode* root = build(postorder, inorder, postorderIndex, inorderStart, inorderEnd);
    return root;
}