#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxHeap.size() == minHeap.size()){
            double median = findMedian();
            if(num < median){
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
        }
        else if(maxHeap.size() == minHeap.size() + 1){
            double median = findMedian();
            if(num < median){
                //if we insert here size diff between two would be 2 so will shift top from
                //max to min heap then insert num
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
        }
        else if(maxHeap.size() + 1 == minHeap.size()){
            double median = findMedian();
            if(num > median){
                //if we push to minHeap the size diff would be greater than 1
                //so we shift min heap's top to max heap and then insert the number to 
                //min heap
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == 0 && minHeap.size() == 0)return 0.0;
        else if(maxHeap.size() > minHeap.size())return (double)maxHeap.top();
        else if(maxHeap.size() < minHeap.size())return (double)minHeap.top();
        else return (double)(maxHeap.top() + minHeap.top()) / 2;
    }
};