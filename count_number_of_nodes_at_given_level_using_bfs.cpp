
/*
https://www.geeksforgeeks.org/count-number-nodes-given-level-using-bfs/
*/

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
    private:
    int V;
    list<int> *adj;

    public:
    Graph(int v) {
        V = v;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int bfs(int s, int l) {
        vector<bool> visited(V, false);
        vector<int> level(V, 0);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        level[s] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for(auto i = adj[cur].begin(); i != adj[cur].end(); i++) {
                if (!visited[*i]) {
                    level[*i] = level[cur] + 1;
                    visited[*i] = true;
                    q.push(*i);
                }
            }

        }


        int count = 0;
        for(int i = 0; i < V; i++) {
            if (level[i] == l)
                count++;
        }
        return count;

    }


};

int main()
{
    // Create a graph given
    // in the above diagram
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
 
    int level = 2;
 
    cout << g.bfs(0, level);
 
    return 0;
}