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


//my approach: by reversing the levelPath at alternate levels
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // Placeholder for zigzag level order traversal
    if(!root)return {};
    int i = 0;
    queue<TreeNode*> q;
    vector<int> levelPath;
    vector<vector<int>> ans;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* front = q.front();q.pop();
        if(!front){
            if(i & 1)reverse(levelPath.begin(), levelPath.end());
            ans.push_back(levelPath);
            levelPath.clear();
            i++;
            if(!q.empty())q.push(nullptr);
        }
        else{
            levelPath.push_back(front->val);
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
    }
    return ans;
}

//approach 2 using a bolean and using queue sized vector
// to efficiently place values at their index either from front
// or back

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // Placeholder for zigzag level order traversal
    if(!root)return {};
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int queueSize = q.size();
        vector<int> path(queueSize);
        for(int i = 0;i < queueSize;i++){
            TreeNode* front = q.front();q.pop();
            int index = leftToRight ? i : queueSize - i - 1;
            path[index] = front->val;
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        ans.push_back(path);
        leftToRight = !leftToRight;
    }
    return ans;
}