#include <bits/stdc++.h>
using namespace std;



class Node{
  public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node* buildTree(Node* root, int val){
  if(!root)return new Node(val);
  if(root->val > val)root->left = buildTree(root->left, val);
  else root->right = buildTree(root->right, val);
  return root;
}

Node* createBST(){
  Node* root = NULL;
  int val;
  cin >> val;
  while(val != -1){
    root = buildTree(root, val);
    cin >> val;
  }
  return root;
}

void inorder(Node* root){
  if(!root)return;
  stack<Node*>st;
  while(root || !st.empty()){
    while(root){
      st.push(root);
      cout << root->val << " ";
      root = root->left;
    }
    if(!st.empty()){
      Node* top = st.top();
    
    root = top->right;
    st.pop();
    }
  }
}