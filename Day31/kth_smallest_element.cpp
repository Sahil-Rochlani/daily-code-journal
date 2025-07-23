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
//approach 1 : store inodred and return the k-1th element
void inorder(TreeNode* root, vector<int> &ans){
        if(!root)return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return ans[k - 1];
    }

//approach 2: travel inodred and maintain a variable to keep track of position like k
int kthSmallest(TreeNode* root, int &k) {
        if(!root)return -1;
        int left = kthSmallest(root->left, k);
        k--;
        if(k == 0)return root->val;
        int right = kthSmallest(root->right, k);
        if(left == -1)return right;
        else return left;
    }

//approach 3: slightly beaturiful code
void inorder(TreeNode* root, int k, int &count, int&ans){
        if(!root)return;
        inorder(root->left, k, count, ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        inorder(root->right, k, count, ans);
    }
    int kthSmallest(TreeNode* root, int &k) {
        int ans = -1, count = 0;
        inorder(root, k, count, ans);
        return ans;
    }