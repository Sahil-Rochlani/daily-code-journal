#include<bits/stdc++.h>
using namespace std;

//approach 1

class BrowserHistory {
public:
    string homepag;
    vector<string> history;
    vector<string> backhistory;
    BrowserHistory(string homepage) {
        // Initialize with homepage logic
        homepag = homepage;
        history.push_back(homepage);
    }
    
    void visit(string url) {
        // Visit URL logic
        history.push_back(url);
        backhistory.clear();
    }
    
    string back(int steps) {
        while(history.back() != homepag && steps > 0){
            backhistory.push_back(history.back());
            history.pop_back();
            steps--;
        }
        return history.back();
    }
    
    string forward(int steps) {
        while(!backhistory.empty() && steps > 0){
            history.push_back(backhistory.back());
            backhistory.pop_back();
            steps--;
        }
        return history.back();
    }
};

//approach 2

class BrowserHistory {
public:
    vector<string> history;
    string homepag;
    int currindex;
    int totalindex;
    BrowserHistory(string homepage) {
        // Initialize with homepage logic
        homepag = homepage;
        history.push_back(homepage);
        currindex = 0;
        totalindex = 0;
    }
    
    void visit(string url) {
        // Visit URL logic
        if(currindex == history.size() - 1){
            history.push_back(url);
        }
        else{
            history[currindex + 1] = url;
        }
        currindex++;
        totalindex = currindex;
    }
    
    string back(int steps) {
        currindex = currindex - steps >= 0 ? currindex - steps : 0;
        return history[currindex];
    }
    
    string forward(int steps) {
        currindex = currindex + steps <= totalindex ? currindex + steps : totalindex;
        return history[currindex];
    }
};