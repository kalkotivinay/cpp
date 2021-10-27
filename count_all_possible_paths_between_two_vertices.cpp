/*
https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
*/

#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    private:
    int V;
    // vector<int> *adj;
     list<int> * adj;
    public:
    Graph(int v) {
        V = v;
        //adj = new vector<int>[v];
        adj = new list<int> [v];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    int countPath1(int src, int dest, int vertices) {
        vector<bool> visited(V, false);
        int count = 0;
        stack<int> st;
        st.push(src);
        visited[src] = true;

        while(!st.empty()) {
            int cur = st.top();
            st.pop();
            cout << cur << " ";
            if (cur == dest) {
                count++;
            }

            for(auto i = adj[cur].begin(); i != adj[cur].end(); i++) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    st.push(*i);
                }
            }

        }
        return count;
    }

    void printGraph() {
        for (int v = 0; v < V; ++v)
        {
            cout << "\n Adjacency list of vertex "
                << v << "\n head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            cout << endl;
        }
    }
    int countPath(int src, int dst, int vertices)
    {
        int path_count = 0;
        vector<bool>visited(vertices,false);
        path_counter(src, dst, path_count, visited);
        return path_count;
    }
 
    /*
    * A recursive function that counts all paths from src to
    * dst. Keep track of the count in the parameter.
    */
    void path_counter(int src, int dst, int& path_count, vector<bool> visited)
    {
        // If we've reached the destination, then increment
        // count...
        visited[src]=true;
        if (src == dst) {
            path_count++;
        }
        else {
            for (auto neighbour : adj[src]) {
                // cout << neighbour << " ";
                if(!visited[neighbour])
                    path_counter(neighbour, dst, path_count, visited);
            }
        }
    }
};

// Tests...
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    // Validate it...
    // g.printGraph();

    cout<<g.countPath(0, 4, 5);
 
    return 0;
}
