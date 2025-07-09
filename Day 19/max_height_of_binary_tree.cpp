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