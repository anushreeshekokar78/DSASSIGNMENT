#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

// Structure for Disjoint Set (Union-Find)
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    // Initialize Disjoint Set
    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<Edge> result;  // To store MST edges
    int totalWeight = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    for (auto edge : edges) {
        int u = findParent(parent, edge.u);
        int v = findParent(parent, edge.v);

        // If including this edge doesn’t cause a cycle
        if (u != v) {
            result.push_back(edge);
            totalWeight += edge.w;
            unionSets(parent, rank, u, v);
        }
    }

    // Display MST
    for (auto e : result)
        cout << e.u << " -- " << e.v << " == " << e.w << endl;

    cout << "Total weight of MST: " << totalWeight << endl;
    return 0;
}
