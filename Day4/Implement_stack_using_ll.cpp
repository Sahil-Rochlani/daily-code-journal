#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    int data;
    Node* next;
    
    Node(int val){
      this->data = val;
      this->next = nullptr;
    }
};
class Stack{
  public:
    Node* head;
    Node* tail;
    
    Stack(){
      head = nullptr;
      tail = nullptr;
    }
    void push(int val){
      Node* newNode = new Node(val);
      if(head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
      }
      else{
        tail->next = newNode;
        tail = newNode;
      }
    }
    void pop(){
      if(!head && !tail){
        cout << "Stack Underflow" << endl;
        return;
      }
      else{
        if(head == tail){
          Node* temp = head;
          head = nullptr;
          tail = nullptr;
          delete temp;
          return;
        }
        else{
          Node* temp = head;
          while(temp->next && temp->next->next){
            temp = temp->next;
          }
          Node* temp2 = temp->next;
          temp->next = nullptr;
          delete temp2;
          tail = temp;
          return;
        }
      }
    }
    int size(){
      int l = 0;
      Node* temp = head;
      while(temp){
        l++;
        temp = temp->next;
      }
      return l;
    }
    bool empty(){
      return !head && !tail;
    }
    int top(){
      if(!head && !tail){
        return INT_MIN;
      }
      else{
        return tail->data;
      }
    }
    void printrec(Node* head){
      if(!head->next){
        cout << head->data << " ";
        return;
      }
      printrec(head->next);
      cout << head->data << " ";
    }
    void print(){
      printrec(head);
      cout << endl;
    }
    
};