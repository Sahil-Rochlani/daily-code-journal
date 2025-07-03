#include<bits/stdc++.h>
using namespace std;

//approach 1: brute force

int trap(vector<int>& heights) {
    int sum = 0;
    for(int i = 0;i < heights.size();i++){
        int j = i;
        int lmax = 0, rmax = 0;
        while(j >= 0){
            lmax = max(lmax, heights[j--]);
        }
        j = i;
        while(j < heights.size()){
            rmax = max(rmax, heights[j++]);
        }
        sum += min(lmax, rmax) - heights[i];
    }
    return sum;
}

//approach 2: precompute rmax and lmax and compare

int trap(vector<int>& heights) {
    int sum = 0, lmax = heights[0];
    int n = heights.size();
    vector<int> rmax(n, 0);
    rmax[n - 1] = max(rmax[n - 1], heights[n - 1]);
    for(int i = n - 2;i >= 0;i--){
        rmax[i] = max(rmax[i + 1], heights[i]);
    }
    for(int i = 1;i < n - 1;i++){
        lmax = max(lmax, heights[i]);
        sum += min(lmax, rmax[i]) - heights[i];
    }
    return sum;
}

//approach 3: two pointers

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1, lmax = 0, rmax = 0, sum = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= lmax)lmax = height[left];
            else sum += lmax - height[left];
            left++;
        }
        else{
            if(height[right] >= rmax)rmax = height[right];
            else sum += rmax - height[right];
            right--;
        }
    }
    return sum;
}