#include<bits/stdc++.h>
using namespace std;
void printMiddleElement(stack<int> &st, int count, int size){
  if(count == size / 2){
    cout << st.top();
    return;
  }
  int val = st.top();
  st.pop();
  count++;
  printMiddleElement(st, count, size);
}