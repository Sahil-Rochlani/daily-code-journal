#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

//approcah 1: brute force
Node* recurse(Node* head){
    Node* it = head;
    Node* tail = NULL;
    while(it){
        if(it->child){
            Node* childtail = recurse(it->child);
            Node* temp = it->next;
            it->next = it->child;
            it->next->prev = it;
            it->child = NULL;
            childtail->next = temp;
            if(temp)temp->prev = childtail;
        }
        tail = it;
        it = it->next;
    }
    return tail;
}
Node* flatten(Node* head) {
    recurse(head);
    return head;
}

//approach 2: using stack

Node* flatten(Node* head) {
    if(!head)return NULL;
    stack<Node*>st;
    Node* curr = head;
    while(curr){
        if(curr->child){
            Node* next = curr->next;
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child = NULL;
            if(next)
            st.push(next);
        }
        if(!curr->next && !st.empty()){
            Node* top = st.top(); st.pop();
            curr->next = top;
            top->prev = curr;
        }
        curr = curr->next;
    }
    return head;

}