#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <utility>
#include <limits.h>

using std::map;
using std::vector;
using std::queue;
using std::string;
using std::pair;
using std::cout;
using std::cin;
using std::endl;

class Graph {
    int V; //number of vertices in the graph
    vector<vector<int>> adjMatrix;  //adjacency matrix
    //vector<vector<int>> cost;

    public: 
        Graph(int v);   //constructor
        ~Graph();   //destructor
        void addEdge(int v, int w, int weight); //adds edge to graph
        void setAdjMatrix(vector<vector<int>> & m);
        vector<vector<int>> getAdjMatrix();
        void printAdjencyMatrix();
        
        int findShortestPathBFS(int s, int d); //shortest path from source vertex to destination
        int printBFS(vector<int> & parent, int s, int d);    //prints shortest path from source to destination
        vector<int> dijkstra(int src, int dest);  //dijkstra's method, which calls getMin as a helper
        int getMin(vector<int> distance, vector<bool> visited);
        vector<int> printDijkstra(vector<int> distance, vector<int> parent, int d);

        vector<int> pageRank();
        vector<int> pageRank(int src, int dest);
        vector<vector<double>> stochastic(const vector<vector<int>>& adjMatrix);
};
void scaleMatrix(vector<vector<double>>& matrix, double scalar);
void addMatrices(vector<vector<double>>& matrix, const vector<vector<double>>& addMatrix);
void multiplyMatrices(vector<double>& v, const vector<vector<double>>& multMatrix);
