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
