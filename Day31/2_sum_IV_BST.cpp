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
void inorder(TreeNode* root, vector<int> &ans){
    if(!root)return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);

}
bool findTarget(TreeNode* root, int k){
    vector<int>ans;
    inorder(root, ans);
    int s = 0, e = ans.size() - 1;
    while(s < e){
        int sum = ans[s] + ans[e];
        if(sum == k)return true;
        if(sum < k)s++;
        else e--;
    }
    return false;
}

//approach : using hashset
bool inorder(TreeNode* root, int k, unordered_set<int> &s){
        if(!root)return false;
        if(s.find(k - root->val) != s.end())return true;
        s.insert(root->val);
        return inorder(root->left, k, s) || inorder(root->right, k, s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        return inorder(root, k, s);
    }