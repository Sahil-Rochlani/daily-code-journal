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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)return root;
        int mini = min(p->val, q->val), maxi = max(p->val, q->val);
        if(root->val > maxi)return lowestCommonAncestor(root->left, p, q);
        else if(root->val < mini)return lowestCommonAncestor(root->right, p, q);
        else return root;
    }