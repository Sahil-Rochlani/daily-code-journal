#include<bits/stdc++.h>
using namespace std;
bool checkSortedStack(stack<int> &st){
  if(st.empty())return true;
  int val = st.top();
  st.pop();
  if(st.empty()){
    st.push(val);
    return true;
  }
  bool issorted = false;
  if(val < st.top()){
    issorted = false;
  }
  else{
    issorted = checkSortedStack(st);
  }
  st.push(val);
  return issorted;
}