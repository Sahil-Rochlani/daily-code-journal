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

string solve(TreeNode* root, unordered_map<string, int> &m, vector<TreeNode*> &ans){
    if(!root)return "#";
    string left = solve(root->left, m, ans);
    string right = solve(root->right, m, ans);
    string curr = left + "," + right + "," + to_string(root->val);
    if(m[curr] == 1)ans.push_back(root);
    m[curr]++;
    return curr;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int>m;
    vector<TreeNode*> ans;
    solve(root, m, ans);
    return ans;
}