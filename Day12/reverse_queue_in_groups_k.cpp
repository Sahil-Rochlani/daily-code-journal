#include<bits/stdc++.h>
using namespace std;

//unusedelement initislized to q.size()
void reverseinkgroup(queue<int> &q, int k, int unusedElementCount){
  //ek case main solve karunga
  if(unusedElementCount >= k){
    //i have k element to use
    stack<int> st;
    int count = 0;
    while(count < k){
      st.push(q.front());
      q.pop();
      count++;
      
    }
    while(!st.empty()){
      q.push(st.top());
      st.pop();
    }
    //baaski recursion sambhal lega
    reverseinkgroup(q, k, unusedElementCount - k);
  }
  else{
    //i dont have a k group to reverse
    while(unusedElementCount > 0){
      q.push(q.front());
      q.pop();
      unusedElementCount--;
    }
    return;
  }
}