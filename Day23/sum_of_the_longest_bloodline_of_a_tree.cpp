#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; 

void solve(Node* root, int &currmax, int i, int &maxi, int sum){
    if(!root)return;
    if(i == currmax){
        maxi = max(maxi, sum + root->data);
    }
    else if(i > currmax){
        maxi = sum + root->data;
        currmax = i;
    }
    solve(root->left, currmax, i + 1, maxi, sum + root->data);
    solve(root->right, currmax, i + 1, maxi, sum + root->data);
}
int sumOfLongRootToLeafPath(Node *root) {
    // code here
    int maxi = 0, currmax = 0;
    solve(root, currmax, 0, maxi, 0);
    return maxi;
    
}