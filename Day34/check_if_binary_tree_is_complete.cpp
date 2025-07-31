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

//approach 1: DFS(index checking method)
int totalNodes(TreeNode* root){
    if(!root)return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}
bool isComplete(TreeNode* root, int i, int total){
    if(!root)return true;
    if(i > total)return false;
    return isComplete(root->left, 2 * i, total) && isComplete(root->right, 2 * i + 1, total);
}
bool isCompleteTree(TreeNode* root) {
    int total = totalNodes(root);
    return isComplete(root, 1, total);
}

//approach 2 : BFG gap method

bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool isGap = false;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            TreeNode* front = q.front();q.pop();
            if(!front){
                isGap = true;
                continue;
            }
            if(isGap)return false;
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}