#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function for DFS traversal
void DFSUtil(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u])
            DFSUtil(u, adj, visited);
    }
}

// Function for BFS traversal
void BFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from vertex " << start << ": ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    int start;
    cout << "Enter starting vertex for traversal: ";
    cin >> start;

    cout << "\nDFS Traversal starting from vertex " << start << ": ";
    vector<bool> visited(V, false);
    DFSUtil(start, adj, visited);

    cout << endl;
    BFS(start, adj, V);

    return 0;
}
