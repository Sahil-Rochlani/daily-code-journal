#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q){
  stack<int> st;
  while(!q.empty()){
    st.push(q.front());
    q.pop();
  }
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
}

void reverse(queue<int> &q){
  if(q.empty())return;
  int val = q.front();
  q.pop();
  reverse(q);
  q.push(val);
}