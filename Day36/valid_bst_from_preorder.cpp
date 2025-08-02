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


//code type 1
bool solve(vector<int> &preorder, int &i, int mini, int maxi){
    if(i == preorder.size())return true;
    if(preorder[i] <= mini || preorder[i] >= maxi)return false;
    int root = preorder[i];
    i++;
    return solve(preorder, i, mini, root) || solve(preorder, i, root , maxi);
}
bool canRepresentBST(vector<int>& preorder) {
    // User to implement the actual logic here
    int i = 0;
    return solve(preorder, i, INT_MIN, INT_MAX);
}

//code type 2

void buold(vector<int> &pre, int &i, int mini, int maxi){
    if(i == pre.size() || pre[i] <= mini || pre[i] >= maxi)return;
    int root = pre[i++];
    buold(pre,  i, mini, root);
    buold(pre, i, root, maxi);
}
bool canRepresentBST(vector<int>& preorder) {
    // User to implement the actual logic here
    int i = 0;
    buold(preorder, i, INT_MIN, INT_MAX);
    return i == preorder.size();
}