#include <iostream>
#include <vector>
#include <queue>
#include <limits>   // for numeric_limits
using namespace std;

typedef pair<int,int> Edge; // (weight, vertex)
const int INF = numeric_limits<int>::max();

// Prim's algorithm using adjacency list
void prims(int V, const vector<vector<Edge>>& adj, int start) {
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    // min-heap: (key, vertex)
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        // relax adjacent edges
        for (const Edge &e : adj[u]) {
            int weight = e.first;
            int v = e.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Check if all vertices are included (graph connected)
    for (int i = 0; i < V; ++i) {
        if (!inMST[i]) {
            cout << "Graph is disconnected: MST does not include vertex " << i << ".\n";
            // We continue printing the partial MST for connected component containing 'start'.
        }
    }

    // Print MST edges and total cost (only for vertices that have a parent)
    long long totalCost = 0;
    cout << "\nEdges in Minimum Spanning Tree (parent -> vertex : weight):\n";
    bool anyEdge = false;
    for (int v = 0; v < V; ++v) {
        if (parent[v] != -1) {
            cout << parent[v] << " -> " << v << " : " << key[v] << '\n';
            totalCost += key[v];
            anyEdge = true;
        }
    }
    if (!anyEdge) cout << "(No edges in MST — graph may have a single vertex or be disconnected)\n";
    cout << "Total cost of MST = " << totalCost << '\n';
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    if (!(cin >> V) || V <= 0) {
        cout << "Invalid number of vertices.\n";
        return 0;
    }
    cout << "Enter number of edges: ";
    if (!(cin >> E) || E < 0) {
        cout << "Invalid number of edges.\n";
        return 0;
    }

    vector<vector<Edge>> adj(V);

    cout << "Enter edges (u v weight) with 0 <= u,v < " << V << ":\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid edge endpoints: " << u << " " << v << ". Skipping this edge.\n";
            continue;
        }
        // undirected graph
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int start;
    cout << "Enter starting vertex (0 to " << V-1 << "): ";
    cin >> start;
    if (start < 0 || start >= V) {
        cout << "Invalid start vertex. Using 0 instead.\n";
        start = 0;
    }

    prims(V, adj, start);
    return 0;
}
