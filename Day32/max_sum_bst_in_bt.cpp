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

class Info{
    public:
        int maxVal;
        int minVal;
        bool isBST;
        int sum;

        Info() : maxVal(INT_MIN), minVal(INT_MAX), isBST(false), sum(0) {}
        Info(int maxVal,int minVal, bool isBST, int sum) : maxVal(maxVal), minVal(minVal), isBST(isBST), sum(sum) {}
};

Info solve(TreeNode* root, int &sum){
    if(!root)return Info(INT_MIN, INT_MAX, true, 0);

    Info left = solve(root->left, sum);
    Info right = solve(root->right, sum);
    Info current;
    current.maxVal = max(root->val, max(left.maxVal, right.maxVal));
    current.minVal = min(root->val, min(left.minVal, right.minVal));

    if(left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal){
        current.isBST = true;
    }
    else current.isBST = false;
    current.sum = current.isBST ? root->val + left.sum + right.sum : max(left.sum, right.sum);
    sum = max(sum, current.sum);
    return current;
}
int maxSumBST(TreeNode* root) {
    int sum = 0;
    solve(root, sum);
    return sum;
    
}