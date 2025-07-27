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

int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root, 1});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            ans = max(ans, (int)(right - left + 1));
            for(int i = 0;i < size;i++){
                TreeNode* front = q.front().first;unsigned long long  curr = q.front().second;q.pop();
                if(front->left)q.push({front->left, curr * 2});
                if(front->right)q.push({front->right, curr * 2 + 1});
            }
        }
        return ans;
    }