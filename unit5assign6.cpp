#include <iostream>
using namespace std;

#define MAX 20   // maximum number of vertices


struct Edge {
    int u, v, w;
};


int findParent(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void unionSets(int parent[], int u, int v) {
    int a = findParent(parent, u);
    int b = findParent(parent, v);
    parent[a] = b;
}

int main() {
    int V;  // number of vertices
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Create edge list from adjacency matrix
    Edge edges[MAX * MAX];
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {  // upper triangle (undirected graph)
            if (graph[i][j] != 0) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "\nEdges in Minimum Spanning Tree (MST):\n";
    int totalCost = 0;
    int edgeAdded = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        if (setU != setV) {  // if they belong to different sets
            cout << u << " - " << v << " : " << w << endl;
            totalCost += w;
            unionSets(parent, setU, setV);
            edgeAdded++;
        }

        if (edgeAdded == V - 1)
            break;
    }

    cout << "Total cost of MST = " << totalCost << endl;
    return 0;
}
