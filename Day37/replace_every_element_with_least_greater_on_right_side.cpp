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

//recursive manual bst insertion and deletion
TreeNode* insertAndSearch(TreeNode* root, int val, int &ans, bool &elementFound){
    if(!root){
        //insert the element if its not found otherwise return as weve 
        //already gotten the successor above
        return elementFound ? NULL : new TreeNode(val);
    }
    if(root->val == val){
        //set bool to true and search right for a smaller successor
        elementFound = true;
        root->right = insertAndSearch(root->right, val, ans, elementFound);
    }
    else if(root->val > val){
        //root is a potential successor so we store it and move left
        //to find a smaller successor
        ans = root->val;
        root->left = insertAndSearch(root->left, val, ans, elementFound);
    }
    else{
        //we move right to find the successor
        root->right = insertAndSearch(root->right, val, ans, elementFound);
    }
    return root;
}

//iterative
TreeNode* insertAndSearch(TreeNode* root, int val, int &ans){
    if(!root){
        //insert the element if its not found otherwise return as weve 
        //already gotten the successor above
        return new TreeNode(val);
    }
    TreeNode* curr = root;
    bool isFound = false;
    while(curr){
        if(curr->val == val){
            isFound = true;
            curr = curr->right;
        }
        else if(curr->val > val){
            ans = curr->val;
            if(!curr->left && !isFound){
                curr->left = new TreeNode(val);
                break;
            }
            curr = curr->left;
        }
        else{
            if(!curr->right && !isFound){
                curr->right = new TreeNode(val);
                break;
            }
            curr = curr->right;
        }
    }
    return root;
}

vector<int> findLeastGreater(vector<int>& arr, int n) {
    TreeNode* root = NULL;
    vector<int> ans(n, -1);
    for(int i = n - 1; i >= 0;i--){
        int successor = -1;
        bool found = false;
        root = insertAndSearch(root, arr[i], successor, found);
        if(successor != -1)ans[i] = successor;
    }
    return ans;
}

//USING SETS
vector<int> findLeastGreater(vector<int>& arr, int n) {
    set<int> bst;
    vector<int> ans(n, -1);
    for(int i = n - 1; i >= 0;i--){
        auto it = bst.upper_bound(arr[i]);
        if(it != bst.end())ans[i] = *it;
        bst.insert(arr[i]);
    }
    return ans;
}