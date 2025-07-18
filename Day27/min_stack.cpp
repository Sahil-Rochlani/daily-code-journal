
#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    int top1;
    int top2;
    int *arr1;
    int *arr2;
    MinStack() {
        top1 = -1;
        top2 = -1;
        arr1 = new int[300001];
        arr2 = new int[300001];
    }
    
    void push(int val) {
        top1++;
        arr1[top1] = val;
        
        if(top2 == -1){
            top2++;
            arr2[top2] = val;
        }
        else{
            top2++;
            arr2[top2] = min(val, arr2[top2 - 1]);
        }
    }
    
    void pop() {
        if(top1 == -1)return;
        top1--;
        top2--;
    }
    
    int top() {
        if(top1 == -1)return -1;
        return arr1[top1];
    }
    
    int getMin() {
        if(top2 == -1)return -1;
        return arr2[top2];
    }
};