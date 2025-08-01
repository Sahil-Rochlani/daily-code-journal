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


//bfs
int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            int left = q.front().second;
            int right = q.back().second;
            ans = max(ans, right - left + 1);
            for(int i = 0;i < size;i++){
                TreeNode* front = q.front().first;
                int  curr = q.front().second;q.pop();
                if(front->left)q.push({front->left, curr * 1ull * 2 - left});
                if(front->right)q.push({front->right, curr * 1ull * 2 + 1 - left});
            }
        }
        return ans;
    }

//approach 2: using dfs

int dfs(TreeNode* root, int level, int order, vector<pair<int, int>> &vec){
        if(!root)return 0;
        if(vec.size() == level)vec.push_back({order, order});
        else vec[level].second = order;
        int minIdx = vec[level].first;
        return max({vec[level].second - vec[level].first + 1, dfs(root->left, level + 1, 2 * 1ull *order - minIdx, vec), dfs(root->right, level + 1, 2 * 1ull * order + 1 - minIdx, vec)});
    }
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root, 0, 1, vector<pair<int, int>>() = {});
    }