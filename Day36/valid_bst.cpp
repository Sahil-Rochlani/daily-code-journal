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

//approach 1: bottom up
 class Info{
    public:
    long long maxi;
    long long mini;
    bool isBST;

    Info(long long maxv, long long minv, bool isBSTv) : maxi(maxv), mini(minv), isBST(isBSTv) {}
    Info() : maxi(LLONG_MIN), mini(LLONG_MAX), isBST(false) {}
 };

Info solve(TreeNode* root){
    if(!root)return Info(LLONG_MIN, LLONG_MAX, true);
    
    Info left = solve(root->left);
    Info right = solve(root->right);
    Info current;
    current.maxi = max(root->val * 1ll, max(left.maxi, right.maxi));
    current.mini = min(root->val * 1ll, min(left.mini, right.mini));
    current.isBST = left.isBST && right.isBST && (root->val * 1ll > left.maxi) && (root->val * 1ll < right.mini);
    return current;
}
bool isValidBST(TreeNode* root) {
    Info ans = solve(root);
    return ans.isBST;
}


//approach 2: top down using bounds

bool solve(TreeNode* root, long long leftMax, long long rightMin){
    if(!root)return true;
    if(root->val * 1ll >= rightMin || root->val * 1ll <= leftMax)return false;
    return solve(root->left, leftMax, 1ll * root->val) && solve(root->right, 1ll * root->val, rightMin);
}
bool isValidBST(TreeNode* root) {
    return solve(root,LLONG_MIN, LLONG_MAX);
}

//appoach 3: inorder traversal by using the property that inorder is sorted

bool solve(TreeNode* root, long long &prev){
    if(!root)return true;
    if(!solve(root->left, prev))return false;
    if(root->val <= prev)return false;
    prev = root->val * 1ll;
    return solve(root->right, prev);
}
bool isValidBST(TreeNode* root) {
    long long prev = LLONG_MIN;
    return solve(root,prev);
}