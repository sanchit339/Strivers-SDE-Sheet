#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u])
                DFSUtil(u, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(3, 1);
    g.addEdge(4, 2);

    cout << "DFS starting from node 1: ";
    g.DFS(0);
    cout << endl;

    cout << "DFS starting from node 2: ";
    g.DFS(1);
    cout << endl;

    cout << "DFS starting from node 3: ";
    g.DFS(2);
    cout << endl;

    cout << "DFS starting from node 4: ";
    g.DFS(3);
    cout << endl;

    cout << "DFS starting from node 5: ";
    g.DFS(4);
    cout << endl;

    return 0;
}
