/*
https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
*/

#include <iostream>
#include <vector>
#include <stack>
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

    void DFS(int s) {
        vector<bool> visited(V, false);

        stack<int> st;
        visited[s] = true;
        st.push(s);

        while(!st.empty()) {
            int cur = st.top();
            cout << cur << " ";
            st.pop();

            for(auto i = adj[cur].begin(); i != adj[cur].end(); i++) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    st.push(*i);
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
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}