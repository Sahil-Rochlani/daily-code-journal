#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> diagonalTraversal(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        TreeNode* front = q.front();q.pop();
        TreeNode* curr = front;
        while(curr){
            ans.push_back(curr->val);
            if(curr->left)q.push(curr->left);
            curr = curr->right;
        }
    }
    return ans;
}