#include<bits/stdc++.h>
using namespace std;

class Deque{
  public:
    int *arr;
    int front;
    int rear;
    int size;
    
    Deque(int capacity){
      arr = new int[capacity];
      size = capacity;
      front = -1;
      rear = -1;
    }
    
    void push_front(int val){
      if(front == -1)cout << "Overflow" << endl;
      else if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[front] = val;
      }
      else{
        front--;
        arr[front] = val;
      }
    }
    void push_back(int val){
      if(rear == size -  1)cout << "Overflow" << endl;
      else if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[rear] = val;
      }
      else{
        rear++;
        arr[rear] = val;
      }
    }
    void pop_front(){
      if(front == -1 && rear == -1){
        cout << "Underflow" << endl;
      }
      else if(front == rear){
        front = -1;
        rear = -1;
      }
      else{
        front++;
      }
    }
    void pop_back(){
      if(front == -1 && rear == -1){
        cout << "Underflow" << endl;
      }
      else if(front == rear){
        front = -1;
        rear= -1;
      }
      else{
        rear--;
      }
    }
};