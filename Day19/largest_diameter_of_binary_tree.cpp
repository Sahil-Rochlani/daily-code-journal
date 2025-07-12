#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

//approach 1: O(N ^ 2)
int maxDepth(Node* root){
    if(!root)return NULL;
    return 1 + max(maxDepth(root->left), maxDepth((root->right)));
}

int largestDiameterOfBinaryTree(Node* root){
    if(!root)return NULL;

    //option 1: lst + root + rst
    int o1 = maxDepth(root->left) + maxDepth(root->right);

    //option 2: largest diameter exosts in lst
    int o2 = largestDiameterOfBinaryTree(root->left);

    //option 2: largest diameter exosts in rst
    int o3 = largestDiameterOfBinaryTree(root->right);

    return max(o1, max(o2, o3));
}

//approach 2: optimized O(n)

int maxDepth(Node* root, int &ans) {
    if(!root)return 0;
    int left = maxDepth(root->left, ans);
    int right = maxDepth(root->right, ans);
    ans = max(ans, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(Node* root) {
    int ans = -1;
    maxDepth(root, ans);
    return ans;
}
