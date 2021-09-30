/*
 * https://www.youtube.com/watch?v=gDNm1m3G4wo&list=PLFj4kIJmwGu3m30HfYDDufr3PZBfyngr0&index=9
 * https://github.com/fit-coder/fitcoderyoutube/blob/master/graph/topological_sort_kahn.cpp
 *
 *      0 ---> 1 --->3
 *       \     |    /
          \    |   /
 *         \   |  /
 *             2 -------> 4
 */



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}


vector<int> topological_sort(vector<int> graph[], int size)
{
    vector<int> result;
    queue<int> q;
    vector<int> indegree(size, 0);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            //cout << "Before " << i << " " << j << " " << graph[i][j] << " --> " << indegree[graph[i][j]] << endl;
            indegree[graph[i][j]]++;
            cout << "After  " << i << " " << j << " " << graph[i][j] << " --> " << indegree[graph[i][j]] << endl;
        }
    }

    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.push_back(v);
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
            indegree[*i]--;
            if (indegree[*i] == 0) {
                q.push(*i);
            }
        }
    }
    return result;
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

int main()
{
    int size = 5;
    vector<int> graph[size];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    printGraph(graph, size);

    vector<int> result = topological_sort(graph, size);
    if (result.size() != size)
       cout << "Topological sort not possible" << endl;
    else
    {
        cout << "Topological sort using Kahn's algorithm: " << endl;
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}