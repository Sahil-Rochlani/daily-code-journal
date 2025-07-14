#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftBoundary(Node* root, vector<int> &ans){
    //if NULL or leavf return NULL;
    if(!root)return;
    if(!root->left && !root->right)return;
    
    //else store kar lo
    ans.push_back(root->data);
    
    //jab tak left jaa sake ho left mein jaao
    //since question prefers going left if it exists for left boundary
    if(root->left)leftBoundary(root->left, ans);
    else{
        //warna right jaao
        leftBoundary(root->right, ans);
    }
}
void leafBoundary(Node* root, vector<int> &ans){
    if(!root)return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    
    //baaki recursion dekh lega
    leafBoundary(root->left, ans);
    leafBoundary(root->right, ans);
}
void rightBoundary(Node* root, vector<int> &ans){
    //if NULL or leavf return NULL;
    if(!root)return;
    
    if(!root->left && !root->right)return;
    //jab tak right jaa sake ho left mein jaao
    //since question prefers going right if it exists for right boundary
    if(root->right)rightBoundary(root->right, ans);
    else rightBoundary(root->left, ans);
    
    //for reverse order push back at the end
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root) {
    // code here
    vector<int> ans;
    
    //root node
    if(root == NULL)return {};
    else ans.push_back(root->data);
    //left boundary
    leftBoundary(root->left, ans);
    
    //left st leaves
    leafBoundary(root->left, ans);
    
    //right st leaves
    leafBoundary(root->right, ans);
    
    //right boundary in reverse
    rightBoundary(root->right, ans);
    
    return ans;
}