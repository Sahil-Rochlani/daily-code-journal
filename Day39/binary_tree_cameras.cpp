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

int dfs(TreeNode* root, int &camera){
    if(!root)return 1;
    int left = dfs(root->left, camera);
    int right = dfs(root->right, camera);
    if(left == 2 || right == 2){
        camera++;
        return 0;
    }
    if(left == 0 || right == 0)return 1;
    return 2;
}
int minCameraCover(TreeNode* root) {
    int cameras = 0;
    if(dfs(root, cameras) == 2)cameras++;
    return cameras;
}