#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

const int MOD = 1e9 + 7;
    void solve(TreeNode* root, int targetSum, int sum, int &count, unordered_map<int, int> &m){
    if(!root)return;
    sum = (sum + root->val) % MOD;
    if(m.find(sum - targetSum) != m.end())
    count+= m[sum - targetSum];
    m[sum]++;
    
    solve(root->left, targetSum, sum, count, m);
    solve(root->right, targetSum, sum, count, m);
    m[sum]--;
}
int pathSum(TreeNode* root, int targetSum) {
    // Placeholder logic for path sum
    unordered_map<int, int> m;
    m[0]++;
    int count = 0;
    solve(root, targetSum, 0, count, m);
    return count;
}