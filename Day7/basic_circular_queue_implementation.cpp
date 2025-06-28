#include<bits/stdc++.h>
using namespace std;

class circularQueue{
 public:
  int *arr;
  int front;
  int rear;
  int size;
  
  circularQueue(int capacity){
    arr = new int[capacity];
    front = -1;
    rear = -1;
    size = capacity;
  }
  void push(int val){
    if((rear == size - 1) || (front - rear == 1)){
      cout << "overflow" << endl;
    }
    else if(front == -1 && rear == -1){
      front++;
      rear++;
      arr[rear] = val;
    }
    else if((rear == size - 1) && (front != 0)){
      rear = 0;
      arr[rear] = val;
    }
    else{
      rear;
      arr[rear] = val;
    }
  }
  void pop(){
    if(front == -1 && rear == -1){
      cout << "Underflow" << endl;
    }
    else if(front == rear){
      front = -1;
      rear = -1;
    }
    else if(front == size - 1){
      front = 0;
    }
    else front++;
  }
  int front(){
    if(front == -1){
      cout << "Queue empty" << endl;
      return - 1;
    }
    return arr[front];
  }
  bool checkEmpty(){
    return front == -1 && rear == -1;
  }
  int getSize(){
    if(front == -1 && rear == -1)return -1;
    if(front <= rear)return rear - front + 1;
    else return size - front + rear + 1;
  }
};