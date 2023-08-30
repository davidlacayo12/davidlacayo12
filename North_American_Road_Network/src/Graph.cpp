#include "Graph.h"

Graph::Graph(int v) {
    this->V = v;
    adjMatrix.resize(v, vector<int>(v));

    for(size_t i = 0; i < adjMatrix.size(); i++) {
        for(size_t j = 0; j < adjMatrix[i].size(); j++) {
            adjMatrix[i][j] = 0;
        }
    }

}

Graph::~Graph() {   
    for(size_t u = 0; u < adjMatrix.size(); u++) {
        for(size_t v = 0; v < adjMatrix[u].size(); v++) {
            adjMatrix[u][v] = 0;
        }
    }
}

void Graph::addEdge(int v, int w, int weight) {
    adjMatrix[v][w] = weight;   //theses can all either be 1, weight, or mix based on implementation.
    adjMatrix[w][v] = weight;
}

void Graph::setAdjMatrix(vector<vector<int>> & m) {
    for(size_t i = 0; i < m.size(); i++) {
        for(size_t j = 0; j < m[i].size(); j++) {
            adjMatrix[i][j] = m[i][j];
        }
    }
}

vector<vector<int>> Graph::getAdjMatrix() {
    return adjMatrix;
}

int Graph::printBFS(vector<int> & parent, int s, int d) {
    static int pos = 0;
    cout<< endl;
    if(parent[s] == -1) {
        cout << "Shortest Path Between " << s << " and " << d << " is " << " ";
        cout << endl;
        return pos;
    }
    printBFS(parent, parent[s], d);
    
    pos++;
    if(s < V) {
        cout << s << " ";
    }
    return pos;
}

int Graph::findShortestPathBFS(int s, int d) {
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> parent(adjMatrix.size(), -1);

    queue<int> q;    //create a queue for BFS, and mark current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int v = q.front();
        if(v == d) {
            return printBFS(parent, v, d);
        }
        q.pop();

        for(size_t it = 0; it < adjMatrix[v].size(); it++) {   //this works for adjacency matrix instead of list
            if(!visited[it] && adjMatrix[v][it] != 0) {
                visited[it] = true;
                q.push(it);
                parent[it] = v;
            }
        }
    }
    return -1;
}

int Graph::getMin(vector<int> distance, vector<bool> visited) {
    int minNode = INT_MAX;
    int minValue = INT_MAX;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

vector<int> Graph::dijkstra(int src, int dest) { 
    vector<int> parent(V);
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);

    distance[src] = 0;
    parent[src] = -1;

    for(int i = 0; i < V-1; i++) {
        int u = getMin(distance, visited);
        if(u == INT_MAX) {
            vector<int> v;
            v.push_back(-1);
            cout << "No solution exists from this starting location to this destination." << endl;
            return v;
        }

        visited[u] = true;
        for(int v = 0; v < V; v++) {
            int currDistance = distance[u] + adjMatrix[u][v];
            if(!visited[v] && adjMatrix[u][v] != 0 && (distance[v] > currDistance)) {
                distance[v] = currDistance;
                parent[v] = u;
            }
        }
        if(u == dest) {break;}
    }

    vector<int> v = printDijkstra(distance, parent, dest);
    return v;
}

vector<int> Graph::printDijkstra(vector<int> distance, vector<int> parent, int d) {
    vector<int> distanceVector;
    int pos = parent[d];
    cout<< d << " <- ";
    while(pos != -1) {
        cout<< pos << " <- ";
        pos = parent[pos];
    }
    cout << endl;
    cout<< "::::Distance = " << distance[d];
    cout<< "\n" << endl;
    distanceVector.push_back(distance[d]);
    cout << "\n" << endl;
    return distanceVector;
}

