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

int countPairs(TreeNode* root1, TreeNode* root2, int x) {
        TreeNode *r1 = root1, *r2 = root2;
        stack<TreeNode*> s1, s2;
        unordered_set<int> s;
        while(r1 || !s1.empty()){
            while(r1){
                s1.push(r1);
                s.insert(r1->val);
                r1 = r1->left;
            }
            auto top = s1.top();
            r1 = top->right;
            s1.pop();
        }
        int count = 0;
        while(r2 || !s2.empty()){
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
            auto top = s2.top();
            if(s.find(x - top->val) != s.end())count++;
            r2 = top->right;
            s2.pop();
        }
        return count;
    }