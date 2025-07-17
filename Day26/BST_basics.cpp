#include <bits/stdc++.h>
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

Node* buildBST(Node* root, int val){
  if(!root){
    root =  new Node(val);
    return root;
  }
  else{
    if(val > root->data){
      root->right = buildBST(root->right, val);
    }
    else{
      root->left = buildBST(root->left, val);
    }
    return root;
  }
}
int getMax(Node* root){
  if(!root)return -1;
  while(root->right)root = root->right;
  return root->data;
}
int getMin(Node* root){
  if(!root)return -1;
  while(root->left)root = root->left;
  return root->data;
}
Node* deleteNode(Node* root, int target){
  if(!root)return root;
  if(root->data == target){
    //no child
    if(!root->left && !root->right){
      Node* temp = root;
      delete temp;
      return NULL;
    }
    if(root->left && !root->right){
      Node* child = root->left;
      Node* temp = root;
      temp->left = NULL;
      delete temp;
      return child;
    }
    if(!root->left && root->right){
      Node* child = root->right;
      Node* temp = root;
      temp->left = NULL;
      delete temp;
      return child;
    }
    if(root->left && root->right){
      //two choices
      //1) find max in left sub tree and replace curr val with max and delete max
      int maxi = getMax(root->left);
      root->data = maxi;
      root->left = deleteNode(root->left, maxi);
      //2) find min in right sub tree and replace curr val with min and delete min
      // int mini = getMin(root->right);
      // root->val = mini;
      // root->right = deleteNode(root->right, max);
      return root;
    }
    //or you find and delete in the same loop
    if(root->left && root->right){
      //two choices
      //1) find max in left sub tree and replace curr val with max and delete max
      Node* temp1 = root->left;
      while(temp1->right && temp1->right->right)temp1 = temp1->right;
      Node* delNode1 = temp1->right;
      root->data = delNode1->data;
      temp1->right = NULL;
      delete delNode1;
      //2) find min in right sub tree and replace curr val with min and delete min
      // Node* temp2 = root->right;
      // while(temp2->left && temp2->left->left)temp2 = temp2->left;
      // Node* delNode2 = temp2->left;
      // root->val = delNode2->data;
      // temp2->left = NULL;
      // delete delNode2;
      return root;
    }
  }
  else{
    if(target > root->data){
      root->right = deleteNode(root->right, target);
    }
    else{
      root->left = deleteNode(root->left, target);
    }
  }
}

Node* createBST(Node* root){
  int val;
  cin >> val;
  //jab tak 01 nhi aata tab tak value lete jaani hai
  while(val != -1){
    root = buildBST(root, val);
    cin >> val;
  }
  return root;
  
}

void preorder(Node* root){
  if(!root)return;
  
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node* root){
  if(!root)return;
  
  
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void postorder(Node* root){
  if(!root)return;
  
  
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void levelOrder(Node* root){
  if(!root)return;
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    Node* front = q.front(); q.pop();
    if(!front){
      cout << "\n";
      if(!q.empty())q.push(NULL);
    }
    else{
      cout << front->data << " ";
      if(front->left)q.push(front->left);
      if(front->right)q.push(front->right);
      
    }
  }
}
int getMin(Node* root){
  if(!root)return -1;
  //traverse leftwards until we reach NULL
  while(root->left){
    root = root->left;
  }
  return root->data;
}

int getMax(Node* root){
  if(!root)return -1;
  
  while(root->right)root = root->right;
  return root->data;
}

bool search(Node* root, int target){
  if(!root)return false;
  if(root->data == target)return true;
  if(root->data > target)return search(root->left, target);
  else return search(root->right, target);
}

int main() 
{
    Node* root = NULL;
    root = createBST(root);
    
    preorder(root);
    cout << endl;
    
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    
    levelOrder(root);
    cout << endl;
    cout << search(root, 160) << endl;
    
}