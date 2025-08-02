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

//approach 1: brute force
void inorder(TreeNode* root, vector<int> &ans){
    if(!root)return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
    vector<int> merge(TreeNode *root1, TreeNode *root2){
    vector<int> ans1, ans2;
    inorder(root1, ans1);
    inorder(root2, ans2);
    vector<int> ans;
    int i = 0, j = 0;
    while(i < ans1.size() && j < ans2.size()){
        if(ans1[i] < ans2[j]){
            if(ans.empty() || ans1[i] != ans.back())ans.push_back(ans1[i]);
            i++;
        }
        else {
            if(ans.empty() || ans2[j] != ans.back())ans.push_back(ans2[j]);
            j++;
        }
    }
    while(i < ans1.size()){
        if(ans.empty() || ans1[i] != ans.back())ans.push_back(ans1[i]);
        i++;
    }
    while(j < ans2.size()){
        if(ans.empty() || ans2[j] != ans.back())ans.push_back(ans2[j]);
        j++;
    }
    return ans;

}

//approach 2: simultanous traversing using stack

vector<int> merge(TreeNode *root1, TreeNode *root2){
    stack<TreeNode*> st1, st2;
    TreeNode* r1 = root1;
    TreeNode* r2 = root2;
    vector<int> ans;
    while(r1 || !st1.empty() || r2 || !st2.empty()){
        while(r1){
            st1.push(r1);
            r1 = r1->left;
        }
        while(r2){
            st2.push(r2);
            r2 = r2->left;
        }
        if(st2.empty() || (!st1.empty() && st1.top()->val <= st2.top()->val)){
            auto top = st1.top();
            ans.push_back(top->val);
            r1 = top->right;
            st1.pop();
        }
        else{
                auto top = st2.top();
                ans.push_back(top->val);
                r2 = top->right;
                st2.pop();
            
        }
    }
    return ans;
}