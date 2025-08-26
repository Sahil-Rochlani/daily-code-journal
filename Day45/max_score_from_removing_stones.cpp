#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans = 0;
        while(pq.size() > 1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            a--;b--;ans++;
            if(a)pq.push(a);
            if(b)pq.push(b);
        }
        return ans;
    }