void Graph::printAdjencyMatrix() {
    for(size_t i = 0; i < adjMatrix.size(); i++) {
        for(size_t j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}

/**
 * PageRank Algorithm
 */

/**
 * PageRank algorithm to measure how busy each city (node) in the graph data set 
 * is by counting the number of roads (edges) to each city and the distance between 
 * each city. The busiest cities have the most roads from other cities.
 *
 * @return A vector containing cities sorted from most busy to least busy.
 */

vector<int> Graph::pageRank() {
    vector<int> pageRank;
    vector<double> ranks(V, (double) 1 / V);
    vector<vector<double>> sMatrix = stochastic(adjMatrix);
    vector<double> row(V, 0.15 / V);
    vector<vector<double>> dampMatrix(V, row);
    scaleMatrix(sMatrix, 0.85);
    addMatrices(sMatrix, dampMatrix);
    for (int i = 0; i < 45; ++i) {
        multiplyMatrices(ranks, sMatrix);
    }
    vector<pair<int, double>> sortVec;
    for (int i = 0; i < V; ++i) {
        sortVec.push_back({i, ranks[i]});
    }
    sort(sortVec.begin(), sortVec.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < V; ++i) {
        pageRank.push_back(sortVec[i].first);
    }
    return pageRank; //cities sorted from highest rank to lowest rank (most busy to least busy)
}

/**
 * PageRank algorithm to measure how busy each city (node) in the graph data set 
 * is by counting the number of roads (edges) to each city and the distance between 
 * each city. The busiest cities have the most roads from other cities.
 *
 * @param src Starting city
 * @param dest End city
 *
 * @return A vector containing cities sorted from most busy to least busy.
 */
vector<int> Graph::pageRank(int src, int dest) {
    vector<int> pageRank;
    vector<double> ranks(V, (double) 1 / V);
    vector<vector<double>> sMatrix = stochastic(adjMatrix);
    vector<double> row(V, 0.15 / V);
    vector<vector<double>> dampMatrix(V, row);
    scaleMatrix(sMatrix, 0.85);
    addMatrices(sMatrix, dampMatrix);
    for (int i = 0; i < 45; ++i) {
        multiplyMatrices(ranks, sMatrix);
    }
    vector<pair<int, double>> sortVec;
    for (int i = 0; i < V; ++i) {
        sortVec.push_back({i, ranks[i]});
    }
    sort(sortVec.begin(), sortVec.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    int srcRank = 0;
    int destRank = 0;
    for (int i = 0; i < V; ++i) {
        if (sortVec[i].first == src) {
            srcRank = i + 1;
        }
        if (sortVec[i].first == dest) {
            destRank = i + 1;
        }
        pageRank.push_back(sortVec[i].first);
    }
    cout << "Starting City is Rank " << srcRank << "." << endl;
    cout << "Destination City is Rank " << destRank << "." << endl;
    cout << "Most Popular City is " << pageRank.front() << "!" << endl;
    return pageRank; //cities sorted from highest rank to lowest rank (most busy to least busy)
}

/**
 * Matrix Operations for PageRank
 */

/**
 * Computes the stochastic matrix of a given matrix in which each column sums to 1.
 * Creates a new copy so adjMatrix is not modified.
 *
 * @param adjMatrix The adjacency matrix of the graph.
 *
 * @return A stochastic matrix.
 */
vector<vector<double>> Graph::stochastic(const vector<vector<int>>& adjMatrix) {
    vector<double> row(V, 0);
    vector<vector<double>> sMatrix(V, row);
    for (int i = 0; i < V; ++i) {
        int colSum = 0;
        for (int j = 0; j < V; ++j) {
            colSum += adjMatrix[j][i];
        }
        for (int k = 0; k < V; ++k) {
            sMatrix[k][i] = (double) adjMatrix[k][i] / colSum;
        }
    }
    return sMatrix;
}

/**
 * Scales and modifies a matrix by a given scalar.
 *
 * @param matrix Matrix to be scaled and modified.
 * @param scalar Amount to scale matrix.
 */
void scaleMatrix(vector<vector<double>>& matrix, double scalar) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] *= scalar;
        }
    }
}

/**
 * Modifies a matrix through matrix addition.
 *
 * @param matrix Matrix to be modified.
 * @param addMatrix Matrix to be added.
 */
void addMatrices(vector<vector<double>>& matrix, const vector<vector<double>>& addMatrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += addMatrix[i][j];
        }
    }
}

/**
 * Multiplies two given matrices.
 * This function will only be used to multiply a matrix with a vector.
 *
 * @param v Vector to be modifed.
 * @param multMatrix Matrix to multiply.
 */
void multiplyMatrices(vector<double>& v, const vector<vector<double>>& multMatrix) {
    int rows = v.size();
    int cols = multMatrix[0].size();
    vector<double> resVector(rows, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            resVector[i] += (v[i] * multMatrix[i][j]);
        }
    }
    v = resVector;
}