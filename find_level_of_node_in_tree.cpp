/*

https://www.geeksforgeeks.org/level-node-tree-source-node-using-bfs/

*/

#include <bits/stdc++.h>
using namespace std;
 
// function to determine level of each node starting
// from x using BFS

/*

algorithm:
- use visited vector equal to the length of the vector and initialize it to 0.
- use level vector equal to the length of the vector and initialize it to 0.
- pick starting point and set level to 0 and visited to 1.
- push the start to the queue.
- while q is empty:
    - get front of the queue into v
    - pop the first element
    - for each node connected to v:
        - if not visisted:
            - visited[node] = true
            - q.push_back(node)
            - level[node] = level[v] + 1

*/
void printLevels(vector<int> graph[], int V, int x)
{
    vector<bool> visited(V, 0);
    vector<int> level(V, 0);
    queue<int> q;

    visited[x] = true;
    level[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto i = graph[v].begin(); i != graph[v].end(); i++) {
            level[*i] = level[v] + 1;
            visited[*i] = true;
            q.push(*i);
        }
    }

    for (int i = 0; i < V; i++) {
        cout << level[i] << " ";
    }
    cout << endl;
    return;
}

// Driver Code
int main()
{
    // adjacency graph for tree
    int V = 8;
    vector<int> graph[V];
 
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[1].push_back(5);
    graph[2].push_back(5);
    graph[2].push_back(6);
    graph[6].push_back(7);
 
    // call levels function with source as 0
    printLevels(graph, V, 0);
 
    return 0;
}