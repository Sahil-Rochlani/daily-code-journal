#include<bits/stdc++.h>
using namespace std;

int pick = 6;

int guess(int num){
    if(num == pick)return 0;
    if(num > pick)return -1;
    else return 0;
}

int guessNumber(int n) {
    int s = 1, e = n;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(guess(mid) == 0)return mid;
        if(guess(mid) == -1)e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}