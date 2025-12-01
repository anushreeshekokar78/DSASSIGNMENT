#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
using namespace std;


struct Edge {
    int v;      
    int weight; 
};

// Function to find the vertex with minimum key value
int minKey(vector<int> &key, vector<bool> &mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Prim’s Algorithm
void primMST(vector<vector<Edge>> &adj, int V) {
    vector<int> parent(V, -1); // store MST structure
    vector<int> key(V, INT_MAX); // store edge weights
    vector<bool> mstSet(V, false); // vertices included in MST

    key[0] = 0; // start from vertex 0

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        // Update adjacent vertices
        for (auto edge : adj[u]) {
            int v = edge.v;
            int weight = edge.weight;
            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "\nEdges in Minimum Spanning Tree (MST):\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "  :  " << key[i] << endl;
        totalCost += key[i];
    }
    cout << "Total cost of MST = " << totalCost << endl;
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

    primMST(adj, V);

    return 0;
}
