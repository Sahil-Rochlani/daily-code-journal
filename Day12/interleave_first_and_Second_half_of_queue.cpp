#include<bits/stdc++.h>
using namespace std;

queue<int> rearrangeQueue(queue<int> q) {
    queue<int> q1;
    int size = q.size(), count = 0;
    while(count != size / 2){
        q1.push(q.front());
        q.pop();
        count++;
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
    
}