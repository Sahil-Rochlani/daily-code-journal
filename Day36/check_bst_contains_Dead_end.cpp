#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

//approach 1:
void inorder(Node* root, vector<pair<int, bool>> &vec){
        if(!root)return;
        inorder(root->left, vec);
        bool check = !root->left && !root->right;
        vec.push_back({root->data, check});
        inorder(root->right, vec);
    }
bool isDeadEnd(Node *root) {
    // Code here
    vector<pair<int, bool>> v;
    inorder(root, v);
    if(v[0].first == 1 && v[0].second && v[1].first == 2)return true;
    for(int i = 1;i < v.size() - 1;i++){
        if((v[i + 1].first - v[i].first == 1) && (v[i].first - v[i - 1].first == 1) && v[i].second)return true;
    }
    return false;
    
}

//approach 2: using bounds
bool solve(Node* root, int mini, int maxi){
    if(!root)return false;
    if(mini == maxi)return true;
    return solve(root->left, mini, root->data - 1) || solve(root->right, root->data + 1, maxi);
}
bool isDeadEnd(Node* root) {
    return solve(root, 1, INT_MAX);
}