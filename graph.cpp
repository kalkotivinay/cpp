/*
 * https://www.geeksforgeeks.org/graph-and-its-representations/
 *
 * A graph is a data structure that consists of the following two components: 
 * 1. A finite set of vertices also called as nodes. 
 * 2. A finite set of ordered pair of the form (u, v) called as edge. 
 *
 * Commonly used representations of a graph. 
 * 1. Adjacency Matrix
 *      Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph.
 * 2. Adjacency List 
 *      An array of lists is used. The size of the array is equal to the number of vertices.
 */


// we use dynamic arrays (vector in C++) to represent adjacency lists instead of the linked list.

// A simple representation of graph using STL
#include<bits/stdc++.h>
using namespace std;

void
addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void
printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

// Driver code
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}