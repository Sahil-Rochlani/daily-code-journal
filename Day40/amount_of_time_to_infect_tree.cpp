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

pair<int, int> solve(TreeNode* root, int start){
    if(!root)return {0, -1};
    pair<int, int> left = solve(root->left, start);
    pair<int, int> right = solve(root->right, start);
    if(root->val == start)return {max(left.first, right.first), 0};
    else if(left.second != -1){
        return {max(right.first + left.second + 1, left.first), 1 + left.second};
    }
    else if(right.second != -1){
        return {max(left.first + right.second + 1, right.first), 1 + right.second};
    }
    else{
        return {1 + max(left.first, right.first), -1};
    }
}
int amountOfTime(TreeNode* root, int start) {
    pair<int, int> ans = solve(root, start);
    return ans.first;
}
