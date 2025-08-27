#include<bits/stdc++.h>
using namespace std;

bool dfshelper(int src, unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &resStack){
    visited[src] = true;
    resStack[src] = true;
    for(auto nbr : adjList[src]){
        if(!visited[nbr]){
            if(dfshelper(nbr, adjList, visited, resStack))return true;
        }
        else{
            if(resStack[nbr])return true;
        }
    }
    resStack[src] = false;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    // code here
    unordered_map<int, vector<int>> adjList;
    for(auto i : edges){
        adjList[i[0]].push_back(i[1]);
    }
    unordered_map<int, bool>visited;
    unordered_map<int, bool> resStack;
    for(int src = 0;src < V;src++){
        if(!visited[src]){
            if(dfshelper(src, adjList, visited, resStack))return true;
        }
    }
    return false;
}