#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;


struct Edge {
    int u, v, w; // source, destination, weight
};


int findParent(vector<int> &parent, int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]); // path compression
    return parent[i];
}

// Function to unite two sets
void unionSets(vector<int> &parent, vector<int> &rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V); // adjacency list
    vector<Edge> edges; // list of edges for Kruskal

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
        edges.push_back({u, v, w});
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    // Step 2: Initialize parent and rank for Union-Find
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "\nEdges in Minimum Spanning Tree (MST):\n";
    int totalCost = 0;
    int edgesAdded = 0;

    // Step 3: Kruskal’s Algorithm
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        if (setU != setV) {
            cout << u << " - " << v << "  :  " << w << endl;
            totalCost += w;
            unionSets(parent, rank, setU, setV);
            edgesAdded++;
        }

        if (edgesAdded == V - 1)
            break;
    }

    cout << "Total cost of MST = " << totalCost << endl;
    return 0;
}
