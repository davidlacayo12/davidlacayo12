//Problem #1971 on Leetcode
//Used BFS (queue) and adjacency matrix with a map to accomplish this

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using std::vector;
using std::queue;
using std::unordered_map;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> m;
        for(auto edge : edges) {
            m[edge[0]].push_back(edge[1]);  //creates adjacency "matrix" for graph using unordered map
            m[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,0);  //create vector to keep track of visited nodes
        queue<int> q;
        q.push(source); //push starting point to the queue 
        visited[source] = 1;    //mark the starting point as visited
        while(!q.empty()) { //while the queue is full, and dest not visited, add nodes to visited and push nodes to queue
            int curr = q.front();
            q.pop();
            if(curr == destination) {
                return 1;   //if dest found in adj. list, there is a path from our start to end
            }
            for(auto &node : m[curr]) {
                if(!visited[node]) {
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }
        return 0;   //otherwise, there is no path from source to destination so return false
    }
};