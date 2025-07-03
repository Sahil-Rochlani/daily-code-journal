#include<bits/stdc++.h>
using namespace std;

int sumOfMinAndMax(vector<int>& arr, int k) {
    deque<int> max;
    deque<int> min;
    int sum = 0;
    for(int i = 0;i < arr.size();i++){
        while(!max.empty() && (i - max.front() >= k))max.pop_front();
        while(!min.empty() && (i - min.front() >= k))min.pop_front();
        while(!max.empty() && arr[i] >= arr[max.back()])max.pop_back();
        while(!min.empty() && arr[i] <= arr[min.back()])min.pop_back();
        max.push_back(i);
        min.push_back(i);
        if(i >= k - 1){
            sum += arr[max.front()] + arr[min.front()];
        }
    }
    return sum;
}