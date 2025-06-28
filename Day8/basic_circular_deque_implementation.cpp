#include<bits/stdc++.h>
using namespace std;

class circularDeeue{
 public:
  int *arr;
  int f;
  int r;
  int size;
  
  circularDeeue(int capacity){
    arr = new int[capacity];
    f = -1;
    r = -1;
    size = capacity;
  }
  void push_front(int val){
    if(f == 0 || (f - r == 1)){
      cout << "Overflow" << endl;
    }
    else if(f == -1 && r == -1){
      f++;
      r++;
      arr[f] = val;
    }
    else if(f == 0 && r != size - 1){
      f = size - 1;
      arr[f] = val;
    }
    else{
      f--;
      arr[f] = val;
    }
  }
  void push_back(int val){
    if((r == size - 1) || (f - r == 1)){
      cout << "Overflow" << endl;
    }
    else if(f == -1 && r == -1){
      f++;
      r++;
      arr[f] = val;
    }
    else if(r == size - 1 && f != 0){
      r = 0;
      arr[r] = val;
    }
    else{
      r++;
      arr[r] = val;
    }
  }
  void pop_front(){
    if(f == -1 && r == -1){
      cout << "Queue Empty" << endl;
      // return -1;
    }
    else if(f == r){
      f = -1;
      r = -1;
    }
    else if(f == size - 1){
      f = 0;
    }
    else{
      f++;
    }
  }
  void pop_back(){
    if(f == -1 && r == -1){
      cout << "Queue Empty" << endl;
    }
    else if(f == r){
      f = -1;
      r = -1;
    }
    else if(r == 0){
      r = size - 1;
    }
    else{
      r--;
    }
  }
};