#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        // Constructor logic here if needed
    }
    
    void push(int x) {
        // Placeholder for push logic
        s1.push(x);
    }

    int pop() {
        if(s2.empty()){
            if(s1.empty())return -1;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();s2.pop();
        return val;
    }

    int peek() {
        if(s2.empty()){
            if(s1.empty())return -1;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};