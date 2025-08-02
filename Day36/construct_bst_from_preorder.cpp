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

//approach 1: 
TreeNode* build(vector<int> &preorder, int s, int e){
    if(s > e)return NULL;
    TreeNode* root = new TreeNode(preorder[s]);

    if(s == e)return root;
    int mid = s  + 1;
    while(mid <= e &&  preorder[mid] <= preorder[s])mid++;

    
    root->left = build(preorder, s + 1, mid - 1);
    root->right = build(preorder, mid, e);
    
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, 0, preorder.size() - 1);
}

//approach 2: optimized

TreeNode* buildTree(vector<int> &preorder, int &i, int bound){
    if(i >= preorder.size() || preorder[i] > bound)return NULL;
    int rootVal = preorder[i++];
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTree(preorder,  i, rootVal);
    root->right = buildTree(preorder, i, bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return buildTree(preorder, i, INT_MAX);
}