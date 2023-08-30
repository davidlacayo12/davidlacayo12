#include <iostream>
#include <cstring>
#include "Graph.h"
#include "Utils.h"
using namespace std;
void addEdge(int u, int v, int w, int **matrix, bool bidir = true)
{
    matrix[u][v] = w;
    if (bidir)
    {
        matrix[v][u] = w;
    }
}
// Clean_cs225_dataset_start,end,l2distance.txt
int data225()
{
    freopen("data_10k.txt", "r", stdin);
    freopen("matrix_10k.txt", "w", stdout);

    int V, E; // v is # of vertices and e is # of edges

    cin >> V >> E;

    int **mat = new int *[V];
    for (int i = 0; i < V; i++)
    {
        mat[i] = new int[V];
        memset(mat[i], 0, V * sizeof(int));
    }

    int u, v;
    int w; // getting edges from user
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w, mat);
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}