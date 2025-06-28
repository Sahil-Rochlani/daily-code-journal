#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;

    Queue(int size) {
        arr = new int[size];
        capacity = size;
        frontIndex = -1;
        rearIndex = -1;
    }

    void push(int val) {
        // overflow
        if (rearIndex == capacity - 1) {
            cout << "Overflow" << endl;
            return;
        }

        // first element
        if (frontIndex == -1 && rearIndex == -1) {
            frontIndex = rearIndex = 0;
        } else {
            rearIndex++;
        }
        arr[rearIndex] = val;
    }

    void pop() {
        // underflow
        if (frontIndex == -1 || frontIndex > rearIndex) {
            cout << "Underflow" << endl;
            return;
        }

        frontIndex++;

        // if queue becomes empty
        if (frontIndex > rearIndex) {
            frontIndex = rearIndex = -1;
        }
    }

    int size() {
        if (frontIndex == -1) return 0;
        return rearIndex - frontIndex + 1;
    }

    bool empty() {
        return frontIndex == -1;
    }

    int front() {
        if (frontIndex == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    int rear() {
        if (rearIndex == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rearIndex];
    }
};
