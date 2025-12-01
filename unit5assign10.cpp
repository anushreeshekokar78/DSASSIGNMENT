#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
using namespace std;


struct Edge {
    int v;      // destination vertex
    int weight; // edge weight
};

// Function to find vertex with minimum distance value
int minDistance(vector<int> &dist, vector<bool> &visited, int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Dijkstra's Algorithm
void dijkstra(vector<vector<Edge>> &adj, int V, int src, int dest) {
    vector<int> dist(V, INT_MAX);  // shortest distance from src
    vector<bool> visited(V, false); // visited vertices

    dist[src] = 0; // distance from source to itself is 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break; // no reachable vertex
        visited[u] = true;

        // Update distance of adjacent vertices
        for (auto edge : adj[u]) {
            int v = edge.v;
            int weight = edge.weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    cout << "\nShortest distance from " << src << " to " << dest << " is: " << dist[dest] << endl;

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX)
            cout << i << "\t" << dist[i] << endl;
        else
            cout << i << "\tINF\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<Edge>> adj(V); // adjacency list

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    int src, dest;
    cout << "Enter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;

    dijkstra(adj, V, src, dest);

    return 0;
}
