#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int dest, weight;
};

// Function to implement Dijkstra's Algorithm
void dijkstra(vector<vector<Edge>>& graph, int src, int dest) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX); // Distance from source to each vertex
    dist[src] = 0;

    // Min-heap priority queue (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if already found a better path
        if (d > dist[u]) continue;

        // Traverse all adjacent vertices
        for (auto edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            // If shorter path found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Display result
    if (dist[dest] == INT_MAX)
        cout << "No path exists between " << src << " and " << dest << endl;
    else
        cout << "Shortest distance from " << src << " to " << dest << " is " << dist[dest] << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Remove this line if graph is directed
    }

    int src, dest;
    cout << "Enter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;

    dijkstra(graph, src, dest);

    return 0;
}
