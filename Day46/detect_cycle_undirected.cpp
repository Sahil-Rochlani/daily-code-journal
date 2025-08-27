#include<bits/stdc++.h>
using namespace std;

//BFS
bool isCycle(int V, vector<vector<int>>& edge) {
    // Code here
    unordered_map<int, vector<int>> adjList;
    for(int i = 0;i < edge.size();i++){
        adjList[edge[i][0]].push_back(edge[i][1]);
        adjList[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    unordered_map<int, bool>visited;
    unordered_map<int, int> parent;
    for(auto it : adjList){
        int src = it.first;
        if(!visited[src]){
            q.push(src);
            visited[src] = true;
            parent[src] = -1;
            while(!q.empty()){
                int front = q.front();q.pop();
                for(auto j : adjList[front]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                        parent[j] = front;
                    }
                    else{
                        if(parent[front] != j)return true;
                    }
                }
            }
        }
    }
    return false;
}

//DFS
bool dfsHelper(int src, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, unordered_map<int, vector<int>> &adjList){
        visited[src] = true;
        for(auto nbr: adjList[src]){
            if(!visited[nbr]){
                parent[nbr] = src;
                if(dfsHelper(nbr, visited, parent, adjList))return true;
            }
            else{
                if(parent[src] != nbr)return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edge) {
        // Code here
        unordered_map<int, vector<int>> adjList;
        for(int i = 0;i < edge.size();i++){
            adjList[edge[i][0]].push_back(edge[i][1]);
            adjList[edge[i][1]].push_back(edge[i][0]);
        }
        unordered_map<int, bool>visited;
        unordered_map<int, int> parent;
        for(auto it : adjList){
            int src = it.first;
            if(!visited[src]){
                parent[src] = -1;
                if(dfsHelper(src, visited, parent, adjList))return true;
            }
        }
        return false;
    }