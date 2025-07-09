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

Node* buildTree(){
    int val;
    cin >> val;

    if(val == -1)return NULL;
    else {
        Node* tree = new Node(val);
        tree->left = buildTree();
        tree->right = buildTree();
        return tree;
    }
}

void preorderTraversal(Node* root){
    if(!root)return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
    if(!root)return;
    preorderTraversal(root->left);
    cout << root->data << " ";
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(!root)return;

    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    if(!root)return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();q.pop();

        if(front->left)q.push(front->left);
        if(front->right)q.push(front->right);
    }
}

void levelOrderTraversallevelPrinting(Node* root){
    if(!root)return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();q.pop();

        if(!front){
            cout << endl;
            if(!q.empty())q.push(NULL);
        }
        else{
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
    }
}