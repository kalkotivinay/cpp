/*
https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
*/

#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph {
    private:
    int V; // number of vertices
    list<int> *adj;

    public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);

        queue<int> q;
        visited[s] = true;
        q.push(s);

        while(!q.empty()) {
            int cur = q.front();
            cout << cur << " ";
            q.pop();

            for(auto i = adj[cur].begin(); i != adj[cur].end(); i++) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }

};

int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}