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

//in both appraches we just also check for the maxHeap property that the parent's val must be >= child's values
//approach 1: DFS(index checking method)
 int totalNodes(TreeNode* root){
    if(!root)return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}
bool solve(TreeNode* root, int i, int total){
    if(!root)return true;
    if(i > total)return false;
    if(root->left && root->left->val > root->val)return false;
    if(root->right && root->right->val > root->val)return false;
    return solve(root->left, 2 * i, total) && solve(root->right, 2 * i + 1, total);
}
bool isHeap(TreeNode* root) {
    int total = totalNodes(root);
    return solve(root, 1, total); 
}

//approach 2 : BFG gap method

bool isHeap(TreeNode* root) {
    if(!root)return true;
    queue<TreeNode* >q;
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
            if(front->left && front->left->val > front->val)return false;
            q.push(front->left);
            if(front->right && front->right->val > front->val)return false;
            q.push(front->right);

        }
    }
    return true;
}