#include <bits/stdc++.h>
using namespace std;



class Graph{
  public: 
    //adjacency list
    unordered_map<int, vector<int>> adjList;
    
    void addEdge(int u, int v, bool direction){
      //direction = 1=> directed edge else undirected
      if(direction == 1){
        adjList[u].push_back(v);
      }
      else{
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }
    }
    
    void printAdjList(int n){
      for(int i = 0;i < n;i++){
        //i-> [int, edgeList]
        cout << i << ": ";
        cout << "{ ";
        for(auto j : adjList[i]){
          cout << j << " ";
        }
        cout << "} ";
        cout << endl;
      }
    }
    void bfs(int src){
      queue<int>q;
      unordered_map<int, bool>visited;
      q.push(src);
      visited[src] = true;
      while(!q.empty()){
        int front = q.front();q.pop();
        cout << front << " ";
        for(auto neighbour: adjList[front]){
            if(!visited[neighbour]){
              q.push(neighbour);
              visited[neighbour] = true;
            }
        }
      }
    }
    void dfshelper(int src, unordered_map<int, bool> &visited){
      cout << src << " ";
      visited[src] = true;
      for(auto neighbour : adjList[src]){
        if(!visited[neighbour]){
          dfshelper(neighbour, visited);
        }
      }
    }
    void dfs(int src, int n){
      unordered_map<int, bool>visited;
      //function call for src
      for(int src = 0;src < n;src++){
        if(!visited[src]){
          dfshelper(src, visited);
        }
      }
    }
    
    
};

// class Graph{
//     public:
//     unordered_map<int, vector<pair<int, int>>> adjList;
    
//     void addEdge(int u, int v, int wt, bool direction){
//       if(direction == 1){
//         adjList[u].push_back({v, wt});
//       }
//       else{
//         adjList[u].push_back({v, wt});
//         adjList[v].push_back({u, wt});
//       }
//     }
    
//     void printAdjList(){
//       for(auto i : adjList){
//         cout << i.first << ": {";
//         for(auto j : i.second){
//           cout << "( " << j.first << ", " << j.second << " ) ";
//         }
//         cout << "}" << endl;
//       }
//     }
// };

int main() 
{
    Graph g;
    g.addEdge(0, 1, true);
    g.addEdge(0, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(2, 8, true);
    g.addEdge(3, 4, true);
    g.addEdge(8, 4, true);
    g.addEdge(4, 5, true);
    g.addEdge(4, 7, true);
    g.addEdge(5, 6, true);
    g.addEdge(7, 6, true);
    // g.printAdjList();
    g.bfs(0);
    cout << endl;
    g.dfs(0, 9);
}