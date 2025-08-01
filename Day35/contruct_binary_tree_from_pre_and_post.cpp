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

TreeNode* build(vector<int> &preorder, unordered_map<int, int> &m, int &preidx, int postart, int poend){
        if(preidx >= preorder.size() || postart > poend)return NULL;
        TreeNode* root = new TreeNode(preorder[preidx]);
        preidx++;

        if(preidx < preorder.size() && postart < poend){
            int poindex = m[preorder[preidx]];
            root->left = build(preorder, m, preidx, postart, poindex);
            root->right = build(preorder, m, preidx, poindex + 1, poend - 1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int>m;
        for(int i  = 0; i < postorder.size();i++){
            m[postorder[i]] = i;
        }
        int preidx = 0;
        return build(preorder, m, preidx, 0, postorder.size() - 1);
    }